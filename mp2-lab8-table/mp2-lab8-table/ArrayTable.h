#pragma once
#include "Table.h"
enum class PositionMode {first, current, last};

class ArrayTable : public Table
{
protected:
	TableRecord *pRecords;
	int TableSize;
	int CurrentPosition;
public:
	ArrayTable(int);
	~ArrayTable();
	virtual bool IsFull() const;
	int GetTableSize() const;

	virtual TableRecord   GetRecord() const;
	virtual TKey          GetKey() const;
	virtual TValue        GetValue() const;
	virtual TKey          GetKey   (PositionMode mode) const;
	virtual TValue        GetValue (PositionMode mode) const;

	virtual bool Reset();
	virtual bool IsEnd() const;
	virtual bool GoNext();
	virtual bool SetCurrentPosition(int);
	        int  GetCurrentPosition() const;
};

