#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <fstream>
#include <iostream>
#include <vector>

#include "student.hpp"

using std::istream;
using std::ostream;
using std::vector;

class Database {
public:
	void Add(Student s);
	void Add(vector<Student> vs);
	vector<Student> Search(const string& name) const;
	size_t Size() const;
	void Clear();

	friend ostream& operator<< (ostream& os, const Database& db);
	friend istream& operator>> (istream& os, Database& db);

private:
	vector<Student> students_;
};

#endif
