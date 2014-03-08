#ifndef DATE_H
#define DATE_H
#include <iostream>
using std::ostream;

class Date {
	friend ostream& operator<<(ostream&, const Date&);
private:
	int day, month, year;
public:
	Date(int, int, int);
	int Day() const;
	int Month() const;
	int Year() const;
};

ostream& operator<<(ostream&, const Date&);
#endif