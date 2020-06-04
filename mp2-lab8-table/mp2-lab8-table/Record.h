#pragma once
#include <string>
#include <iostream>
typedef int TKey;
typedef std::string TValue;

struct TableRecord{
	TKey Key;
	TValue Value;

	TableRecord(){}
	TableRecord(TKey k) { Key = k; }
	TableRecord(TKey k, TValue v) { 
		Key = k; 
		Value = v;
	}

	void SetKey(TKey k) { Key = k; }
	void SetValue(TValue v) { Value = v; }
	TKey GetKey() const { return Key; }
	TValue GetValue() const { return Value; }  

	TableRecord& operator= (const TableRecord& tr) {
		SetKey(tr.GetKey());
		SetValue(tr.GetValue());
		return *this;
	}
	           
                                                                    //bool functions must be virtual (?)
	bool operator== (const TableRecord& tr) { return Key == tr.Key; }
	bool operator!= (const TableRecord& tr) { return Key != tr.Key; }
	bool operator<  (const TableRecord& tr) { return Key < tr.Key; }                //mb signs should be swaped 
	bool operator>  (const TableRecord& tr) { return Key > tr.Key; }
	
	friend std::ostream& operator<< (std::ostream& os, const TableRecord& tr) {
		return os << tr.Key << " | " << tr.Value;
	}
};

