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
	int size;
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
		bool operator==(Iterator) const;
		bool operator!=(Iterator) const;
		Iterator& operator++();
		operator bool() const;
	};
	Container();
	Container(const Container<K>&);
	~Container();
	Container<K>& operator=(const Container<K>&);
	Iterator Minimum() const;
	Iterator Maximum() const;
	static Iterator Successor(Iterator);
	static Iterator Predecessor(Iterator);
	int Size() const;
	bool Empty() const;
	void AddItem(const K&);
	Iterator FindItem(const K&) const;
	K RemoveItem(const K&);
	K& operator[](Iterator) const;
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
bool Container<K>::Iterator::operator==(typename Container<K>::Iterator x) const {
	return it==x.it;
}

template <class K>
bool Container<K>::Iterator::operator!=(typename Container<K>::Iterator x) const {
	return it!=x.it;
}

template <class K>
typename Container<K>::Iterator& Container<K>::Iterator::operator++() {
	if (it) *this=Successor(*this);
	return *this;
}

template <class K>
Container<K>::Iterator::operator bool() const {
	if (it) return true;
	else return false;
}

template <class K>
Container<K>::Container(): radice(0), size(0) {}

template <class K>
Container<K>::Container(const Container<K>& x): radice(copy(x.radice)), size(x.size) {}

template <class K>
Container<K>::~Container() {
	if (radice) delete radice;
}

template <class K>
Container<K>& Container<K>::operator=(const Container<K>& x) {
	if (this!=&x) {
		destroy(radice);
		radice=copy(x.radice);
		size=x.size;
	}
	return *this;
}

template <class K>
typename Container<K>::Iterator Container<K>::Minimum() const {
	Iterator p;
	p.it=Minimum(radice);
	return p;
}

template <class K>
typename Container<K>::Iterator Container<K>::Maximum() const {
	Iterator p;
	p.it=Maximum(radice);
	return p; 
}

template <class K>
typename Container<K>::Iterator Container<K>::Successor(typename Container<K>::Iterator x) {
	if (x) {
		typename Container<K>::Iterator y;
		if (x.it->dx) {
			y.it=Minimum(x.it->dx);
			return y;
		}
		y.it=x.it->pred;
		while (y && x.it==y.it->dx) {
			x=y;
			y.it=y.it->pred;
		}
		return y;
	}
}

template <class K>
typename Container<K>::Iterator Container<K>::Predecessor(typename Container<K>::Iterator x) {
	if (x) {
		typename Container<K>::Iterator y;
		if (x.it->sx) {
			y.it=Maximum(x.it->sx);
			return y;
		}
		y.it=x.it->pred;
		while (y && x.it==y.it->sx) {
			x=y;
			y.it=y.it->pred;
		}
		return y;
	}
}

template <class K>
int Container<K>::Size() const {
	return size;
}

template <class K>
bool Container<K>::Empty() const {
	return size == 0;
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
	size++;
}

template <class K>
typename Container<K>::Iterator Container<K>::FindItem(const K& obj) const {
	typename Container<K>::Iterator p;
	p.it=radice;
	while (p && obj!=p.it->info) {
		if (obj < p.it->info) p.it=p.it->sx;
		else p.it=p.it->dx;
	}
	return p;
}

template <class K>
K Container<K>::RemoveItem(const K& obj) {
	typename Container<K>::Iterator x, y, del;
	del=FindItem(obj);
	if (del) {
		if (!del.it->sx || !del.it->dx) y=del;
		else y=Successor(del);
		if (y.it->sx != 0) x.it=y.it->sx;
		else x.it=y.it->dx;
		if (x) x.it->pred=y.it->pred;
		if (!y.it->pred) radice=x.it;
		else {
			if (y.it==(y.it->pred)->sx) (y.it->pred)->sx=x.it;
			else (y.it->pred)->dx=x.it;
		}
		if (y!=del) del.it->info=y.it->info;
		size--;
		return del.it->info;
	}
}

template <class K>
K& Container<K>::operator[](typename Container<K>::Iterator x) const {
	if (x) return x.it->info;
}

template <class K>
ostream& operator<<(ostream& os, const Container<K>& x) {
	typename Container<K>::Iterator q;
	q=x.Minimum();
	while (q.it) {
		os << q.it->info;
		++q;
	}
	return os;
}
#endif
// modifica
// in container -> implementare bool operator== che ritorna true se b.size()==c.size() e se ogni elemento di b è uguale al corrispondente elemento di c