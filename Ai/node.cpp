#include <iostream>
#include "includes.h"
#include <vector>
using namespace std;
node::node(char name, node* pParent, node* pNext, float cost, bool explored) :
	name(name), pParent(pParent), pNext(pNext), cost(cost), explored(explored)
{

}
node::node()
{

}
node::~node()
{
	delete pParent;
	delete pNext;
}
char node::getName()
{
	return this->name;
}
float node::getCost()
{
	return this->cost;
}
bool node::getExplored()
{
	return this->explored;
}
node* node::getpParent()
{
	return this->pParent;
}
node* node::getpNext()
{
	return this->pNext;
}
void node::setCost(float cost)
{
	this->cost = cost;
}
void node::setExplored(bool explored)
{
	this->explored = explored;
}
void node::setpNext(node* pNext)
{
	this->pNext = pNext;
}
void node::setpParent(node* pParent)
{
	this->pParent = pParent;
}
void node::setName(char name)
{
	this->name = name;
}
node& node::operator=(const node& right)
{
	if (this == &right)
	{
		return *this;
	}
	return *this;
}
bool node::isGoal(char goalCity)
{
	if (this->name == goalCity)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void node::expand(vector<link> &links, list* pFrontier)
{
	node* tempNode;
	bool found = false;
	for (int i = 0; i <links.size(); i++)
	{
		bool found = false;
		tempNode = NULL;
		if (this->getName() == links[i].getC1())
		{
			found = true;
			tempNode = new node(links[i].getC2(), this, NULL, links[i].getLinkCost() + cost, false);
		}
		else if (this->getName() == links[i].getC2())
		{
			found = true;
			tempNode = new node(links[i].getC1(), this, NULL, links[i].getLinkCost() + cost, false);
		}
		if (found == true)
		{
			if (tempNode->isQualified(pFrontier))
			{
				tempNode->pushNodeToList(pFrontier);
			}
		}
	}
}
void node::pushNodeToList(list* pFrontier)
{
	pFrontier->getpLastNode()->pNext = this;
	pFrontier->setpLastNode(this);
}
bool node::isQualified(list* pFrontier)
{
	node* temp = new node();
	node* previous = new node();
	temp = pFrontier->getpFirstNode();
	while (temp != NULL)
	{
		if (temp->name == this->name)
		{
			if (this->cost < temp->cost)
			{
				previous->pNext = this;
				this->pNext = temp->pNext;
			}
			else if (temp->pNext == pFrontier->getpLastNode())
			{
				temp = temp->pNext;
			}
			return false;
		}
		else
		{
			previous = temp;
			if (temp->pNext == NULL)
			{
				break;
			}
			temp = temp->pNext;
		}
	}
	return true;
}


