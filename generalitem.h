#ifndef GENERALITEM_H
#define GENERALITEM_H
#include "marketitem.h"

class GeneralItem : public MarketItem {
private:
	static double vat;
	static double discountRate;
public:
	GeneralItem(string, string, string, double, bool);
	~GeneralItem();
	double Price() const;
	double GetDiscountRate() const;
};
#endif