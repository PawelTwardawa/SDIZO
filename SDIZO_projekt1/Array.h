#include<iostream>
#include <string>

using namespace std;
class Array
{
public:
	Array();
	~Array();
	
	void AddToEnd(int value);
	void AddToBegining(int value);
	void AddToPos(int value, int pos);
	void RemoveFromEnd();
	void RemoveFromBegining();
	void RemoveFromPos(int pos);
	bool Find(int value);
	void Print();
	void FromFile(int * tab, int dzialanie);
	int getSize();
private:
	void AddToEndResize();
	void AddToBeginingResize();
	void AddToRandPosResize(int pos);
	int * array;
	int * tmp;
	int  size;
	

};

