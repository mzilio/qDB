#ifndef FABBRICATO_H
#define FABBRICATO_H
#include "beneimmobile.h"
#include "error.h"
#include <string>
using std::string;

class Fabbricato : public BeneImmobile {
private:
    string CategoriaCatastale;
	bool PrimaCasa, Storico, Inagibile;
public:
	static double AliquotaAgevolata;
	static double Rivalutazione;
	static double MoltiplicatoreAX;
	static double MoltiplicatoreBX;
	static double MoltiplicatoreA10D5;
	static double MoltiplicatoreDX;
	static double MoltiplicatoreC1;
	Fabbricato(string, double, string, bool=false, bool=false, bool=false);
	bool operator==(const BeneImmobile&) const;
	bool operator<(const BeneImmobile&) const;
	Fabbricato* clone() const;
	bool isPrimaCasa() const;
	bool isStorico() const;
	bool isInagibile() const;
	string getCategoriaCatastale() const;
	double calcoloImu() const throw(Error);
};
#endif
