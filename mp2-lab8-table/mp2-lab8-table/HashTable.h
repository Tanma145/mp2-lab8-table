#pragma once
#include "Table.h"
#define TableHashStep 7
class HashTable : public Table{
protected:
	TableRecord* pRecords;
	int TableSize;
	int HashStep;
	int CurrentPosition;
	int FreePosition;
	TableRecord Mark;
	TableRecord Empty;
	int GetNextPosition(int pos) { return (pos + HashStep) % TableSize; }
	unsigned int HashFunction(const TKey key);
public:
	HashTable(int Size = MaxTableSize, int Step = TableHashStep);
	virtual ~HashTable();

	virtual bool IsFull() const { return DataCount >= TableSize; }
	virtual bool Reset();
	virtual bool IsEnd() const;
	virtual bool GoNext();

	virtual bool FindRecord(TKey key);
	virtual TableState InsRecord(TKey key, TValue val);
	virtual TableState DelRecord(TKey key);

	virtual TKey GetKey() const;
	virtual TValue GetValue() const;
};

