#include "terreno.h"

double Terreno::Rivalutazione = 25.0;

double Terreno::Moltiplicatore = 135.0;

Terreno::Terreno(string p, double r): BeneImmobile(p,r) {}

Terreno* Terreno::clone() const {
	return new Terreno(*this);
}

double Terreno::calcoloImu() const {
	double Rendita=getRenditaCatastale();
	double Incremento=(Rendita*Rivalutazione)/100.0;
	Rendita+=Incremento;
	Rendita*=Moltiplicatore;
	return (Rendita*AliquotaStandard)/100.0;
}