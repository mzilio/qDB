#include "record.h"

Record::Record(BeneImmobile* b): punt(b->clone()) {}

Record::Record(const Record& r): punt(r.punt->clone()) {}

Record::~Record() {
	delete punt;
}

Record& Record::operator=(const Record& r) {
	if(this!=&r) {
		delete punt;
		punt=r.punt->clone();
	}
	return *this;
}

bool Record::operator<(const Record& r) const {
	return *punt<*r.punt;
}

bool Record::operator==(const Record& r) const {
	return *punt==*r.punt;
}

BeneImmobile& Record::operator*() {
	return *punt;
}

BeneImmobile* Record::operator->() {
	return punt;
}

const BeneImmobile& Record::operator*() const {
	return *punt;
}

const BeneImmobile* Record::operator->() const {
	return punt;
}