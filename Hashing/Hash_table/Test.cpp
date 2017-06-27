#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

void main()
{
	HashTable hashed;

	string name = "b";
	string name2 = "c";

	
	hashed.Insert(name, 5);
	//hashed.Get(name);

	cout << "Hash: " << name << "\n" << hashed.hashFunction(name) << endl;
	cout << "Get: " << name << "\n" << hashed.Get(name) << endl;

	hashed.Clear();


	cout << "Hash: " << name << "\n" <<  hashed.hashFunction(name) << endl;
	cout << "Get: "  << hashed.Get(name) << endl;

	hashed.Insert(name, 3);
	cout << "Hash: " << name << "\n" << hashed.hashFunction(name) << endl;
	cout << "Get: " << name << "\n" << hashed.Get(name) << endl;

	hashed.Insert(name2, 6);
	cout << "Hash: " << name2 << "\n" << hashed.hashFunction(name2) << endl;
	cout << "Get: " << name2 << "\n" << hashed.Get(name2) << endl;

	system("pause");
}

