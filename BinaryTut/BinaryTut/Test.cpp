#include <iostream>
#include "BinaryTree.h"
using namespace std;


//void Remove(int value)
//start by removing a leaf node only



void main()
{
	//Calling class and naming
	BinaryTree tree;
	//Insert with the value inserted.
	tree.insert(20);
	tree.insert(10);
	tree.insert(15);
	tree.insert(5);
	tree.insert(30);
	tree.insert(35);
	tree.insert(32);
	//Using the remove and with value inserted.
	tree.remove(20);



	system("pause");
}

//Template used to help with remove()
//    20
//10        50  <<<<
//        30