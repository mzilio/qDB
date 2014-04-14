#include "error.h"

Error::Error(string s): errorString(s) {}

string Error::getError() const {
	return errorString;
}