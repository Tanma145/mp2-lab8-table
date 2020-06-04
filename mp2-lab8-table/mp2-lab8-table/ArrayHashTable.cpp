#include "ArrayHashTable.h"

bool ArrayHashTable::FindRecord(TKey key){
	bool result = false;
	FreePos = -1;
	CurrentPos = HashFunction(key) % TableSize;
	for (int i = 0; i < TableSize; i++) {
		//Efficiency++;
		if (pRecs[CurrentPos] == Empty)
			break;
		else if (pRecs[CurrentPos] == Mark) {
			if (FreePos == -1)
				FreePos = CurrentPos;
		}
		else if (pRecs[CurrentPos].Key == key) {
			result = true;
			break;
		}
		CurrentPos = GetNextPos(CurrentPos);
	}
	return result;
}

bool ArrayHashTable::InsertRecord(TKey key, TValue value){
	if (isFull())
		return TableIsFull;
	bool result = FindRecord(key);
	if (result)
		return TabRecDbl;
	else {
		if (FreePos != -1)

	}
	return false;
}
