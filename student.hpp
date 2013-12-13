#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <fstream>
#include <iostream>
#include <string>

class Student {
public:
	static const size_t NUM_SCORES = 3;

	bool operator== (const std::string& name) const;

	friend bool operator< (const Student& lhs, const Student& rhs);
	friend std::ostream& operator<< (std::ostream& os, const Student& s);
	friend std::istream& operator>> (std::istream& is, Student& s);

private:
	std::string name_;
	char gender_;
	unsigned age_;
	int scores_[NUM_SCORES];
};

#endif
