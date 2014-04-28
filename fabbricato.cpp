#include "fabbricato.h"

double Fabbricato::AliquotaAgevolata = 0.4;

double Fabbricato::Rivalutazione = 5.0;

double Fabbricato::MoltiplicatoreAX = 160.0;

double Fabbricato::MoltiplicatoreBX = 140.0;

double Fabbricato::MoltiplicatoreA10D5 = 80.0;

double Fabbricato::MoltiplicatoreDX = 60.0;

double Fabbricato::MoltiplicatoreC1 = 55.0;

Fabbricato::Fabbricato(string co, int f, int pa, string pr, double r, string c, bool pc, bool s, bool i): BeneImmobile(co,f,pa,pr,r), CategoriaCatastale(c), PrimaCasa(pc), Storico(s), Inagibile(i) {}

/*bool Fabbricato::operator==(const BeneImmobile& b) const {
	const Fabbricato* f=dynamic_cast<const Fabbricato*>(&b);
	return f && BeneImmobile::operator==(*f);
	//return f && BeneImmobile::operator==(*f) && CategoriaCatastale==f->CategoriaCatastale;
}

bool Fabbricato::operator<(const BeneImmobile& b) const {
	const Fabbricato* f=dynamic_cast<const Fabbricato*>(&b);
	return f && BeneImmobile::operator<(*f);
	//return f && BeneImmobile::operator<(*f) && CategoriaCatastale<f->CategoriaCatastale;
}*/

Fabbricato* Fabbricato::clone() const {
	return new Fabbricato(*this);
}

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
		throw Error("Categoria catastale non riconosciuta!");
	if (PrimaCasa)
		return (Rendita*AliquotaAgevolata)/100.0;
	else
		return (Rendita*AliquotaStandard)/100.0;
}
/*
	TODO capire come fare controllo di coerenza su categoria catastale all'interno del costruttore
*/