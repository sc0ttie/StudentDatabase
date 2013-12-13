#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "database.hpp"
#include "student.hpp"

using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::sort;
using std::string;
using std::vector;

void Database::Add(Student s) {
	students_.push_back(s);

	sort(students_.begin(), students_.end());
}

void Database::Add(vector<Student> vs) {
	students_.insert(students_.end(), vs.begin(), vs.end());

	sort(students_.begin(), students_.end());
}

vector<Student> Database::Search(const string& name) const {
	vector<Student> res;

	for (auto s : students_) {
		if (s.Name() == name) {
			res.push_back(Student(s));
		}
	}

	return res;
}

size_t Database::Size() const {
	return students_.size();
}

void Database::Clear() {
	students_.clear();
}

ostream& operator<< (ostream& os, const Database& db) {
	if (&os != &cout) {
		os << db.students_.size() << endl;
	}

	for (auto s : db.students_) {
		os << s << endl;
	}

	return os;
}

istream& operator>> (istream& is, Database& db) {
	size_t size;
	Student s;
	vector<Student> tmp;

	is >> size;
	for (size_t i = 0; i < size; ++i) {
		is >> s;

		tmp.push_back(s);
	}

	db.Clear();
	db.Add(tmp);

	return is;
}

