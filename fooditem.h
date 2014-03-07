#ifndef FOODITEM_H
#define FOODITEM_H
#include "marketitem.h"

class FoodItem : public MarketItem {
private:
	static double vat;
public:
	FoodItem(string, string, double);
	~FoodItem();
	double Price() const;
};
#endif
/*
	TODO come incapsulare il campo data di scadenza?
*/