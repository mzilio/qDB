#ifndef IDENTIFICATIVOCATASTALE_H
#define IDENTIFICATIVOCATASTALE_H
#include "error.h"
#include <string>
using std::string;

class IdentificativoCatastale {
private:
	string Comune;
	int Foglio, Particella;
public:
	IdentificativoCatastale(string, int, int) throw(Error);
	bool operator==(const IdentificativoCatastale&) const;
	bool operator!=(const IdentificativoCatastale&) const;
	bool operator<(const IdentificativoCatastale&) const;
	string getComune() const;
	int getFoglio() const;
	int getParticella() const;
};
#endif