#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <Vector>
#include <ctime>
#include "ScanTable.h"
#include "SortTable.h"
#include "HashTable.h"
#include "TreeTable.h"

using namespace std;


enum class TableType { scan_table, sort_table, array_hash_table, list_hash_table, tree_table };

int main() {
	Table* pTable = nullptr;
	int DataCount = 0;
	int MemSize;
	int MaxKeyValue;
	int tableType;
	char Line[100];

	cout << "Select table type (1 - scan, 2 - sort, 3 - hash, 4 - tree)" << endl;
	cin >> tableType;
	cout << "Enter number of records" << endl;
	cin >> DataCount;
	cout << "Enter range of values" << endl;
	cin >> MaxKeyValue;
	MemSize = DataCount + 10;

	switch (tableType) {
	case 1:
		pTable = new ScanTable[MemSize];
		break;
	case 2:
		pTable = new SortTable[MemSize];
		break;
	case 3:
		pTable = new HashTable[MemSize * 3];
		break;
	case 4:
		pTable = new TreeTable[MemSize];
		break;
	}
	srand(time(0));
	while (pTable->GetDataCount() < DataCount){
		int tmp = ((double)rand() / (double)RAND_MAX) * MaxKeyValue;

		sprintf(Line, "%d", tmp);
		string value = "*";
		value += Line;
		value += "*";

		pTable->InsRecord(tmp, value);
	}
	cout << *pTable << endl << endl << "Efficiency: " << pTable->GetEfficiency() << endl << endl;

	int choice, key;
	string tmp, resultString;
	bool res;
	TableState tableState;
	while (true) {
		cout << "1 - find record, 2 - insert record, 3 - delete record" << endl;
		if (tableType == 4) cout << "4 - print tree" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter key" << endl;
			cin >> key;
			pTable->ClearEfficiency();
			res = pTable->FindRecord(key);
			resultString = (res ? "Record found" : "Record not found");
			break;
		case 2:
			cout << "Enter key" << endl;
			cin >> key;
			pTable->ClearEfficiency();
			tmp = "*";
			tmp += to_string(key);
			tmp += "*";
			tableState = pTable->InsRecord(key, tmp);

			switch (tableState) {
			case TableState::record_already_exists:
				resultString = "Unable to insert: Record already exists";
				break;
			case TableState::table_is_full:
				resultString = "Unable to insert: Table is full";
				break;
			case TableState::table_is_ok:
				resultString = "Insertion completed";
				break;
			}
			break;
		case 3:
			cout << "Enter key" << endl;
			cin >> key;
			pTable->ClearEfficiency();
			tableState = pTable->DelRecord(key);

			switch (tableState) {
			case TableState::record_not_found:
				resultString = "Unable to delete: Record not found";
				break;
			case TableState::table_is_empty:
				resultString = "Unable to delete: Table is empty";
				break;
			case TableState::table_is_ok:
				resultString = "Deletion completed";
				break;
			}
			break;
		case 4:
			pTable->ClearEfficiency();
			((TreeTable*) pTable)->PrintTable(cout);
			_getch();
			break; 
		}
		system("cls");
		cout << *pTable << endl << resultString << endl << endl << "Efficiency: " << pTable->GetEfficiency() << endl << endl;
	}
	_getch();
}