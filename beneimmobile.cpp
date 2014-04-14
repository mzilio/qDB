#include "beneimmobile.h"

double BeneImmobile::AliquotaStandard = 0.76;

BeneImmobile::BeneImmobile(double r): RenditaCatastale(r) {}

BeneImmobile::~BeneImmobile() {}

double BeneImmobile::getRenditaCatastale() const {
	return RenditaCatastale;
}