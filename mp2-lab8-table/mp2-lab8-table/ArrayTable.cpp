#include "ArrayTable.h"

ArrayTable::ArrayTable(int size = MaxTableSize){
	pRecords = new TableRecord[size];
	TableSize = size;
	DataCount = CurrentPosition = Efficiency = 0;
}

ArrayTable::~ArrayTable(){
	delete[] pRecords;
}

bool ArrayTable::IsFull() const
{
	return DataCount >= TableSize;
}

int ArrayTable::GetTableSize() const{
	return TableSize;
}
TableRecord ArrayTable::GetRecord() const{
	return pRecords[CurrentPosition];
}
TKey ArrayTable::GetKey() const {
	return pRecords[CurrentPosition].Key;
}

TValue ArrayTable::GetValue() const {
	return pRecords[CurrentPosition].Value;
}
TKey ArrayTable::GetKey(PositionMode mode = PositionMode::current) const{
	switch (mode) {
	case PositionMode::first:
		return pRecords[0].Key;
	case PositionMode::current:
		return pRecords[CurrentPosition].Key;
	case PositionMode::last:
		return pRecords[DataCount].Key; //mb -1?
	}
}

TValue ArrayTable::GetValue(PositionMode mode = PositionMode::current) const{
	switch (mode) {
	case PositionMode::first:
		return pRecords[0].Value;
	case PositionMode::current:
		return pRecords[CurrentPosition].Value;
	case PositionMode::last:
		return pRecords[DataCount].Value;
	}
}

bool ArrayTable::Reset(){
	CurrentPosition = 0;
	return IsEnd();
}

bool ArrayTable::IsEnd() const{
	return CurrentPosition >= DataCount;
}

bool ArrayTable::GoNext(){
	if (!IsEnd()) CurrentPosition++; //i don't like it
	return IsEnd();
}

bool ArrayTable::SetCurrentPosition(int pos){
	CurrentPosition = ((pos > -1) && (pos < DataCount)) ? pos : 0;
	return IsEnd();
}

int ArrayTable::GetCurrentPosition() const{
	return CurrentPosition;
}
