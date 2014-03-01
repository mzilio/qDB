#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
using std::ostream;

template <class K> class Item;

template <class K> class Container;

template <class K> ostream& operator<<(ostream&, Item<K>*);

template <class K> ostream& operator<<(ostream&, const Container<K>&);

template <class K>
class Item {
	friend class Container<K>;
	friend ostream& operator<< <K>(ostream&, Item<K>*);
private:
	K info;
	Item *sx, *dx, *pred;
	Item(const K& =0, Item* =0, Item* =0, Item* =0);
};

template <class K>
class Container {
	friend ostream& operator<< <K>(ostream&, const Container<K>&);
private:
	Item<K>* radice;
	static Item<K>* Minimum(Item<K>*);
	static Item<K>* Maximum(Item<K>*);
	static Item<K>* Successor(Item<K>*);
public:
	Container();
	Item<K>* Minimum() const;
	Item<K>* Maximum() const;
	void AddItem(const K&);
	Item<K>* FindItem(const K&) const;
	Item<K>* DeleteItem(const K&);
};

template <class K>
Item<K>::Item(const K& x, Item* s, Item* d, Item* p): info(x), sx(s), dx(d), pred(p) {}

template <class K>
Container<K>::Container(): radice(0) {}

template <class K>
Item<K>* Container<K>::Minimum(Item<K>* x) {
	while (x->sx) x=x->sx;
	return x;
}

template <class K>
Item<K>* Container<K>::Maximum(Item<K>* x) {
	while (x->dx) x=x->dx;
	return x;
}

template <class K>
Item<K>* Container<K>::Successor(Item<K>* x) {
	if (x->dx) return Minimum(x->dx);
	Item<K>* y = x->pred;
	while (y && x==y->dx) {
		x=y;
		y=y->pred;
	}
	return y;
}

template <class K>
Item<K>* Container<K>::Minimum() const {
	return Minimum(radice);
}

template <class K>
Item<K>* Container<K>::Maximum() const {
	return Maximum(radice);
}

template <class K>
void Container<K>::AddItem(const K& obj) {
	Item<K> *it=radice, *p=0;
	while (it) {
		p=it;
		if (obj < it->info) it=it->sx;
		else it=it->dx;
	}
	Item<K> *newItem = new Item<K>(obj,0,0,p);
	if (!p) radice=newItem;
	else {
		if (obj < p->info) p->sx=newItem;
		else p->dx=newItem;
	}
}

template <class K>
Item<K>* Container<K>::FindItem(const K& obj) const {
	Item<K>* it=radice;
	while (!it && obj!=it->info) {
		if (obj < it->info) it = it->sx;
		else it = it->dx;
	}
	return it;
}

// ***********************************
//            DA VEDERE!!!
// ***********************************
template <class K>
Item<K>* Container<K>::DeleteItem(const K& obj) {
	Item<K>* x, *y;
	Item<K>* del=FindItem(obj);
	if (!del->sx || !del->dx) y=del;
	else y=Successor(del);
	if (y->sx) x=y->sx;
	else x=y->dx;
	if (x) x->pred=y->pred;
	if (!y->pred) radice=x;
	else
		if (y==y->pred->sx) y->pred->sx=x;
		else y->pred->dx=x;
	if (y!=del) del->info=y->info;
	return y;
}

// ***********************************
// HA SENSO LA STAMPA DEL CONTENITORE?
// ***********************************
template <class K>
ostream& operator<<(ostream& os, Item<K>* x) {
	if (!x) os << '@';
	else os << x->info << '(' << x->sx << ',' << x->dx << ')';
	return os;
}

template <class K>
ostream& operator<<(ostream& os, const Container<K>& x) {
	os << x.radice;
	return os;
}
#endif
// rimozione - modifica