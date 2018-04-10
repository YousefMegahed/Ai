#ifndef link_H_
#define	link_H_
class link
{
public:
	link();
	~link();
	char getC1();
	char getC2();
	float getLinkCost();
	void setc1(char c1);
	void setc2(char c2);
	void setLinkCost(float linkCost);
	link& operator=(const link& right);
	link(char c1, char c2, float linkCost);
private:
	char c1;
	char c2;
	float linkCost;
};

#endif //! link_H_
