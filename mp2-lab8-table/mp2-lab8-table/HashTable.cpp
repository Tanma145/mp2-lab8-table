#include "HashTable.h"

unsigned int HashTable::HashFunction(const TKey key){
	unsigned int hash_value = key;
	/*
	int len = key.length();
	for (int i = 0; i < len; i++)
		hash_value += (i + 1)*;
	*/
	return hash_value;
}
