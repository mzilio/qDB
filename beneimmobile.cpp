#include "beneimmobile.h"

double BeneImmobile::AliquotaStandard = 0.76;

BeneImmobile::BeneImmobile(string c, int f, int pa, string pr, double r): id(c,f,pa), Proprietario(pr), RenditaCatastale(r) {}

BeneImmobile::~BeneImmobile() {}

bool BeneImmobile::operator==(const BeneImmobile& b) const {
	return id==b.id;
	//return id==b.id && Proprietario==b.Proprietario && RenditaCatastale==b.RenditaCatastale;
}

bool BeneImmobile::operator!=(const BeneImmobile& b) const {
	return id!=b.id;
}

bool BeneImmobile::operator<(const BeneImmobile& b) const {
	return id<b.id;
	//return id<b.id && Proprietario<b.Proprietario && RenditaCatastale<b.RenditaCatastale;
}

IdentificativoCatastale BeneImmobile::getIdentificativoCatastale() const {
	return id;
}

string BeneImmobile::getProprietario() const {
	return Proprietario;
}

void BeneImmobile::setProprietario(string p) {
	Proprietario=p;
}

double BeneImmobile::getRenditaCatastale() const {
	return RenditaCatastale;
}

void BeneImmobile::setRenditaCatastale(double r) {
	RenditaCatastale=r;
}