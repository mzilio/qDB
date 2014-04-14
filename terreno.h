#ifndef TERRENO_H
#define TERRENO_H

class Terreno : public BeneImmobile {
public:
	static double Rivalutazione;
	static double Moltiplicatore;
	Terreno(double);
	double calcoloImu() const;
};
#endif