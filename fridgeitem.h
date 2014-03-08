#ifndef FRIDGEITEM_H
#define FRIDGEITEM_H
#include "fooditem.h"

class FridgeItem : public FoodItem {
private:
	double storageTemp;
public:
	FridgeItem(string, string, string, double, bool, int, int, int, double);
	~FridgeItem();
	double GetStorageTemp() const;
};
#endif