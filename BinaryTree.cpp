// ASSIGNMENT 1 - Programming in C/C++ 2 2017 - by JEPPE WILLATZEN - 05-11-2017 - BinaryTree.cpp
#include "BinaryTree.h"


BinaryTree::BinaryTree() 
{
	root = nullptr;
}


BinaryTree::BinaryTree(std::shared_ptr<LinkedList> list) 
{
	// Implement this if going for PwD. If not, leave as is. 
}


BinaryTree::~BinaryTree() {}


void do_insert(int value, std::shared_ptr<TreeNode> node)
{
	auto newItem = std::make_shared<TreeNode>(value);
	if (value < node->get_value()) // left = smaller, check this firstly
	{
		if (node->left)
		{
			do_insert(value, node->left); // recursion, i.e. check again one step further down using the node->left
		}
		else
		{
			node->left = newItem; // at the end, left is a nullptr so insert here
		}
	}
	else // if the argument's value is larger than the node's value: go right
	{
		if (value > node->get_value())
		{
			if (node->right)
			{
				do_insert(value, node->right); // recursion, i.e. check again one step further down using the node->right
			}
			else
			{
				node->right = newItem; // at the end, right is a nullptr so insert here
			}
		}
	}
}


void do_enumerate(std::shared_ptr<LinkedList> list, std::shared_ptr<TreeNode> node) // depth first
{
	if (node) // not nullptr
	{
		if (node->left) // recursion if the left ptr of the node isn't pointing to the nullptr
		{
			do_enumerate(list, node->left);
		}
		if (node->right) // recursion if the right ptr of the node isn't pointing to the nullptr
		{
			do_enumerate(list, node->right);
		}
		list->addItem(node->get_value()); // reached the end, i.e. both left and right ptrs for the node are nullptrs, so add the value to the list
	}
}


void BinaryTree::insert(int value) 
{
	auto newItem = std::make_shared<TreeNode>(value);
	if (!root) // if no root, assign it
	{
		root = newItem;
	}
	else
	{
		do_insert(value, root);
	}
}


std::shared_ptr<LinkedList> BinaryTree::enumerate() 
{
	std::shared_ptr<LinkedList> list = std::make_shared<LinkedList>(); // list to store the values
	do_enumerate(list, root);
	return list; // contains all the values
}


int BinaryTree::getDepth(int value)
{
	int depth = 0;
	std::shared_ptr<TreeNode> node = root;
	while (node)
	{
		if (value == node->get_value()) // if the argument value is the same as the node, stop searching and return
		{
			return depth;
		}
		else
		{
			if (value < node->get_value()) // if the argument value is smaller, increment depth by 1, go left and check again
			{
				depth++;
				node = node->left;
				continue;
			}
			else
			{
				if (value > node->get_value()) // if the argument value is larger, increment depth by 1, go right and check again
				{
					depth++;
					node = node->right;
					continue;
				}
			}
		}
	}
	return 0;
}
