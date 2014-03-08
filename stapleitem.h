#ifndef STAPLEITEM_H
#define STAPLEITEM_H
#include "fooditem.h"

class StapleItem : public FoodItem {
private:
	static double vat;
public:
	StapleItem(string, string, string, double, bool, int, int, int);
	~StapleItem();
	double Price() const;
};
#endif