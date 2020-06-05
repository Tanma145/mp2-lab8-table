#pragma once
#include "ArrayTable.h"
#include "SortTable.h"

class ScanTable : public ArrayTable {
public:
	ScanTable(int size = MaxTableSize) : ArrayTable(size) {}
	bool FindRecord(TKey k);
	TableState InsRecord(TKey k, TValue v);
	TableState DelRecord(TKey k);
};

