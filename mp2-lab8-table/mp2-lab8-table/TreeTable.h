#pragma once
#include <stack>
#include "Table.h"
#include "TreeNode.h"

class TreeTable : public Table
{
protected:
	TreeNode *pRoot, *pCurrent, *pPrev;
	int CurrentPosition;
	std::stack<TreeNode*> stack;

	void  PrintTreeTable(std::ostream os);
public:
	bool FindRecord(TKey k);
	bool InsertRecord(TKey k, TValue v);
};

