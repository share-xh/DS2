/*
 * main.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: dor
 */

#include <iostream>
#include "DataStructures/AVLRankTree.h"
#include "DataStructures/UnionFind.h"
#include "DataStructures/HashTable.h"
#include "DataStructures/UnionFindSelectiveUnion.h"
#include "Exceptions/UNIONExceptions.h"

//#include "Objects/Fruit.h"
using namespace std;

void TreeInterface();
void UnionInterface();
void HashTableInterface();


/*int main(int argc, const char** argv) {
	UnionInterface();
	return 0;
}*/


void TreeInterface() {
	cout << "Good morning Sir. You may create your AVLRankTree now." << endl;
	cout << "######################################################" << endl;
	int choice, item, ID, *arr, min, max;
	;

	AVLRankTree<int, int> avl;
	while (1) {
		cout << "1. Insert";
		cout << "\t\t2. Remove" << endl;
		cout << "3. Display";
		cout << "\t\t4. Generate array" << endl;
		cout << "5. Get leftest";
		cout << "\t\t6. GetRange" << endl;
		cout << "9. Exit" << endl << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "What is the ID? ";
			cin >> ID;
			cout << "Enter Item: ";
			cin >> item;
			//avl.Insert(ID, new int(item));
			avl.Insert(ID, item);
			break;
		case 2:
			cout << "What is the ID? ";
			cin >> ID;
			avl.Remove(ID);
			break;
		case 3:
			cout << "Balanced AVL Tree:" << endl;
			avl.print();
			break;
		case 4:
			cout << "array:" << endl;
			arr = avl.getSortedArray();
			cout << arr[0];
			for (int i = 1; i < avl.GetSize(); i++) {
				cout << "," << arr[i];
			}
			cout << endl;
			free(arr);
			break;
		case 5:
			cout << "minimin key is:" << endl;
			cout << avl.getSmallest() << endl;
			break;
		case 6:
			cout << "Enter min: ";
			cin >> min;
			cout << "Enter max: ";
			cin >> max;
			cout << "Amout of elements in range: ";
			cout << avl.getInRange(min, max) << endl;
			break;
		case 9:
			exit(0);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
		cout << endl
				<< "-------------------------------------------------------"
				<< endl;
	}
}

void UnionInterface() {
	cout << "Good morning Sir. You may create your UnionFind DS now." << endl;
	cout << "#######################################################" << endl;
	int id1, id2, n, choice, data;

	cout << "Please enter the structure size: ";
	cin >> n;

	cout << "#######################################################" << endl;
	UnionFindSelectiveUnion<int> uf(n, 0);
	while (1) {

		cout << "1. Union";
		cout << "\t\t2. Find" << endl;
		cout << "3. Set set data";
		cout << "\t\t4. Get set data" << endl;
		cout << "5. PrintFake";
		cout << "\t\t6. PrintReal" << endl;
		cout << "9. Exit" << endl << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter Set1 id: ";
			cin >> id1;
			cout << "Enter Set2 id: ";
			cin >> id2;
			try {
				uf.Union(id1, id2);
			} catch (UnionFailure& e) {
				cout << "already together" << endl;
			}
			break;
		case 2:
			cout << "Set index: ";
			cin >> id1;
			cout << "The Set the include " << id1 << "is: " << uf.Find(id1)
					<< endl;
			break;
		case 3:
			cout << "Enter Set id: ";
			cin >> id1;
			cout << "Enter data: ";
			cin >> data;
			uf.SetData(id1, data);
			break;
		case 4:
			cout << "Enter Set id: ";
			cin >> id1;
			cout << uf.GetData(id1) << endl;
			break;
		case 5:
			cout << "The current fake state of the datastructures is: " << endl;
			uf.Print();
			break;
		case 6:
			cout << "The current real state of the datastructures is: " << endl;
			uf.PrintReal();
			break;
		case 9:
			exit(0);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
		cout << endl
				<< "-------------------------------------------------------"
				<< endl;
	}
}

void HashTableInterface() {
	cout << "Good morning Sir. You may create your UnionFind DS now." << endl;
	cout << "#######################################################" << endl;

	HashTable<int> hashingTable;
	int key, val;
	int userVal = 1;
	while (userVal != 0) {
		cout << "1. Insert";
		cout << "\t\t2. Find" << endl;
		cout << "3. Delete";
		cout << "\t\t9. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> userVal;

		switch (userVal) {
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> val;
			cout << "Enter key at which element to be inserted: ";
			cin >> key;
			hashingTable.Insert(key, val);
			break;
		case 2:
			cout << "Enter key of the element to be searched: ";
			cin >> key;
			try {
				cout << "Element at key " << key << " : "
						<< hashingTable.Find(key) << endl;
			} catch (...) {
				cout << "Key does not exist" << endl;
			}
			break;
		case 3:
			cout << "Enter key of the element to be deleted: ";
			cin >> key;
			cout
					<< "Nothing can be deleted from this Hash Table Implementation."
					<< endl;
			break;
		case 9:
			exit(0);
		default:
			cout << "Wrong Choice" << endl;
		}
		cout << endl
				<< "-------------------------------------------------------"
				<< endl;
	}
}
