#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <fstream>
#include <iostream>
#include <vector>

#include "student.hpp"

class Database {
public:
	void Add(Student s);
	void Add(std::vector<Student> vs);
	std::vector<Student> Search(const std::string& name) const;
	size_t Size() const;
	void Clear();

	friend std::ostream& operator<< (std::ostream& os, const Database& db);
	friend std::istream& operator>> (std::istream& os, Database& db);

private:
	std::vector<Student> students_;
};

#endif
