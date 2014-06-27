#ifndef ERROR_H
#define ERROR_H
#include <string>
using std::string;

class Error {
private:
	string errorString;
public:
	Error(string);
	string getError() const;
};

#endif