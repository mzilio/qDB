#include "fridgeitem.h"

FridgeItem::FridgeItem(string e, string b, string n, double t, bool s, int d, int m, int y, double c): FoodItem(e,b,n,t,s,d,m,y), storageTemp(c) {}

FridgeItem::~FridgeItem() {}

double FridgeItem::GetStorageTemp() const {
	return storageTemp;
}