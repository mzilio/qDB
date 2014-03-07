#ifndef FOODITEM_H
#define FOODITEM_H
#include "marketitem.h"
#include "date.h"

class FoodItem : public MarketItem {
private:
	Date expirationDate;
	static double vat;
public:
	FoodItem(string, string, double, int, int, int);
	~FoodItem();
	double Price() const;
};
#endif