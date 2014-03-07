#ifndef MARKETITEM_H
#define MARKETITEM_H
#include <string>
using std::string;

class MarketItem {
private:
	string brand;
	string productName;
	double taxable;
protected:
	MarketItem(string, string, double);
	virtual ~MarketItem();
public:
	virtual double Price() const = 0;
	string GetBrand() const;
	string GetProductName() const;
	double GetTaxable() const;
};
#endif
/*
iva diversa per categorie di prodotti
-normalmente 22%
-prodotti alimentari 10%
-prodotti alimentari prima necessità 4%

diverse categorie di prodotti:
-alimentari (data di scadenza)
	-da frigo (temperatura di conservazione)
-non alimentari (garanzia)
*/