#include "includes.h"
#include <vector>
#ifndef node_H_
#define node_H_
class node
{
public:
	node();
	~node();
	char getName();
	float getCost();
	bool getExplored();
	node* getpParent();
	node* getpNext();
	void setpParent(node* pParent);
	void setExplored(bool explored);
	void setpNext(node* pNext);
	void setName(char name);
	void setCost(float cost);
	node& operator=(const node& right);
	bool isGoal(char goalCity);
	node(char name, node* pParent, node* pNext, float cost, bool explored);
	void expand(vector<link> &links, list* pFrontier);
	void pushNodeToList(list* pFrontier);
	bool isQualified(list* pFrontier);
private:
	char name;
	node* pParent;
	node* pNext;
	float cost;
	bool explored;
};
#endif // node_H_
