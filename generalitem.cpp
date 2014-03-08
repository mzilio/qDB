#include "generalitem.h"

double GeneralItem::vat = 22.0;

double GeneralItem::discountRate = 20.0;

GeneralItem::GeneralItem(string e, string b, string n, double t, bool s): MarketItem(e,b,n,t,s) {}

GeneralItem::~GeneralItem() {}

double GeneralItem::Price() const {
	double value=GetTaxable();
	if (IsDiscountable()) value-=value*(discountRate/100.0);
	double tax=value*(vat/100.0);
	return value+tax;
}

double GeneralItem::GetDiscountRate() const {
	return discountRate;
}