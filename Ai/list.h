#include "includes.h"
#ifndef List_H_
#define List_H_
class list
{
public:
	list();
	~list();
	node* getpFirstNode();
	node* getpLastNode();
	void setpFirstNode(node* pFirstNode);
	void setpLastNode(node* pLastNode);
	list(node *pFirstNode, node *PLastNode);
	list& operator=(const list& right);
	void printList(void);
	void printResult(void);
private:
	node* pFirstNode;
	node* pLastNode;
};

#endif // !List_H_

