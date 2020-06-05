#pragma once
#include <stack>
#include "Table.h"
#include "TreeNode.h"

class TreeTable : public Table{
protected:
	TreeNode *pRoot;
	TreeNode *pCurrent;
	TreeNode *pPrev;
	int CurrentPosition;
	int level;
	std::stack<TreeNode*> stack;

	void PrintTreeTable(std::ostream& os, TreeNode* pNode);
	void DeleteTreeTable(TreeNode* pNode);
public:
	TreeTable() : Table() { CurrentPosition = level = 0; pRoot = pCurrent = pPrev = nullptr; }
	~TreeTable() { DeleteTreeTable(pRoot); }

	virtual bool IsFull() const;

	bool FindRecord(TKey k);
	TableState InsRecord(TKey k, TValue v);
	TableState DelRecord(TKey k);

	virtual bool Reset();
	virtual bool IsEnd() const;
	virtual bool GoNext();

	virtual TKey GetKey() const;
	virtual TValue GetValue() const;

	friend std::ostream& operator<<(std::ostream& os, TreeTable& tab);
	void PrintTable(std::ostream& os);
};

