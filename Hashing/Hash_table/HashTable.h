#pragma once
#include <string>
using namespace std;

class HashTable
{
public:
	HashTable();
	~HashTable();

	void Insert(string key, int value);
	int Get(string key);
	void Output();
	void Clear();


	unsigned int hashFunction(string key);

	int& operator[](const string key);

private:
	int* data;
	int* empty;
	unsigned int tableSize;

};

