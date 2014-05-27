#include "identificativocatastale.h"

IdentificativoCatastale::IdentificativoCatastale(string c, int f, int p) throw(Error): Comune(c) {
	if (f<0)
		throw Error("Il numero del foglio deve essere positivo!");
	else
		Foglio=f;
	if (p<0)
		throw Error("Il numero della particella deve essere positivo!");
	else
		Particella=p;
}

bool IdentificativoCatastale::operator==(const IdentificativoCatastale& i) const {
    return Comune==i.Comune & Foglio==i.Foglio & Particella==i.Particella;
}

bool IdentificativoCatastale::operator!=(const IdentificativoCatastale& i) const {
    return Comune!=i.Comune | Foglio!=i.Foglio | Particella!=i.Particella;
}

bool IdentificativoCatastale::operator<(const IdentificativoCatastale& i) const {
    return Comune<i.Comune & Foglio<i.Foglio & Particella<i.Particella;
}

string IdentificativoCatastale::getComune() const {
	return Comune;
}

int IdentificativoCatastale::getFoglio() const {
	return Foglio;
}

int IdentificativoCatastale::getParticella() const {
	return Particella;
}
