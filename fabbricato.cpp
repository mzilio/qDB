#include "fabbricato.h"

double Fabbricato::AliquotaAgevolata = 0.4;

double Fabbricato::Rivalutazione = 5.0;

double Fabbricato::MoltiplicatoreAX = 160.0;

double Fabbricato::MoltiplicatoreBX = 140.0;

double Fabbricato::MoltiplicatoreA10D5 = 80.0;

double Fabbricato::MoltiplicatoreDX = 60.0;

double Fabbricato::MoltiplicatoreC1 = 55.0;

Fabbricato::Fabbricato(string co, int f, int pa, string pr, double r, string c, bool pc, bool s, bool i): BeneImmobile(co,f,pa,pr,r), CategoriaCatastale(c) {
	PrimaCasa=Storico=Inagibile=false;
	if (pc)
		PrimaCasa=true;
	else if (s)
		Storico=true;
	else if (i)
		Inagibile=true;
}

Fabbricato* Fabbricato::clone() const {
	return new Fabbricato(*this);
}

bool Fabbricato::isPrimaCasa() const {
	return PrimaCasa;
}

void Fabbricato::setPrimaCasa(bool p) {
	if (p) {
		Storico=Inagibile=false;
	}
	PrimaCasa=p;
}

bool Fabbricato::isStorico() const {
	return Storico;
}

void Fabbricato::setStorico(bool s) {
	if (s) {
		PrimaCasa=Inagibile=false;
	}
	Storico=s;
}

bool Fabbricato::isInagibile() const {
	return Inagibile;
}

void Fabbricato::setInagibile(bool i) {
	if (i) {
		PrimaCasa=Storico=false;
	}
	Inagibile=i;
}

string Fabbricato::getCategoriaCatastale() const{
	return CategoriaCatastale;
}

void Fabbricato::setCategoriaCatastale(string c) {
	CategoriaCatastale=c;
}

double Fabbricato::calcoloImu() const throw(Error) {
	double Rendita=getRenditaCatastale();
	if (Storico || Inagibile)
		Rendita*=0.5;
	double Incremento=(Rendita*Rivalutazione)/100.0;
	Rendita+=Incremento;
	if (CategoriaCatastale=="A1" || CategoriaCatastale=="A2" || CategoriaCatastale=="A3" || CategoriaCatastale=="A4" || CategoriaCatastale=="A5" || CategoriaCatastale=="A7" || CategoriaCatastale=="A8" || CategoriaCatastale=="A9" || CategoriaCatastale=="A11" || CategoriaCatastale=="C2" || CategoriaCatastale=="C6" || CategoriaCatastale=="C7")
		Rendita*=MoltiplicatoreAX;
	else if (CategoriaCatastale=="B1" || CategoriaCatastale=="B2" || CategoriaCatastale=="B3" || CategoriaCatastale=="B4" || CategoriaCatastale=="B5" || CategoriaCatastale=="B6" || CategoriaCatastale=="B7" || CategoriaCatastale=="B8" || CategoriaCatastale=="C3" || CategoriaCatastale=="C4" || CategoriaCatastale=="C5")
		Rendita*=MoltiplicatoreBX;
	else if  (CategoriaCatastale=="A10" || CategoriaCatastale=="D5")
		Rendita*=MoltiplicatoreA10D5;
	else if (CategoriaCatastale=="D1" || CategoriaCatastale=="D2" || CategoriaCatastale=="D3" || CategoriaCatastale=="D4" || CategoriaCatastale=="D6" || CategoriaCatastale=="D7" || CategoriaCatastale=="D8" || CategoriaCatastale=="D9" || CategoriaCatastale=="D10")
		Rendita*=MoltiplicatoreDX;
	else if (CategoriaCatastale=="C1")
		Rendita*=MoltiplicatoreC1;
	else
        throw Error("Classe catastale non riconosciuta!");
	if (PrimaCasa)
		return (Rendita*AliquotaAgevolata)/100.0;
	else
		return (Rendita*AliquotaStandard)/100.0;
}