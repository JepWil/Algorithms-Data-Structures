// ASSIGNMENT 1 - Programming in C/C++ 2 2017 - by JEPPE WILLATZEN - 05-11-2017 - LinkedList.cpp
#include "LinkedList.h"


LinkedList::LinkedList() 
{
	root = nullptr;
	size = 0;
}


LinkedList::~LinkedList() {}


void swap(int a, int b, std::shared_ptr<ListItem>& root) 
{
	// initializing two ptrs (previous and current) for a's and b's respective elements
	std::shared_ptr<ListItem> currA = root;
	std::shared_ptr<ListItem> prevA = nullptr;
	std::shared_ptr<ListItem> currB = root;
	std::shared_ptr<ListItem> prevB = nullptr;
	for (int i = 0; i < a; ++i)	// loop until index a is reached and assign ptrs
	{
		prevA = currA;
		currA = prevA->next;
	}
	for (int i = 0; i < b; ++i) // loop until index b is reached and assign ptrs
	{
		prevB = currB;
		currB = prevB->next;
	}
	if (prevA) // prevA is not the root
	{
		prevA->next = currB;
	}
	else // A was the root; so now:
	{
		root = currB;
	}
	if (prevB) // same as above. prevB is not the root
	{
		prevB->next = currA;
	}
	else // B was the root; so now:
	{
		root = currA;
	}
	std::shared_ptr<ListItem> placeHolder = currB->next; // placeHolder contains current B's next ptr
	currB->next = currA->next; // current B's next ptr is stored in placeHolder so now it can be reassigned
	currA->next = placeHolder; // current A´'s next ptr is then assigned to the former current B next ptr via the placeHolder
}


void LinkedList::addItem(int item) 
{
	auto newItem = std::make_shared<ListItem>(item);
	if (!root) // no root(empty list); assign it
	{
		root = newItem;
	}
	else // not empty, so point NewItem's next ptr to the former root and add NewItem to the start of the list
	{
		newItem->next = root;
		root = newItem;
	}
}


int LinkedList::getItem(int index) 
{
	// starts at root, loops through until the index is reached 
	// then the get_item function is called and returns the value
	auto node = root;
	for (int i = 0; i < index; ++i)
	{
		node = node->next;
	}
	return node->get_item();
}


void LinkedList::deleteItem(int index)
{
	if (index == 0) // deleting the root by reassigning it to the next in the list
	{
		root = root->next;
	}
	else
	{
		std::shared_ptr<ListItem> node = root;
		for (int i = 0; i < index - 1; i++)	// starts at root, loops through the list and finds the desired node to be deleted
		{
			node = node->next;
		}
		std::shared_ptr<ListItem> removeNode = node->next; 
		node->next = node->next->next; // disconnects the removeNode by reassigning the next ptr of the node before removeNode to the node after removeNode
		removeNode->next = nullptr; // assign removeNode's next ptr to nullptr to fully disconnect it from the list
	}
}


int LinkedList::getSize()
{
	std::shared_ptr<ListItem> item = root;
	int numitems = 1;
	while (item->next) // loop through the list and increment numItems by 1 until the end has been reached
	{
		item = item->next;
		numitems += 1;
	}
	return numitems;
}


void LinkedList::sort()
{
	for (int i = 1; i < this->getSize(); i++) // loop through the list
	{
		int j = i;
		while ((j > 0) && this->getItem(j) < this->getItem(j - 1)) // checks the values of two adjacent indices; if second is smaller than the first: swap
		{
			swap(j, j - 1, root); // uses the root as an argument so that the swap function can make use of it, since it's not a class method declared in the header
			--j; // decrements j by 1 so the while condition is checked again against the previous values; will go on until j = 0 then i in the outer loop is incremented by 1 and the process starts over
		}
	}
}


bool LinkedList::bubbleSort()
{
	int len = this->getSize();
	for (int i = 0; i < len - 1; i++) // nested for loop; after the first iteration of the outer loop, the largest value will be at the end and by the second iteration the second largest value will be at the end - 1 etc.
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (this->getItem(j+1) < this->getItem(j)) // compares two adjacent nodes' items and performs a swap if the latter is smaller than the former
			{
				swap(j+1, j, root);
			}
		}
	}
	// Return true if this has been implemented. If not, leave as is. 
	// The returned value is only used to simplify grading. 
	return true;
}


