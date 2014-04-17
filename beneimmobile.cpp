#include "beneimmobile.h"

double BeneImmobile::AliquotaStandard = 0.76;

BeneImmobile::BeneImmobile(string p, double r): Proprietario(p), RenditaCatastale(r) {}

BeneImmobile::~BeneImmobile() {}

bool BeneImmobile::operator==(const BeneImmobile& b) const {
	return Proprietario==b.Proprietario && RenditaCatastale==b.RenditaCatastale;
}

bool BeneImmobile::operator<(const BeneImmobile& b) const {
	return Proprietario<b.Proprietario && RenditaCatastale<b.RenditaCatastale;
}

string BeneImmobile::getProprietario() const {
	return Proprietario;
}

double BeneImmobile::getRenditaCatastale() const {
	return RenditaCatastale;
}