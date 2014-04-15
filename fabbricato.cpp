#include "fabbricato.h"

double Fabbricato::AliquotaAgevolata = 0.4;

double Fabbricato::Rivalutazione = 5.0;

double Fabbricato::MoltiplicatoreAX = 160.0;

double Fabbricato::MoltiplicatoreBX = 140.0;

double Fabbricato::MoltiplicatoreA10D5 = 80.0;

double Fabbricato::MoltiplicatoreDX = 60.0;

double Fabbricato::MoltiplicatoreC1 = 55.0;

Fabbricato::Fabbricato(string p, double r, string c, bool pc, bool s, bool i): BeneImmobile(p,r), CategoriaCatastale(c), PrimaCasa(pc), Storico(s), Inagibile(i) {}

bool Fabbricato::isPrimaCasa() const {
	return PrimaCasa;
}

bool Fabbricato::isStorico() const {
	return Storico;
}

bool Fabbricato::isInagibile() const {
	return Inagibile;
}

string Fabbricato::getCategoriaCatastale() const{
	return CategoriaCatastale;
}

double Fabbricato::calcoloImu() const throw(Error) {
	double Rendita=getRenditaCatastale();
	if (Storico || Inagibile)
		Rendita*=0.5;
	double Incremento=(Rendita*Rivalutazione)/100.0;
	Rendita+=Incremento;
	if (true)
		Rendita*=MoltiplicatoreAX;
	/*if (CategoriaCatastale)
		Rendita*=MoltiplicatoreAX;
	else if
		Rendita*=MoltiplicatoreBX;
	else if
		Rendita*=MoltiplicatoreA10D5;
	else if
		Rendita*=MoltiplicatoreDX;
	else if
		Rendita*=MoltiplicatoreC1;
	else
		throw Error("Categoria catastale non riconosciuta!");*/
	if (PrimaCasa)
		return (Rendita*AliquotaAgevolata)/100.0;
	else
		return (Rendita*AliquotaStandard)/100.0;
}

/*
	TODO capire come riconoscere le diverse categorie catastali
*/