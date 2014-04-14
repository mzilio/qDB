#ifndef BENEIMMOBILE_H
#define BENEIMMOBILE_H

class BeneImmobile {
private:
	double RenditaCatastale;
public:
	static double AliquotaStandard;
	BeneImmobile(double);
	virtual ~BeneImmobile();
	double getRenditaCatastale() const;
	virtual double calcoloImu() const =0;
};
#endif