#ifndef FOODITEM_H
#define FOODITEM_H
#include "marketitem.h"
#include "date.h"

class FoodItem : public MarketItem {
private:
	Date expirationDate;
	static double vat;
	static double discountRate;
public:
	FoodItem(string, string, string, double, bool, int, int, int);
	~FoodItem();
	double Price() const;
	Date GetExpirationDate() const;
	double GetDiscountRate() const;
};
#endif