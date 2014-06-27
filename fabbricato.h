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
	Fabbricato(string, int, int, string, double, string, bool=false, bool=false, bool=false);
	Fabbricato* clone() const;
	bool isPrimaCasa() const;
	void setPrimaCasa(bool);
	bool isStorico() const;
	void setStorico(bool);
	bool isInagibile() const;
	void setInagibile(bool);
	string getCategoriaCatastale() const;
	void setCategoriaCatastale(string);
	double calcoloImu() const throw(Error);
};

#endif