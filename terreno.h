#ifndef TERRENO_H
#define TERRENO_H
#include "beneimmobile.h"

class Terreno : public BeneImmobile {
public:
	static double Rivalutazione;
	static double Moltiplicatore;
	Terreno(string, int, int, string, double);
    Terreno(IdentificativoCatastale, string =0, double =0);
	Terreno* clone() const;
	double calcoloImu() const;
};
#endif
