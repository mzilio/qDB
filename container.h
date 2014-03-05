#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
using std::ostream;

template <class K> class Container;

template <class K> ostream& operator<<(ostream&, const Container<K>&);

template <class K>
class Container {
	friend class Iterator;
	friend ostream& operator<< <K>(ostream&, const Container<K>&);
private:
	class Item {
	public:
		K info;
		Item *sx, *dx, *pred;
		Item(const K& =0, Item* =0, Item* =0, Item* =0);
		~Item();
	};
	Item* radice;
	static Item* copy(Item*, Item* =0);
	static void destroy(Item*);
	static Item* Minimum(Item*);
	static Item* Maximum(Item*);
public:
	class Iterator {
		friend class Container;
		friend ostream& operator<< <K>(ostream&, const Container<K>&);
	private:
		Item* it;
	public:
		Iterator& operator++();
	};
	Container();
	Container(const Container<K>&);
	~Container();
	Container<K>& operator=(const Container<K>&);
	Item* Minimum() const;
	Item* Maximum() const;
	static Item* Successor(Item*);
	static Item* Predecessor(Item*);
	void AddItem(const K&);
	Item* FindItem(const K&) const;
	Item* RemoveItem(const K&);
};

template <class K>
Container<K>::Item::Item(const K& x, Item* s, Item* d, Item* p): info(x), sx(s), dx(d), pred(p) {}

template <class K>
Container<K>::Item::~Item() {
	if (sx) delete sx;
	if (dx) delete dx;
}

template <class K>
typename Container<K>::Item* Container<K>::copy(typename Container<K>::Item* x, typename Container<K>::Item* p) {
	if (!x) return 0;
	else {
		typename Container<K>::Item* q=new typename Container<K>::Item(x->info,0,0,p);
		q->sx=copy(x->sx,q);
		q->dx=copy(x->dx,q);
		return q;
	}
}

template <class K>
void Container<K>::destroy(Container<K>::Item* x) {
	if (x) {
		destroy(x->sx);
		destroy(x->dx);
		delete x;
	}
}

template <class K>
typename Container<K>::Item* Container<K>::Minimum(typename Container<K>::Item* x) {
	while (x->sx) x=x->sx;
	return x;
}

template <class K>
typename Container<K>::Item* Container<K>::Maximum(typename Container<K>::Item* x) {
	while (x->dx) x=x->dx;
	return x;
}

template <class K>
typename Container<K>::Iterator& Container<K>::Iterator::operator++() {
	if (it) it=Successor(it);
	return *this;
}

template <class K>
Container<K>::Container(): radice(0) {}

template <class K>
Container<K>::Container(const Container<K>& x): radice(copy(x.radice)) {}

template <class K>
Container<K>::~Container() {
	if (radice) delete radice;
}

template <class K>
Container<K>& Container<K>::operator=(const Container<K>& x) {
	if (this!=&x) {
		destroy(radice);
		radice=copy(x.radice);
	}
	return *this;
}

template <class K>
typename Container<K>::Item* Container<K>::Minimum() const {
	return Minimum(radice);
}

template <class K>
typename Container<K>::Item* Container<K>::Maximum() const {
	return Maximum(radice);
}

template <class K>
typename Container<K>::Item* Container<K>::Successor(typename Container<K>::Item* x) {
	if (x->dx) return Minimum(x->dx);
	typename Container<K>::Item* y = x->pred;
	while (y && x==y->dx) {
		x=y;
		y=y->pred;
	}
	return y;
}

template <class K>
typename Container<K>::Item* Container<K>::Predecessor(typename Container<K>::Item* x) {
	if (x->sx) return Maximum(x->sx);
	typename Container<K>::Item* y = x->pred;
	while (y && x==y->sx) {
		x=y;
		y=y->pred;
	}
	return y;
}

template <class K>
void Container<K>::AddItem(const K& obj) {
	typename Container<K>::Item *it=radice, *p=0;
	while (it) {
		p=it;
		if (obj < it->info) it=it->sx;
		else it=it->dx;
	}
	typename Container<K>::Item *newItem = new typename Container<K>::Item(obj,0,0,p);
	if (!p) radice=newItem;
	else {
		if (obj < p->info) p->sx=newItem;
		else p->dx=newItem;
	}
}

template <class K>
typename Container<K>::Item* Container<K>::FindItem(const K& obj) const {
	typename Container<K>::Item* it=radice;
	while (it && obj!=it->info) {
		if (obj < it->info) it = it->sx;
		else it = it->dx;
	}
	return it;
}

// ***********************************
//      TIPO DI RITORNO COERENTE?
// ***********************************
template <class K>
typename Container<K>::Item* Container<K>::RemoveItem(const K& obj) {
	typename Container<K>::Item* x, *y;
	typename Container<K>::Item* del=FindItem(obj);
	if (del) {
		if (!del->sx || !del->dx) y=del;
		else y=Successor(del);
		if (y->sx != 0) x=y->sx;
		else x=y->dx;
		if (x) x->pred=y->pred;
		if (!y->pred) radice=x;
		else {
			if (y==(y->pred)->sx) (y->pred)->sx=x;
			else (y->pred)->dx=x;
		}
		if (y!=del) del->info=y->info;
		return y;
	}
}

template <class K>
ostream& operator<<(ostream& os, const Container<K>& x) {
	typename Container<K>::Iterator q;
	q.it=x.Minimum();
	while (q.it) {
		os << q.it->info;
		++q;
	}
	return os;
}
#endif
// modifica
// in container -> implementare metodo int size() che ritorna il valore di una variabile statica che conta gli oggetti aggiunti e tolti..
// in container -> implementare metodo bool empty()..c.size==0
// in container -> implementare bool operator== che ritorna true se b.size()==c.size() e se ogni elemento di b è uguale al corrispondente elemento di c