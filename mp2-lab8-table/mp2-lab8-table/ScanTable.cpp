#include "ScanTable.h"
#include <algorithm>

bool ScanTable::FindRecord(TKey k){
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
		return TableState::record_already_exists;
	if (DataCount < TableSize) {
		pRecords[DataCount].SetKey(k);
		pRecords[DataCount].SetValue(v);
		DataCount++;
		return TableState::table_is_ok;
	}
	else
		return TableState::table_is_full;
}

TableState ScanTable::DelRecord(TKey k){
	if (!FindRecord(k))
		return TableState::record_not_found;
	pRecords[CurrentPosition] = pRecords[DataCount-1];
	DataCount--;
	return TableState::table_is_ok;
}
