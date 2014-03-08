#include "date.h"

Date::Date(int g, int m, int a) {
	if (a>0) {
		if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
			if (0<g<32) {
				day=g;
				month=m;
				year=a;
			}
		}
		if (m==4 || m==6 || m==9 || m==10) {
			if (0<g<31) {
				day=g;
				month=m;
				year=a;
			}
		}
		if (m==2) {
			if (0<g<30) {
				day=g;
				month=m;
				year=a;
			}
		}
	}
}

int Date::Day() const {
	return day;
}

int Date::Month() const {
	return month;
}

int Date::Year() const {
	return year;
}

ostream& operator<<(ostream& os, const Date& x) {
	os << x.day << '/' << x.month << '/' << x.year;
	return os;
}