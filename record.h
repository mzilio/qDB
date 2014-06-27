#ifndef RECORD_H
#define RECORD_H
#include "beneimmobile.h"

class Record {
private:
	BeneImmobile* punt;
public:
	Record(BeneImmobile*);
	Record(const Record&);
	~Record();
	Record& operator=(const Record&);
	bool operator<(const Record&) const;
	bool operator==(const Record&) const;
	bool operator!=(const Record&) const;
	BeneImmobile& operator*();
	BeneImmobile* operator->();
	const BeneImmobile& operator*() const;
	const BeneImmobile* operator->() const;
};

#endif