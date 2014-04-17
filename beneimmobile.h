#ifndef BENEIMMOBILE_H
#define BENEIMMOBILE_H
#include <string>
using std::string;

class BeneImmobile {
private:
	string Proprietario;
	double RenditaCatastale;
public:
	static double AliquotaStandard;
	BeneImmobile(string, double);
	virtual ~BeneImmobile();
	virtual bool operator==(const BeneImmobile&) const;
	virtual bool operator<(const BeneImmobile&) const;
	virtual BeneImmobile* clone() const =0;
	string getProprietario() const;
	double getRenditaCatastale() const;
	virtual double calcoloImu() const =0;
};
#endif