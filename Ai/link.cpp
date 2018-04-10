#include "includes.h"
#include "link.h"
using namespace std;

link::link(char c1, char c2, float linkCost) : c1(c1), c2(c2), linkCost(linkCost)
{


}
char link::getC1()
{
	return this->c1;
}
char link::getC2()
{
	return this->c2;
}
float link::getLinkCost()
{
	return this->linkCost;
}

void link::setLinkCost(float linkCost)
{
	this->linkCost = linkCost;
}
void link::setc1(char c1)
{
	this->c1 = c1;
}
void link::setc2(char c2)
{
	this->c2 = c2;
}

link& link::operator=(const link& right)
{
	if (this == &right)
	{
		return *this;
	}
	return *this;
}
link::link()
{

}
link::~link()
{

}
