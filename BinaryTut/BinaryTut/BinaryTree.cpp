#include <iostream>
#include "BinaryTree.h"

//Allows to use assert which will jump/break out of the console
//used for debugging as well.
#include <assert.h>


BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
}
//Condition check to see if the tree is empty
bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
		return true;
	else
		return false;
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* newNode = new TreeNode();
	newNode->m_value = a_nValue;
	//if the tree is empty, the value is inserted at the root
	if (isEmpty() == true)
	{
		m_pRoot = newNode;
		std::cout << "Root node with value of: " << m_pRoot->m_value << std::endl;
		return;
	}
	//Set the current node pointer to the root node
	TreeNode* currentNode = m_pRoot;


	//While the current node is not null
	while (true)
	{
		//if the value to be inserted is less than the value in the current node
		if (newNode->m_value < currentNode->m_value)
		{
			//Set the current node to the left child and continue
			if (currentNode->m_left != nullptr)
			{
				//shifting current node to the left node.
				currentNode = currentNode->m_left;
			}
			else
			{
					std::cout << "Adding a node to the left of current node with value of: " << currentNode->m_value << " Left : " << newNode->m_value << std::endl;
					//adding newNode at the current node
					currentNode->m_left = newNode;
					//jump out of the loop
					return;
			}

		}//if the value to be inserted is less than the value in the current node
		else if (newNode->m_value > currentNode->m_value)
		{
			if (currentNode->m_right != nullptr)
			{
				//Shifting the current node to the right node.
				currentNode = currentNode->m_right;
			}
			else
			{
				std::cout << "Adding a node to the right of current node with value of: " << currentNode->m_value << " Right : " << newNode->m_value << std::endl;
				//adding newNode at the current node
				currentNode->m_right = newNode;
			
				//jump out of the loop
				return;

			}
		}
		//if the value to be inserted is the same as the value in the current node
		else
		{
			std::cout << "The value is already in the tree. :->" << newNode->m_value << std::endl;
			//The value is already in the tree, so exit.
			currentNode->m_value = newNode->m_value;
			return; //exit insert function
		}
	}//end While
}

void BinaryTree::remove(int a_nValue)
{
	//FIND THE NODE TO REMOVE
	//store node to remove's parent as pointer
	TreeNode* nodeToRemove = m_pRoot;
	//store node to remove as pointer
	TreeNode* nodeToRemovesParent = nullptr;
	//to set true if number is found.
	bool found = false;

	//is the first in the tree a nullptr? if so , display there is no tree.
	if(nodeToRemove == nullptr)
	{
		std::cout << "No tree fround." << std::endl;
	}
	//While the nodeToRemove is not  nullptr, iterate through.
	while (nodeToRemove != nullptr)
	{
		//if nodeToRemove's value is equal to inserted value, iterate.
		if (nodeToRemove->m_value == a_nValue)
		{
			//Output that the value is equal.
			std::cout << a_nValue << " was found!" << std::endl;
			std::cout << a_nValue << " was deleted!" << std::endl;
			//set bool to true, it was found.
			found = true;
			//get out of this function.
			break;
		}
		else //else, if it's not equal to the inserted value
		{
			//search through using a loop (sort of similar to insert)
			nodeToRemovesParent = nodeToRemove;
			//if inserted value is greater than the nodeToRemove's value, iterate, else...
			if (a_nValue > (nodeToRemove->m_value))
			{
				//Go to Right of nodeToRemove
				nodeToRemove = nodeToRemove->m_right;
			}else{

				//Go to Left of NodeToRemove
				nodeToRemove = nodeToRemove->m_left;
			}
		}
	}
	//Finding if the value exists in the tree.
	if (!found)
	{
		//Display inserted value on console.
		std::cout << a_nValue << " was not found!" << std::endl;
	}
	
	//2 children
	if ((nodeToRemove->m_left != nullptr && nodeToRemove->m_right != nullptr))
	{
		//assert(false);
		//Remove 2 Children(node to remove and its parent)
		//Get the greatest value from the nodeToRemove.
		TreeNode* nextNode = nodeToRemove->m_right;
		TreeNode* nextNodeParent = nodeToRemove;
		//Get the smallest value from the left of nextNode.
		while (nextNode->m_left != nullptr)
		{
			nextNodeParent = nextNode;
			nextNode = nextNode->m_left;
		}
		//Copy nextNode's value into nodeToRemove's value
		nodeToRemove->m_value = nextNode->m_value;

		//If next node's right and left have nothing, remove leaf.
		if ((nextNode->m_right == nullptr && nextNode->m_left == nullptr))
		{
			RemoveLeaf(nextNode, nextNodeParent);
		}
		//If it has a child then moves child into the parent's node left
		if ((nextNode->m_right != nullptr && nextNode->m_left == nullptr))
		{
			RemoveOneChild(nextNode, nextNodeParent);
		}

	}
	//No children - Leaf node
	else if ((nodeToRemove->m_left == nullptr && nodeToRemove->m_right == nullptr))
	{
		RemoveLeaf(nodeToRemove, nodeToRemovesParent);
	}
	//node has 1 child
	else
	{
		RemoveOneChild(nodeToRemove, nodeToRemovesParent);
	}
}


//Remove the leaf and set the left or right to null
void BinaryTree::RemoveLeaf(TreeNode * nodeToRemove, TreeNode * nodeToRemovesParent)
{
	//Checking if left is nodeToRemove
	if (nodeToRemovesParent->m_left == nodeToRemove)
	{
		//Parent's left is = null
		nodeToRemovesParent->m_left = nullptr;
	}
	//Checking if right is nodeToRemove
	if (nodeToRemovesParent->m_right == nodeToRemove)
	{
		//Parent's right is = null
		nodeToRemovesParent->m_right = nullptr;
	}
		std::cout << nodeToRemove->m_value << " was leaf node." << std::endl;
		delete nodeToRemove; //Remove nodeToRemove
}

//Delete the leaf with the one child.
void BinaryTree::RemoveOneChild(TreeNode * nodeToRemove, TreeNode * nodeToRemovesParent)
{
	//Left leaf present, no Right leaf.
	if (nodeToRemove->m_left != nullptr && nodeToRemove->m_right == nullptr)
	{
		//If node to remove is on the left of parent then delete the left.
		if (nodeToRemovesParent->m_left == nodeToRemove)
		{
			nodeToRemovesParent->m_left = nodeToRemove->m_left;
			delete nodeToRemove;
		}
		else
		{
			nodeToRemovesParent->m_right = nodeToRemove->m_left;
			delete nodeToRemove;
		}

	}
	//Right leaf present, no Left leaf.
	if (nodeToRemove->m_right != nullptr && nodeToRemove->m_left == nullptr)
	{
		//If node to remove is on the right of parent then delete the right.
		if (nodeToRemovesParent->m_right == nodeToRemove)
		{
			nodeToRemovesParent->m_right = nodeToRemove->m_right;
			delete nodeToRemove;
		}
		else
		{
			nodeToRemovesParent->m_left = nodeToRemove->m_right;
			delete nodeToRemove;
		}
	}

}

BinaryTree::TreeNode::TreeNode()
{
	m_left = nullptr;
	m_right = nullptr;
	m_value = NULL;
}

BinaryTree::TreeNode::TreeNode(int a_value)
{
	m_left = nullptr;
	m_right = nullptr;
	m_value = a_value;
}


