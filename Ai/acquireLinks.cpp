#include <iostream>
#include <fstream>
#include <vector>
#include "includes.h"
using namespace std;

void acquirelinks(vector<link>&links)
{
	char c1, c2;
	float linkCost;
	fstream file;
	file.open("file.txt");
	while (!file.eof())
	{
		file >> c1 >> c2 >> linkCost;
		links.push_back(link(c1, c2, linkCost));
	}
	file.close();
}
