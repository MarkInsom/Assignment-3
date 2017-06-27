#include <iostream>
#include "HashTable.h"
using namespace std;

HashTable::HashTable()
{
	data = new int[10];

	tableSize = 10;
}
HashTable::~HashTable()
{
}

void HashTable::Insert(string key, int value)
{
	unsigned int index = hashFunction(key);
	index = index % tableSize;
	data[index] = value;
}

int HashTable::Get(string key)
{
	unsigned int index = hashFunction(key);
	index = index % tableSize;
	
	if (data[index] < 0)
	{
		cout << "Index in the data is a garbage value." << endl;
	}

	return data[index];
}

void HashTable::Output()
{

}

void HashTable::Clear()
{
	delete[] data;
	cout << "Cleared Hash Table" << endl;
}

unsigned int HashTable::hashFunction(string key)
{
	unsigned int hash = 0;

	for (unsigned int index = 0; index < key.size(); index++)
	{
		hash = (hash * 1313) + data[index];
	}

	return (hash & 0x7FFFFFFF);//0x10000000)
}

int & HashTable::operator[](const string key)
{
	return data[hashFunction(key) & (tableSize - 1)];
}


