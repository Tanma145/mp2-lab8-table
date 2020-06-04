#pragma once
#include "ArrayTable.h"
//в SortTable должно быть минимум два метода сортировки: n^2 и n*log(n)
class ScanTable : public ArrayTable {
public:
	ScanTable(int size = MaxTableSize) : ArrayTable(size) {}
	bool FindRecord(TKey k);
	TableState InsRecord(TKey k, TValue v);
	TableState DelRecord(TKey k);
};

