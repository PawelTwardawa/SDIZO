#include "DoublyLinkedList.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}


DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::print()
{
	int i = 0;
	dListElement * current;

	current = head;
	while (current)
	{
		cout << "Element: " << i++ << " " << current->data << endl;
		current = current->next;
	}
}

void DoublyLinkedList::addToBegining(int value)
{
	dListElement * current;

	current = new dListElement;
	current->data = value;
	current->prev = NULL;
	current->next = head;
	head = current;
	size++;
	if (current->next)
	{
		current->next->prev = current;
	}
	else
	{
		tail = current;
	}
}

void DoublyLinkedList::addToEnd(int value)
{
	dListElement * current;

	current = new dListElement;
	current->data = value;
	current->next = NULL;
	current->prev = tail;
	tail = current;
	size++;
	if (current->prev)
	{
		current->prev->next = current;
	}
	else
	{
		head = current;
	}
}

void DoublyLinkedList::addAfterPos(int elem, int value)
{
	dListElement * current;
	dListElement * findElem = find(elem);

	if (findElem == NULL)
	{
		addToBegining(value);
	}
	else
	{



		if (findElem == tail)
		{
			addToEnd(value);
		}
		else
		{
			current = new dListElement;
			current->data = value;
			current->next = findElem->next;
			current->prev = findElem;
			size++;
			findElem->next->prev = current;
			findElem->next = current;
		}
	}
}

void DoublyLinkedList::remove(int  value)
{
	dListElement * elem;
	elem = find(value);

	if (elem != NULL)
	{

		if (elem->prev)
		{
			elem->prev->next = elem->next;
		}
		else
		{
			head = elem->next;
		}

		if (elem->next)
		{
			elem->next->prev = elem->prev;
		}
		else
		{
			tail = elem->prev;
		}
		size--;
		delete elem;
	}
}

void DoublyLinkedList::removeFront()
{
	if (size != 0)
	{
		remove(head->data);
	}
}

void DoublyLinkedList::removeBack()
{
	if (size != 0)
	{
		remove(tail->data);
	}
}

dListElement * DoublyLinkedList::find(int value) // wyszukiwanie z wartownikiem
{
	dListElement * current;
	addToEnd(value);
	current = head;
	while (current->data != value)
	{
		current = current->next;
	}
	if (current == tail)
	{
		current = NULL;
	}
	removeBack();
	return current;
}

void DoublyLinkedList::FromFile(string name, int dzialanie)
{
	int sizeFile;
	int value;
	std::fstream plik;
	plik.open(name, std::ios::in);
	if (plik.good() == true)
	{
		plik >> sizeFile;

		for (int i = 0; i < sizeFile; i++)
		{
			plik >> value;
			if (dzialanie == 0)
			{
				addToBegining(value);
			}
			if (dzialanie == 1)
			{
				addToEnd(value);
			}
			if (dzialanie == 2)
			{
				int rand = 0;
				if (size != 0)
				{
					rand = (std::rand() % size);
				}
				addAfterPos(rand, value);
			}


		}
		plik.close();

	}
}

