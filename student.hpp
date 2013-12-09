#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <fstream>
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Student {
public:
	static const size_t NUM_SCORES = 3;

	bool operator== (const string& name) const;

	friend bool operator< (const Student& lhs, const Student& rhs);
	friend ostream& operator<< (ostream& os, const Student& s);
	friend istream& operator>> (istream& is, Student& s);

private:
	string name_;
	char gender_;
	unsigned age_;
	int scores_[NUM_SCORES];
};

#endif
