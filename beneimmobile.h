#ifndef BENEIMMOBILE_H
#define BENEIMMOBILE_H
#include "identificativocatastale.h"
#include <string>
using std::string;

class BeneImmobile {
private:
	IdentificativoCatastale id;
	string Proprietario;
	double RenditaCatastale;
public:
	static double AliquotaStandard;
	BeneImmobile(string, int, int, string, double);
    BeneImmobile(IdentificativoCatastale, string =0, double =0);
	virtual ~BeneImmobile();
	virtual bool operator==(const BeneImmobile&) const;
	virtual bool operator!=(const BeneImmobile&) const;
	virtual bool operator<(const BeneImmobile&) const;
	virtual BeneImmobile* clone() const =0;
	IdentificativoCatastale getIdentificativoCatastale() const;
	string getProprietario() const;
	void setProprietario(string);
	double getRenditaCatastale() const;
	void setRenditaCatastale(double);
	virtual double calcoloImu() const =0;
};
#endif
