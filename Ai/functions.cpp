#include <iostream>
#include <vector>
#include "includes.h"
using namespace std;
void acquirelinks(vector<link>&links)
{
	char c1, c2;
	float linkCost;
	char key = 'k';
	while (key != 'q')
	{
		cout << "please enter the start city and the goal city and the cost as this i.g (a b 3)" << endl;
		cin >> c1 >> c2 >> linkCost;
		links.push_back(link(c1, c2, linkCost));
		cout << "if u want to proccess on enter any key" << endl;
		cout << "if u want to end press q" << endl;
		cin >> key;
	}
}

