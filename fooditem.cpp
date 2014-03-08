#include "fooditem.h"

double FoodItem::vat = 10.0;

double FoodItem::discountRate = 20.0;

FoodItem::FoodItem(string e, string b, string n, double t, bool s, int d, int m, int y): MarketItem(e,b,n,t,s), expirationDate(d,m,y) {}

FoodItem::~FoodItem() {}

double FoodItem::Price() const {
	double value=GetTaxable();
	if (IsDiscountable()) value-=value*(discountRate/100.0);
	double tax=value*(vat/100.0);
	return value+tax;
}

Date FoodItem::GetExpirationDate() const {
	return expirationDate;
}