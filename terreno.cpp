#include "terreno.h"

double Terreno::Rivalutazione = 25.0;

double Terreno::Moltiplicatore = 135.0;

Terreno::Terreno(string c, int f, int pa, string pr, double r): BeneImmobile(c,f,pa,pr,r) {}

Terreno::Terreno(IdentificativoCatastale i, string pr, double r): BeneImmobile(i,pr,r) {}

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
