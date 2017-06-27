#pragma once
#include <iostream>

class LinkedList
{
public:

	struct Node
	{
		int value;
		Node* next;
		Node* previous;
	};
	//Head
	Node* m_first;
	Node* m_last;

	void pushFront(int value);
	void pushBack(int value);
	void popFront();
	void popBack();
	void printDetails();
	void remove(int value);
	void clear();

	bool empty();

	int count();
	int printFirst() { return m_first->value; }
	int printLast() { return m_last->value; }

	LinkedList();
	~LinkedList();
};

