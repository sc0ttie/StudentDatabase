#include <fstream>
#include <iostream>

#include "student.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

bool Student::operator== (const string& name) const {
	return name_ == name;
}

bool operator< (const Student& lhs, const Student& rhs) {
	return lhs.name_ < rhs.name_;
}

ostream& operator<< (ostream& os, const Student& s) {
	os << s.name_ << " " << s.gender_ << " ";

	if (&os == &cout) {
		os << "(" << s.age_ << ")";
	} else {
		os << s.age_;
	}

	for (size_t i = 0; i < Student::NUM_SCORES; ++i) {
		os << " " << s.scores_[i];
	}

	return os;
}

istream& operator>> (istream& is, Student& s) {
	if (&is == &cin) {
		cout << "Name: ";
		is >> s.name_;
		cout << "Gender (M/F): ";
		is >> s.gender_;
		cout << "Age: ";
		is >> s.age_;
		cout << Student::NUM_SCORES << " Scores: ";
	} else {
		is >> s.name_ >> s.gender_ >> s.age_;
	}

	for (size_t i = 0; i < Student::NUM_SCORES; ++i) {
		is >> s.scores_[i];
	}

	return is;
}
