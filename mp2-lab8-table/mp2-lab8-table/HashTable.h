#pragma once
#include "Table.h"
class HashTable : public Table{
protected:
	virtual unsigned int HashFunction(const TKey key);
};

