#include "LinkedList.h"
#include <iostream>


void LinkedList::pushFront(int value)
{
	//Let N be new ListNode
	Node* n = new Node();
	//Set N.next to list.first
	n->next = m_first;
	//set N.previous to NULL
	n->previous = nullptr;
	//set N.value to value
	n->value = value;

	//last will be NULL if list empty
	if (m_last == nullptr)
	{
		m_last = n;
	}
	if (m_first != nullptr)// if list is not empty
	{
		m_first->previous = n;
	}
	//Set list.first to N
	m_first = n;
}

void LinkedList::pushBack(int value)
{
	
	Node* n = new Node();
	n->previous = m_last;
	n->next = nullptr;
	n->value = value;

	if (m_first == nullptr)
	{
		m_first = n;
	}
	if (m_last != nullptr)// if list is not empty
	{
		m_last->next = n;
	}

	m_last = n;
}

void LinkedList::popFront()
{
	if (m_first->next != nullptr)
	{
		m_first->next->previous = m_first->previous;
	}

	m_first = m_first->next;
	delete m_first;
}

void LinkedList::popBack()
{
	if (m_last->next != nullptr)
	{
		m_last->next->previous = m_last->previous;
	}

	m_last = m_last->next;
	delete m_last;
}

bool LinkedList::empty()
{
	if (m_first == nullptr)
	{
		return true;
	}
	else
		return false;
}

//Counts the no. of occurences of a node
int LinkedList::count()
{
	//Let currentNode be new list node
	Node* currentNode = new Node();
	currentNode = m_first;
	int count = 0;
	
	while (currentNode != nullptr)
	{
		currentNode = currentNode->next;
		count++;
	}

	return count;
}

void LinkedList::printDetails()
{
	//Node to currentNode
	Node* currentNode;
	//Set currentNode to m_first
	currentNode = m_first;

	std::cout << "Print List: " << std::endl;
	//while currentNode isnt equal to null
	while (currentNode != nullptr)
	{
		auto temp = currentNode->next;
		//display currentNode's value
		std::cout << currentNode->value << std::endl;
		//switch currentNode's value to next
		currentNode = temp;
	}

	std::cout << "\n" << std::endl;

}

void LinkedList::remove(int value)
{
	Node* prev = m_first;

	while (prev != nullptr)
	{
		auto current = prev->next;
		if (prev->value == value)
		{
			if (prev == m_first)
				m_first = prev->next;
			if (prev == m_last)
				m_last = prev->previous;
			if (prev->next != nullptr)
				prev->next->previous = prev->previous;
			if (prev->previous != nullptr)
				prev->previous->next = prev->next;
			std::cout << "Deleting: " << prev->value << "\n";
			//prev->next = prev->next;
			delete prev;
		}
		prev = current;
	}
}

void LinkedList::clear()
{
	while (m_first != nullptr)
	{
		auto next = m_first->next;
		delete m_first;
		m_first = next;
		if (m_first == nullptr)
			break;
	}
	m_first = m_last = nullptr;
}

LinkedList::LinkedList()
{
	//First blank node
	m_first = nullptr;
	//Last blank node
	m_last = nullptr;
}

LinkedList::~LinkedList()
{
	while (m_first != nullptr)
	{
		auto next = m_first->next;
		delete m_first;
		m_first = next;
	}
}
