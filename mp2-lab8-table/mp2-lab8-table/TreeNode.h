#pragma once
#include "Record.h"
class TreeNode : public TableRecord{
protected:
	TreeNode *pLeft, *pRight;
	int Balance;
public:
	TreeNode() { pLeft = pRight = nullptr; Balance = 0;}
};

