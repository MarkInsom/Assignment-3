#include <iostream>
#include "LinkedList.h"
#include <list>

void main()
{
	LinkedList list;
	std::cout << "Checking list before any values have been pushed front or back..." << std::endl;
	if (list.empty())
	{
		std::cout << "List is empty.\n" << std::endl;
	}
	else
	{
		std::cout << "There's something in the list." << std::endl;
	}

	std::cout << "Push in the values and print: " << std::endl;
	list.pushFront(10);
	list.pushFront(20);
	list.pushFront(12);
	list.pushBack(5);
	list.pushBack(11);

	list.printDetails();
	int c = list.count();
	std::cout << "Node count: " << c << std::endl;

	list.remove(11);

	//Will clear all nodes except the first one.
	//list.clear();


	if (list.empty())
	{
		std::cout << "List is empty." << std::endl;
	}
	else
	{
		std::cout << "There's something in the list." << std::endl;
	}


	list.printDetails();
	c = list.count();
	std::cout << "Node count: " << c << std::endl;
	
	//Print first value
	//list.printFirst();
	std::cout << "First value: " << list.printFirst() << std::endl;

	//Print last value
	//list.printLast();
	std::cout << "Last Value: " << list.printLast() << std::endl;

	system("pause");
}