#include "HashTable.h"

unsigned int HashTable::HashFunction(const TKey key){
	unsigned int hash_value = key;
	/*
	int len = key.length();
	for (int i = 0; i < len; i++)
		hash_value += (i + 1) * key[i];
	*/
	return hash_value;
}

HashTable::HashTable(int Size, int Step) : TableSize(Size), HashStep(Step){
	Efficiency = 0;
	pRecords = new TableRecord[TableSize];
	Empty = TableRecord(-1);
	Mark = TableRecord(-2);
	for (int i = 0; i < TableSize; i++)
		pRecords[i] = Empty;
}

HashTable::~HashTable(){
	delete[] pRecords;
}

bool HashTable::FindRecord(TKey key){
	bool result = false;
	FreePosition = -1;
	CurrentPosition = HashFunction(key) % TableSize;
	for (int i = 0; i < TableSize; i++) {
		Efficiency++;
		if (pRecords[CurrentPosition] == Empty)
			break;
		else if (pRecords[CurrentPosition] == Mark) {
			if (FreePosition == -1)
				FreePosition = CurrentPosition;
		}
		else if (pRecords[CurrentPosition].Key == key) {
			result = true;
			break;
		}
		CurrentPosition = GetNextPosition(CurrentPosition);
	}
	return result;
}

TableState HashTable::InsRecord(TKey key, TValue val){
	if (IsFull()) {
		return TableState::table_is_full;
	}
	bool result = FindRecord(key);
	if (result) {
		return TableState::record_already_exists;
	}
	if (FreePosition != -1)
		CurrentPosition = FreePosition;
	pRecords[CurrentPosition] = TableRecord(key, val);
	DataCount++;
	return TableState::table_is_ok;
}

TableState HashTable::DelRecord(TKey key){
	if (IsEmpty())
		return TableState::table_is_empty;
	bool result = FindRecord(key);
	if (!result)
		return TableState::record_not_found;
	pRecords[CurrentPosition] = Mark;
	DataCount--;
	return TableState::table_is_ok;
}

TKey HashTable::GetKey() const{
	return pRecords[CurrentPosition].Key;
}

TValue HashTable::GetValue() const{
	return pRecords[CurrentPosition].Value;
}
bool HashTable::Reset() {
	CurrentPosition = 0;
	while (CurrentPosition < TableSize) {
		if ((pRecords[CurrentPosition] != Empty) && (pRecords[CurrentPosition] != Mark))
			break;
		else
			CurrentPosition++;
	}
	return IsEnd();
}

bool HashTable::IsEnd() const {
	return CurrentPosition >= TableSize;
}

bool HashTable::GoNext() {
	if (!IsEnd()) {
		while (++CurrentPosition < TableSize) {
			if ((pRecords[CurrentPosition] != Empty) && (pRecords[CurrentPosition] != Mark))
				break;
		}
	}
	return IsEnd();
}
