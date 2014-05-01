#ifndef RECORD_H
#define RECORD_H
#include "beneimmobile.h"

class Record {
private:
	BeneImmobile* punt;
public:
	Record(BeneImmobile*);
	Record(const Record&);
	Record& operator=(const Record&);
	~Record();
	bool operator<(const Record&) const;
	bool operator==(const Record&) const;
};
#endif