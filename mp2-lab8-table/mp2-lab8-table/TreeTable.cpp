#include "TreeTable.h"

int TreeTable::FindRecord(TKey k) {
	pPrev = nullptr;
	pCurrent = pRoot;
	while (pCurrent != nullptr) {
		Efficiency++;
		if (pCurrent->Key == k) break;
		pPrev = pCurrent;
		if (pCurrent->Key < k)
			pCurrent = pCurrent->pRight;
		else
			pCurrent = pCurrent->pLeft;


	}
	return 0;
}

int TreeTable::InsertRecord(TKey k, TValue v)
{
	return 0;
}
