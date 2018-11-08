#include "LinkedList.h"
#include<iostream>
#include <fstream>

using namespace std;


LinkedList::LinkedList()
{
	head = NULL;
}


LinkedList::~LinkedList()
{
}

unsigned LinkedList::size() // zwraca rozmiar tablicy
{
	unsigned size = 0;
	listElement * current  = head;
	while (current) //dopoki current->next nie jest nullem
	{
		size++;
		current = current->next;
	}
	return size;
}

void LinkedList::print()
{
	unsigned i;
	listElement * current = head;

	for (i = 1; current; current = current->next)
	{
		cout << "Element: " << i++ << "  data = " << current->data << endl;
	}
	cout << endl;
}

void LinkedList::addToBegining(int value)
{
	listElement * current;

	current = new listElement; //stworzenie noewgo elementu listy
	current->next = head; //przypisanie obecnego head jako nastepny element listy
	current->data = value;
	head = current; // przypisanie nowo stworzonego elementu jako head
}

void LinkedList::addToEnd(int value)
{
	listElement * current, *newEl;

	newEl = new listElement;  // tworzymy nowy element
	newEl->next = NULL;   // przypisanie do nastepnego elementu null, co znaczy ze bedzie ogonem
	newEl->data = value;
	current = head;
	if (current) //jezeli head istnieje
	{
		while (current->next) // szukanie osotatniego elementu listy
		{
			current = current->next;
		}
		current->next = newEl; //dodanie nowego elementu do listy
	}
	else
	{
		head = newEl;
	}
}

void LinkedList::addAfterPos(int elem, int value) // dodawnie po konkretnym elemencie 
{

	listElement * current = new listElement;
	listElement * findElem = find(elem);

	if (findElem == NULL) // jezeli element nie istnieje, nowy element zostanie dodany na poczatek
	{
		addToBegining(value);
	}
	else
	{
		current->next = findElem->next;
		current->data = value;
		findElem->next = current;
	}

	
}

void LinkedList::removeFront()
{
	listElement * current = head; 

	if (current)
	{
		head = current->next;  // przypisanie do glowy drugiego elementu listy
		delete current; //usuniecie pierwszego elementu listy
	}
}

void LinkedList::removeBack()
{
	listElement * current = head; // zapamiêtujemy pocz¹tek

	if (current)
	{
		if (current->next)//jezeli nastepny element istnieje
		{
			while (current->next->next) // szukanie ostatniego elementu listy
			{
				current = current->next;
			}
			delete current->next;
			current->next = NULL;
		}
		else //jezeli lista posiada tylko jeden element
		{
			delete current;
			head = NULL;
		}
	}
}

void LinkedList::remove(int value)
{
	listElement * current, * elem;
	elem = find(value); //szukanie elementu zawierajacego podana wartosc

	if (elem != NULL)
	{
		if (head == elem) // jezeli szukana wartosc jest w pierszym elemencie
		{
			removeFront();
		}
		else
		{
			current = head;
			while (current->next != elem) //szukanie dopoki nastepny element listy jest rozny elementowi zawierajacego podana wartosc
			{
				current = current->next;
			}
			current->next = elem->next;
			delete elem;
		}
	}
}

listElement * LinkedList::find(int value)
{
	listElement * current = head;
	while (current && current->data != value) // dopoki nie jest null i data nie jest rowna szukanej wartosci
	{
		current = current->next;
	}
	return current;
}

void LinkedList::FromFile(int * tab, int dzialanie)
{	
	int sizeFile;

	sizeFile = tab[0];

	for (int i = 1; i <= sizeFile; i++)
	{
		if (dzialanie == 0)
		{
			addToBegining(tab[i]);
		}
		if (dzialanie == 1)
		{
			addToEnd(tab[i]);
		}
		if (dzialanie == 2)
		{
			int rand = 0;
			if (size() != 0)
			{
				rand = (std::rand() % size());
			}

			addAfterPos(tab[i], rand);
		}


	}


}
