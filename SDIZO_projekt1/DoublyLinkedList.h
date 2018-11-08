#include<string>

using namespace std;

struct dListElement
{
	dListElement * next;
	dListElement * prev;
	int  data;
};

class DoublyLinkedList
{
public:
	dListElement * head;
	dListElement * tail;
	unsigned size;

	DoublyLinkedList();
	~DoublyLinkedList();
	void print();
	void addToBegining(int value);
	void addToEnd(int value);
	//void insertBefore(dListElement * elem, int value);
	void addAfterPos(int elem, int value);
	void remove(int value);
	void removeFront();
	void removeBack();
	dListElement * find(int value);
	void FromFile(string name, int dzialanie);
};

