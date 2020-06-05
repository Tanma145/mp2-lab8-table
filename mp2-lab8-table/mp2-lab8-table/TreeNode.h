#pragma once
#include "Record.h"

class TreeNode : public TableRecord{
protected:
	TreeNode *pLeft, *pRight;
	int Balance;
public:
	TreeNode() { pLeft = pRight = nullptr; Balance = 0;}
	TreeNode(TKey key, TValue value, TreeNode* pL = nullptr, TreeNode* pR = nullptr, int bal = 0) : TableRecord(key, value), pLeft(pL), pRight(pR), Balance(bal) {}
	TreeNode* GetLeft() const { return pLeft; }
	TreeNode* GetRight() const { return pRight; }

	int GetBalance() const { return Balance; }
	void SetBalance(int bal) { Balance = bal; }
	friend class TreeTable;
};

