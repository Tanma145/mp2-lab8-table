#include "ScanTable.h"

bool ScanTable::FindRecord(TKey k){
	Efficiency = 0;
	Reset();
	while (!IsEnd()) {
		if (GetKey() == k) return true;
		Efficiency++;
		GoNext();
	}
	return false;
}

TableState ScanTable::InsRecord(TKey k, TValue v){
	if (FindRecord(k))
		return record_already_exists;
	if (DataCount < TableSize) {
		pRecords[DataCount].SetKey(k);
		pRecords[DataCount].SetValue(v);
		DataCount++;
		return table_is_ok;
	}
	else
		return table_is_full;
}

TableState ScanTable::DelRecord(TKey k){
	if (!FindRecord(k))
		return record_not_found;
	pRecords[CurrentPosition] = pRecords[DataCount-1];
	DataCount--;
	return table_is_ok;
}
