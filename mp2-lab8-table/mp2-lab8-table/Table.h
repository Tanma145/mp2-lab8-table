#pragma once
#include "Record.h"
#define MaxTableSize 200
//enum for table states?
//using namespace std;
enum class TableState {table_is_ok, table_is_empty, table_is_full, record_not_found, record_already_exists, not_enough_memory};

class Table
{
protected:
	int DataCount;
	int Efficiency;
public:
	Table() { DataCount = 0; Efficiency = 0; }
	virtual ~Table() {};

	int GetDataCount()  const { return DataCount; }
	int GetEfficiency() const { return Efficiency; }
	void ClearEfficiency() { Efficiency = 0; }
	bool IsEmpty() const { return !DataCount; }
	virtual bool IsFull() const = 0;

	virtual bool FindRecord(TKey k) = 0;
	virtual TableState InsRecord(TKey k, TValue pVal) = 0; //mb use TabRecord instead of TKey and TValue
	virtual TableState DelRecord(TKey k) = 0;

	virtual bool Reset() = 0; //returns TableState?
	virtual bool IsEnd() const = 0;
	virtual bool GoNext() = 0;

	virtual TKey GetKey() const = 0;
	virtual TValue GetValue() const = 0;

	friend std::ostream& operator<<(std::ostream& os, Table& tab) {
		os << "Printing table:" << std::endl;
		for (tab.Reset(); !tab.IsEnd(); tab.GoNext())
			os << "Key: " << tab.GetKey() << "  Value: " << tab.GetValue() << std::endl;
		return os;
	}
	//virtual void PrintTable() = 0;
	/*
	void Print(System::Windows::Forms::DataGridView^ grid) {
		grid->ColumnCount = 2;

	}
	*/
};

