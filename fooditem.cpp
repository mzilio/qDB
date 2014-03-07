#include "fooditem.h"

double FoodItem::vat = 10.0;

FoodItem::FoodItem(string b, string n, double t): MarketItem(b,n,t) {}

FoodItem::~FoodItem() {}

double FoodItem::Price() const {
	double value=GetTaxable();
	double tax=value*(vat/100.0);
	return value+tax;
}