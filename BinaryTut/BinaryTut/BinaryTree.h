#pragma once
class BinaryTree
{
public:

	struct TreeNode 
	{
		int m_value;
		TreeNode();
		TreeNode(int a_value);
		TreeNode* m_left;
		TreeNode* m_right;
	};
	BinaryTree();
	~BinaryTree();

	bool isEmpty() const;
	void insert(int a_nValue);
	void remove(int a_nValue);
	
private:
	TreeNode* m_pRoot;
	void RemoveLeaf(TreeNode* nodeToRemove, TreeNode* nodeToRemovesParent);
	void RemoveOneChild(TreeNode* nodeToRemove, TreeNode* nodeToRemovesParent);
};

