#include "stapleitem.h"

double StapleItem::vat = 4.0;

StapleItem::StapleItem(string e, string b, string n, double t, bool s, int d, int m, int y): FoodItem(e,b,n,t,s,d,m,y) {}

StapleItem::~StapleItem() {}

double StapleItem::Price() const {
	double value=GetTaxable();
	if (IsDiscountable()) value-=value*(GetDiscountRate()/100.0);
	double tax=value*(vat/100.0);
	return value+tax;
}