#include "record.h"

Record::Record(BeneImmobile* b): punt(b->clone()) {}

Record::Record(const Record& r): punt(r.punt->clone()) {}

Record& Record::operator=(const Record& r) {
	if(this!=&r) {
		delete punt;
		punt=r.punt->clone();
	}
	return *this;
}

Record::~Record() {
	delete punt;
}

bool Record::operator<(const Record& r) const {
	return *punt<*r.punt;
}

bool Record::operator==(const Record& r) const {
	return *punt==*r.punt;
}