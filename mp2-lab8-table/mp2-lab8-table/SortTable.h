#pragma once
#include "ArrayTable.h"
class SortTable : public ArrayTable {
public:
	SortTable(int size = MaxTableSize) : ArrayTable(size) {}
	SortTable(TableRecord*, int);
	bool FindRecord(TKey k);
	TableState InsRecord(TKey k, TValue v);
	TableState DelRecord(TKey k);
};

