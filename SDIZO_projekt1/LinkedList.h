#pragma once
#include<string>

using namespace std;

struct  listElement
{
	listElement * next;
	int data;
};

class LinkedList
{
public:
	listElement * head;

	LinkedList();
	~LinkedList();

	unsigned size();
	void print();
	void addToBegining(int value);
	void addToEnd(int value);
	void addAfterPos(int elem, int value);
	void removeFront();
	void removeBack();
	void remove(int value);
	listElement * find(int value);
	void FromFile(int * tab, int dzialanie );
};