#ifndef MARKETITEM_H
#define MARKETITEM_H
#include <string>
using std::string;

class MarketItem {
private:
	string ean;
	string brand;
	string productName;
	double taxable;
	bool discount;
public:
	MarketItem(string, string, string, double, bool);
	virtual ~MarketItem();
	virtual double Price() const = 0;
	string GetEAN() const;
	string GetBrand() const;
	string GetProductName() const;
	double GetTaxable() const;
	bool IsDiscountable() const;
};
#endif