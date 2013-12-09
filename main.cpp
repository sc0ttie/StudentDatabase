#include <iostream>
#include <fstream>
#include <vector>

#include "database.hpp"
#include "student.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istream;

enum class TMenuOpt { ADD = 1, SHOWALL, SEARCH, OUTPUT_TO_FILE, INPUT_FROM_FILE, EXIT };

istream& operator>>(istream& is, TMenuOpt& o) {
	int tmp;

	if (is >> tmp) {
		o = static_cast<TMenuOpt>(tmp);
	}

	return is;
}

int main() {
	Database db;
	TMenuOpt opt;

	do {
		#ifdef _WIN32
		system("cls");
		#else
		system("clear");
		#endif

		cout << "A simple database program" << endl << endl
			 << "(1) Add a record" << endl
			 << "(2) Show all records" << endl
			 << "(3) Search student(s) by name" << endl
			 << "(4) Output records to a text file" << endl
			 << "(5) Input records from a text file" << endl
			 << "(6) Exit the program" << endl << endl
			 << "Please select a function...> ";
		cin >> opt;
		cout << endl;

		switch (opt) {
		case TMenuOpt::ADD: {
			#ifdef _WIN32
			system("cls");
			#else
			system("clear");
			#endif

			cout << "Please input the required values:" << endl << endl;

			Student s;

			cin >> s;

			db.Add(s);

			break;
		} case TMenuOpt::SHOWALL: {
			if (db.Size() == 0) {
				cout << "There is no record in the database." << endl;
			} else {
				cout << "There are " << db.Size() << " records:" << endl << endl << db;
			}

			break;
		} case TMenuOpt::SEARCH: {
			string name;

			cout << "Please input the name of the student...> ";
			cin >> name;

			vector<Student> res = db.Search(name);

			if (res.size() == 0) {
				cout << endl << "There is no \"" << name << "\" exists." << endl;
			} else {
				cout << endl << "There is/are " << res.size() << " \"" << name << "\":" << endl << endl;
				for (size_t i = 0; i < res.size(); ++i) {
					cout << res[i] << endl;
				}
			}

			break;
		} case TMenuOpt::OUTPUT_TO_FILE: {
			char y_or_n;

			cout << "Out all records to a text file." << endl << endl
				 << "Note that the original data in the file will be lost after writing to the file. Are you sure that you want to continue? (Y/N)...> ";
			cin >> y_or_n;

			if (y_or_n == 'y' || y_or_n == 'Y') {
				string fname;
				cout << endl << "Please input the name of the file...> ";
				cin >> fname;

				ofstream fout(fname);
				if (fout.is_open()) {
					fout << db;
					fout.close();
				} else {
					cout << endl << "Cannot open " << fname << endl;
				}
			}

			break;
		} case TMenuOpt::INPUT_FROM_FILE: {
			char y_or_n;

			cout << "Read in records from a text file." << endl << endl
				 << "Note that current data in the program will be lost after reading. Are you sure that you want to continue? (Y/N)...> ";
			cin >> y_or_n;

			if (y_or_n == 'y' || y_or_n == 'Y') {
				string fname;
				cout << endl << "Please input the name of the file...> ";
				cin >> fname;

				ifstream fin(fname);

				if (fin.is_open()) {
					fin >> db;
					fin.close();
				} else {
					cout << endl << "Cannot open " << fname << endl;
				}
			}
			break;
		} case TMenuOpt::EXIT: {
			cout << "Program exits successful." << endl;
			break;
		} default:
			cout << "Invalid option " << static_cast<int>(opt) << endl;
		}

		cout << endl;
		#ifdef _WIN32
		system("pause");
		#else
		cout << "Press enter to continue." << endl;
		cin.ignore();
		cin.get();
		#endif
	} while (opt != TMenuOpt::EXIT);

	return 0;
}

