#include "Tree.h"



TreeNode* Tree::insertNode(TreeNode* node, int val)
{
	if (node == NULL)
		node = new TreeNode(val);

	else
	{
		if (node->getData() < val)
		{
			TreeNode* temp = insertNode(node->getRight(), val);
			node->setRight(temp);
		}
		else
		{
			TreeNode* temp = insertNode(node->getLeft(), val);
			node->setLeft(temp);
		}
	}

	return node;
}

void Tree::inordertraversal(TreeNode * root)
{
	if (root == NULL)
		return;
	else
	{
		inordertraversal(root->getLeft());
		std::cout << root->getData() << " ";
		inordertraversal(root->getRight());
	}
}

Tree::Tree()
{
}


Tree::~Tree()
{
	delete this->root;
}

void Tree::insert(int val)
{
	this->root = insertNode(this->root, val);
}

void Tree::inorder()
{
	inordertraversal(this->root);
}
