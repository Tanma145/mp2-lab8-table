#pragma once
#include "HashTable.h"
class ArrayHashTable : public HashTable{
protected:
	TableRecord* pRecs;
	int TableSize;
	int HashStep;
	int CurrentPos;
	int FreePos;
	TableRecord Mark;
	TableRecord Empty;

	virtual bool FindRecord(TKey key);
	virtual bool InsertRecord(TKey key, TValue value);
	virtual bool DeleteRecord(TKey key);
};

