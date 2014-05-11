#ifndef TERRENO_H
#define TERRENO_H
#include "beneimmobile.h"

class Terreno : public BeneImmobile {
public:
	static double Rivalutazione;
	static double Moltiplicatore;
	Terreno(string, int, int, string, double);
	Terreno* clone() const;
	double calcoloImu() const;
};
#endif
