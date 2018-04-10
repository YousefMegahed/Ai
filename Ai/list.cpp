#include <iostream>
#include "includes.h"
using namespace std;
list::list()
{

}
list::~list()
{
	//delete pFirstNode;
	//delete pLastNode;
}

void list::setpFirstNode(node* pFirstNode)
{
	this->pFirstNode = pFirstNode;
}
void list::setpLastNode(node* pLastNode)
{
	this->pLastNode = pLastNode;
}
node* list::getpFirstNode()
{
	return this->pFirstNode;
}
node* list::getpLastNode()
{
	return  this->pLastNode;
}
list::list(node* pFirstNode, node* pLastNode) :
	pFirstNode(pFirstNode), pLastNode(pLastNode)
{

}
list& list::operator=(const list& right)
{
	if (this == &right)
	{
		return *this;
	}
	return *this;
}
void list::printList(void)
{
	cout << "Name" << "\t" << "ParentName" << "\t" << "Cost" << endl;
	node* pCurrentName = this->getpFirstNode()->getpNext();

	while (pCurrentName != NULL)
	{
		cout << pCurrentName->getName() << "\t " << pCurrentName->getpParent()->getName() << "\t " << "\t" << pCurrentName->getCost() << endl;
		pCurrentName = pCurrentName->getpNext();
	}
}
void list::printResult(void)
{
	node* previous;
	int counter = 0;
	node*pCurrentNode = this->getpFirstNode();
	previous = pCurrentNode;
	while (pCurrentNode != NULL)
	{
		if (pCurrentNode->getExplored())
		{
			cout << pCurrentNode->getName() << endl;
			if (previous->getpParent() != pCurrentNode->getpParent())
			{
				counter++;
			}
		}
		previous = pCurrentNode;
		pCurrentNode = pCurrentNode->getpNext();
	}
	cout << "number of Expanded" << endl;
	cout << counter << endl;
}