#include "TreeTable.h"

bool TreeTable::IsFull() const{
	TreeNode* pNode = new TreeNode();
	bool temp = (pNode == NULL);
	delete pNode;
	return temp;
}

bool TreeTable::FindRecord(TKey k) {
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
	if (pCurrent != nullptr)
		return true;
	else {
		pCurrent = pPrev;
		return false;
	}
}

TableState TreeTable::InsRecord(TKey k, TValue v){
	if (IsFull()) {
		return TableState::table_is_full;
	}
	else if (FindRecord(k) == true) {
		return TableState::record_already_exists;
	}
	else {
		TreeNode* tmp = new TreeNode(k, v);
		if (pRoot == nullptr) {
			pRoot = tmp;
		}
		else {
			if (k < pCurrent->Key) {
				pCurrent->pLeft = tmp;
			}
			else {
				pCurrent->pRight = tmp;
			}
		}
		Efficiency++;
		DataCount++;
	}
}

TableState TreeTable::DelRecord(TKey k){
	if (FindRecord(k) == false) {
		return TableState::record_not_found;
	}
	else {
		TreeNode* pNode = pCurrent;
		if (pNode->pRight == NULL) {
			if (pPrev == NULL) {
				pRoot = pNode->pLeft;
			}
			else {
				if (pPrev->pRight == pNode) {
					pPrev->pRight = pNode->pLeft;
				}
				else {
					pPrev->pLeft = pNode->pLeft;
				}
			}
			Efficiency++;
		}
		else if (pNode->pLeft == NULL) {
			if (pPrev == NULL) {
				pRoot = pNode->pRight;
			}
			else {
				if (pPrev->pRight == pNode) {
					pPrev->pRight = pNode->pRight;
				}
				else {
					pPrev->pLeft = pNode->pRight;
				}
			}
			Efficiency++;
		}
		else {
			TreeNode* pN = pNode->pLeft;
			pPrev = pNode;
			while (pN->pRight != NULL) {
				pPrev = pN;
				pN = pN->pRight;
				Efficiency++;
			}

			pNode->Value = pN->Value;
			pNode->Key = pN->Key;
			if (pPrev->pRight == pN) {
				pPrev->pRight = pN->pLeft;
			}
			else {
				pPrev->pLeft = pN->pLeft;
			}
			pNode = pN;
			Efficiency++;
		}
		delete pNode;
		DataCount--;
		return TableState::table_is_ok;
	}
}
TKey TreeTable::GetKey(void) const {
	return (pCurrent == NULL) ? 0 : pCurrent->Key;
}

TValue TreeTable::GetValue(void) const {
	return (pCurrent == NULL) ? NULL : pCurrent->Value;
}

bool TreeTable::Reset() {
	TreeNode* pNode = pCurrent = pRoot;
	while (!stack.empty())
		stack.pop();
	CurrentPosition = 0;
	while (pNode != NULL) {
		stack.push(pNode);
		pCurrent = pNode;
		pNode = pNode->GetLeft();
	}
	return IsEnd();
}

bool TreeTable::IsEnd() const {
	return CurrentPosition >= DataCount;
}

bool TreeTable::GoNext(void) {
	if (!IsEnd() && (pCurrent != NULL))
	{
		TreeNode* pNode = pCurrent = pCurrent->GetRight();
		stack.pop();
		while (pNode != NULL) {
			stack.push(pNode);
			pCurrent = pNode;
			pNode = pNode->GetLeft();
		}
		if ((pCurrent == NULL) && !stack.empty())
			pCurrent = stack.top();
		CurrentPosition++;
	}
	return IsEnd();
}

void TreeTable::PrintTreeTable(std::ostream& os, TreeNode* pNode) {
	if (pNode != nullptr) {
		Efficiency++;
		for (int i = 0; i < level; i++)
			os << "-";
		os << pNode->Key << std::endl;
		level++;
		PrintTreeTable(os, pNode->pLeft);
		PrintTreeTable(os, pNode->pRight);
		level--;
	}
}

void TreeTable::PrintTable(std::ostream& os) {
	os << "Printing tree:" << std::endl;
	level = 0;
	PrintTreeTable(os, pRoot);
	return;
}
std::ostream& operator<<(std::ostream& os, TreeTable& tab) {
	std::cout << "Table printing" << std::endl;
	tab.PrintTreeTable(os, tab.pRoot);
	return os;
}

void TreeTable::DeleteTreeTable(TreeNode* pNode) {
	if (pNode != NULL) {
		DeleteTreeTable(pNode->pLeft);
		DeleteTreeTable(pNode->pRight);
		delete pNode;
	}
}
