#include "fooditem.h"

double FoodItem::vat = 10.0;

FoodItem::FoodItem(string b, string n, double t, int d, int m, int y): MarketItem(b,n,t), expirationDate(d,m,y) {}

FoodItem::~FoodItem() {}

double FoodItem::Price() const {
	double value=GetTaxable();
	double tax=value*(vat/100.0);
	return value+tax;
}