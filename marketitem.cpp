#include "marketitem.h"

MarketItem::MarketItem(string e, string b, string n, double t, bool d): ean(e), brand(b), productName(n), taxable(t), discount(d) {}

MarketItem::~MarketItem() {}

string MarketItem::GetEAN() const {
	return ean;
}

string MarketItem::GetBrand() const {
	return brand;
}

string MarketItem::GetProductName() const {
	return productName;
}

double MarketItem::GetTaxable() const {
	return taxable;
}

bool MarketItem::IsDiscountable() const {
	return discount;
}