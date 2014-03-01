#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
using std::cout;

template <class K> class Container;

template <class K>
class Item {
	friend class Container<K>;
private:
	K info;
	Item *sx, *dx, *pred;
	Item(const K& =0, Item* =0, Item* =0, Item* =0);
};

template <class K>
class Container {
private:
	Item<K>* radice;
public:
	Container();
	void AddItem(const K&);
	Item<K>* FindItem(const K&) const;
};

template <class K>
Item<K>::Item(const K& x, Item* s, Item* d, Item* p): info(x), sx(s), dx(d), pred(p) {}

template <class K>
Container<K>::Container(): radice(0) {}

template <class K>
void Container<K>::AddItem(const K& x) {
	Item<K> *it=radice, *p=0;
	while (it) {
		p=it;
		if (x < it->info) it=it->sx;
		else it=it->dx;
	}
	Item<K> *newItem = new Item<K>(x,0,0,p);
	if (!p) radice=newItem;
	else {
		if (x < p->info) p->sx=newItem;
		else p->dx=newItem;
	}
}

template <class K>
Item<K>* Container<K>::FindItem(const K& x) const {
	Item<K>* it=radice;
	while (it!=0 && x!=it->info) {
		if (x < it->info) it = it->sx;
		else it = it->dx;
	}
	return it;
}
#endif

// inserimento - rimozione - ricerca - modifica