#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <Vector>
#include <ctime>
#include "ScanTable.h"
#include "SortTable.h"

using namespace std;


enum class TableType { scan_table, sort_table, array_hash_table, list_hash_table, tree_table };

int main() {
	Table* pTable = nullptr;
	vector<TKey> Keys;
	vector<TValue> Values;
	int DataCount = 0;
	int MemSize;
	int MaxKeyValue;
	int tableType;
	char Line[100];
	TableState RetCode;

	cout << "Select table type (1 - scan, 2 - sort, 3 - array_hash, 4 - list_hash, 5 - tree)" << endl;
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
		break;
	case 4:
		break;
	case 5:
		break;
	}
	Keys.resize(MemSize);
	Values.resize(MemSize);
	srand(time(0));
	for (int i = 0; i < DataCount; i++) {
		int tmp = ((double)rand() / (double)RAND_MAX) * MaxKeyValue;
		sprintf(Line, "%d", tmp);
		Keys[i] = tmp;
		Values[i] = "*";
		Values[i] += Line;
		Values[i] += "*";

		RetCode = pTable->InsRecord(Keys[i], Values[i]);
		if (RetCode != TableState::table_is_ok) {
			string message = "RetCode" +  RetCode;
			if (RetCode == TableState::record_already_exists)
				message = "Record already exists";
		}
	}
	cout << *pTable << endl << "Efficiency: " << pTable->GetEfficiency() << endl << endl;

	int choice, key;
	string tmp, resultString;
	bool res;
	TableState tableState;
	while (true) {
		cout << "1 - find record, 2 - insert record, 3 - delete record" << endl;
		cin >> choice;
		cout << "Enter key" << endl;
		cin >> key;
		switch (choice) {
		case 1:
			res = pTable->FindRecord(key);
			resultString = (res ? "Record found" : "Record not found");
			break;
		case 2:
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
		}
		system("cls");
		cout << *pTable << endl << resultString << endl << endl << "Efficiency: " << pTable->GetEfficiency() << endl << endl;
	}
	_getch();
}