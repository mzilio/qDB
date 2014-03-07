#include "marketitem.h"

MarketItem::MarketItem(string b, string n, double t): brand(b), productName(n), taxable(t) {}

MarketItem::~MarketItem() {}

string MarketItem::GetBrand() const {
	return brand;
}

string MarketItem::GetProductName() const {
	return productName;
}

double MarketItem::GetTaxable() const {
	return taxable;
}