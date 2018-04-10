#include <fstream>
#include <iostream>
#include "includes.h"
using namespace std;
int main()
{
	char key = 'k';

	fstream file;

	char startCity, goalCity;

	node* pCurrentNode = new node();
	list* pFrontier = new list(NULL, NULL);
	vector<link> inputs;
	acquirelinks(inputs);
	cout << inputs.size() << endl;
	for (int i = 0; i < inputs.size(); i++)
	{
		cout << inputs[i].getC1() << "\t" << inputs[i].getC2() << "\t" << inputs[i].getLinkCost() << endl;
	}
	cout << "please enter the start city and goal city" << endl;
	cin >> startCity >> goalCity;
	pCurrentNode = new node(startCity, NULL, NULL, 0.0, false);
	pFrontier->setpFirstNode(pCurrentNode);

	pFrontier->setpLastNode(pCurrentNode);

	int choose;
	cout << "please enter the number of your choose to use the algorithm" << endl;

	cout << "choose 1 is Breadth first search" << endl;

	cout << "choose 2 is Deapth first search" << endl;

	cout << "choose 3 is uniCost search" << endl;

	//cout << "choose 4 is heuristic search" << endl;
	//cout << "choose 5 is A star search" << endl;
	cin >> choose;

	switch (choose)

	{
	case 1:
		while (!pCurrentNode->isGoal(goalCity))
		{
			pCurrentNode->setExplored(true);
			pCurrentNode->expand(inputs, pFrontier);
			pCurrentNode = pCurrentNode->getpNext();
		}
		break;
	case 2:
	{
		char name;
		name = '$';
		pCurrentNode = pFrontier->getpFirstNode();
		while (!pCurrentNode->isGoal(goalCity))
		{
			node* temp = pFrontier->getpFirstNode();
			while (temp != NULL)
			{
				if (temp->getpParent() == pCurrentNode && temp->getName() != name)
				{
					pCurrentNode = temp;
					temp->setpNext(NULL);
					pFrontier->setpLastNode(temp);
					break;
				}
				if (temp->getpNext() == NULL && temp->getName() != 'a')
				{
					name = pCurrentNode->getName();
					pCurrentNode = pCurrentNode->getpParent();
					break;
				}
				temp = temp->getpNext();
			}
			pCurrentNode->setExplored(true);
			pCurrentNode->expand(inputs, pFrontier);
		}
	}
	cout << "the node that poshed to list is :" << endl;
	pFrontier->printList();
	cout << "Done" << endl;
	cout << " final Bath is :" << endl;
	if (pCurrentNode->isGoal(goalCity))
	{
		pCurrentNode->setExplored(true);
		pFrontier->printResult();
		cout << startCity << "\t" << goalCity << "\t" << pCurrentNode->getCost() << endl;
	}

	}

}

