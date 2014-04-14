#ifndef FABBRICATO_H
#define FABBRICATO_H
#include <string>
using std::string;

class Fabbricato : public BeneImmobile {
private:
	bool PrimaCasa, Storico, Inagibile;
	string CategoriaCatastale;
public:
	static double AliquotaAgevolata;
	static double Rivalutazione;
	static double MoltiplicatoreAX;
	static double MoltiplicatoreBX;
	static double MoltiplicatoreA10D5;
	static double MoltiplicatoreDX;
	static double MoltiplicatoreC1;
	Fabbricato(double, string, bool, bool, bool);
	double calcoloImu() const;
};
#endif