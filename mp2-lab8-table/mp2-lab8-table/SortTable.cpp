#include "SortTable.h"

bool SortTable::FindRecord(TKey key){
	Efficiency = 0;
	int start = 0;
	int finish = DataCount - 1;
	int mid = (finish + start) / 2;
	while (start <= finish) {
		Efficiency++;
		mid = (finish + start) / 2;
		if (key == pRecords[mid].GetKey()) {
			CurrentPosition = mid;
			return true;
		}

		if (key < pRecords[mid].GetKey()) {
			finish = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	CurrentPosition = finish + 1;
	return false;
}

TableState SortTable::InsRecord(TKey k, TValue v){
	if (FindRecord(k))
		return TableState::record_already_exists;
	if (DataCount < TableSize) {
		TableRecord tmp1;
		TableRecord tmp2(k, v);
		DataCount++;
		for (; !IsEnd(); GoNext()) {
			tmp1 = GetRecord();
			pRecords[CurrentPosition] = tmp2;
			tmp2 = tmp1;
		}
		return TableState::table_is_ok;
	}
	else
		return TableState::table_is_full;
}

TableState SortTable::DelRecord(TKey key){
	if (!FindRecord(key))
		return TableState::record_not_found;
	if (DataCount > 0) {
		GoNext();
		for (; !IsEnd(); GoNext()) {
			pRecords[CurrentPosition-1] = pRecords[CurrentPosition];
		}
		DataCount--;
		return TableState::table_is_ok;
	}
	else
		return TableState::table_is_full;

	return TableState();
}
