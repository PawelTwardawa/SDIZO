#include<iostream>
#include<cstdlib>
#include<ctime>
#include <fstream>
#include <Windows.h>
#include <iomanip>

#include "Array.h"
#include "PerformanceCounter.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Heap.h"
#include "RedBlackTree.h"

using namespace std;

void menu(Array * array, LinkedList * linkedList, DoublyLinkedList * doubluLinkedList, Heap * heap, RedBlackTree * redBlackTree);
void menuArray(Array * array);
void menuArrayAdd(Array * array);
void menuArrayRemove(Array * array);
void AddToArrayEnd(Array * array);
void AddToArrayBegining(Array * array);
void AddToArrayRandPos(Array * array);
void menuLinkedList(LinkedList * linkedList);
void menuLinkedListRemove(LinkedList * linkedList);
void menuLinkedListAdd(LinkedList * linkedList);
void AddToLinedListEnd(LinkedList * linkedList);
void AddToLinkedListBegining(LinkedList * linkedList);
void AddToLinkedListPos(LinkedList * linkedList);
int menuFromFile();
void menuHeap(Heap * heap);
void menuRBTree(RedBlackTree * RBT);
void menuDLinkedList(DoublyLinkedList * linkedList);
void menuDLinkedListRemove(DoublyLinkedList * linkedList);
void menuDLinkedListAdd(DoublyLinkedList * linkedList);
void AddToDLinkedListEnd(DoublyLinkedList * linkedList);
void AddToDLinkedListBegining(DoublyLinkedList * linkedList);
void AddToDLinkedListPos(DoublyLinkedList * linkedList);
void menuListType(LinkedList * linkedList, DoublyLinkedList * dLinkedList);
int * readFromFile(string name);

int m = 30;



int findValue()
{
	int value;
	cout << "Podaj szukana wartosc: ";
	cin >> value;
	cout << endl;
	return value;
	
}

void menu(Array * array, LinkedList * linkedList, DoublyLinkedList * doubluLinkedList, Heap * heap, RedBlackTree * redBlackTree)
{
	while (true)
	{


		int no;
		//system("cls");
		cout << "[0] Tablica" << endl;
		cout << "[1] Lista" << endl;
		cout << "[2] Kopiec binarny" << endl;
		cout << "[3] Drzewo czerwono-czarne" << endl;
		cout << "[4] Wyjdz" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			menuArray(array);
			break;
		case 1:
			menuLinkedList(linkedList);
			//menuListType(linkedList, doubluLinkedList);
			break;
		case 2:
			menuHeap(heap);
			break;
		case 3:
			menuRBTree(redBlackTree);
			break;
		case 4:
			exit(0);
			break;
		}
	}
}

void menuListType(LinkedList * linkedList, DoublyLinkedList * dLinkedList)
{
	while (true)
	{
		int no;
		//system("cls");
		cout << "[0] Lista jednokierunkowa" << endl;
		cout << "[1] Lista dwukierunkowa" << endl;
		cout << "[2] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			menuLinkedList(linkedList);
			break;
		case 1:
			menuDLinkedList(dLinkedList);
			break;
		case 2:
			return;
			break;
		}
	}
}


//Array
void menuArray(Array * array)
{
	int value;
	bool find;
	int menu;
	int * tab;
	PerformanceCounter counter;
	while (true)
	{
		int no;
		//system("cls");
		cout << "[0] Zbuduj z pliku" << endl;
		cout << "[1] Usun" << endl;
		cout << "[2] Dodaj" << endl;
		cout << "[3] Znajdz" << endl;
		cout << "[4] Wyswietl" << endl;
		cout << "[5] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;
		
		switch (no)
		{
		case 0:
			menu = menuFromFile();
			tab = readFromFile("dane.txt");

			counter.startTimer();
			//for (int i = 0; i < 100; i++)
			//{
				array->FromFile(tab, menu);
			//}

			cout << "time: " << counter.endTimer()/m << endl;
			
			break;
		case 1:
			menuArrayRemove(array);
			break;
		case 2:
			menuArrayAdd(array);
			break;
		case 3:
			value = findValue();

			
			counter.startTimer();
			for (int i = 0; i < m; i++)
			{
				find = array->Find(value);
			}

			cout << "time: " << counter.endTimer() / m << endl;
			if (find)
			{
				cout << "znaleziono" << endl;
			}
			else
			{
				cout << "nie znaleziono" << endl;
			}
			break;
		case 4:
			array->Print();
		case 5:
			return;
			break;
		}
	}
}

void menuArrayRemove(Array * array)
{
	PerformanceCounter counter;
	while (true)
	{

		int no, randPos;
		//system("cls");
		cout << "[0] Usun z poczatku" << endl;
		cout << "[1] Usun z konca" << endl;
		cout << "[2] Usun z losowych pozycji " << endl;
		cout << "[3] Usun z pozycji " << endl;
		cout << "[4] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			

			counter.startTimer();
			//for (int i = 0; i < m; i++)
			//{
				array->RemoveFromBegining();
			//}

			cout << "time: " << counter.endTimer()  << endl;
			
			break;
		case 1:
			counter.startTimer();
			//for (int i = 0; i < m; i++)
			//{
				array->RemoveFromEnd();
			//}

			cout << "time: " << counter.endTimer() << endl;
			
			break;
		case 2:

			if (array->getSize() != 0)
			{
				randPos = rand() % array->getSize();
			}
			else
			{
				randPos = 0;
			}

			counter.startTimer();
			//for (int i = 0; i < m; i++)
			//{
				array->RemoveFromPos(randPos);
			//}

			cout << "time: " << counter.endTimer()  << endl;
			break;
		case 3:
			int pos;
			cout << "podaj pozycje do usuniecia: ";
			cin >> pos;

			array->RemoveFromPos(pos);
			break;
		case 4:
			return;
			break;
		}
	}
}

//Array Add
void menuArrayAdd(Array * array)
{
	while (true)
	{

		int no;
		//system("cls");
		cout << "[0] Dodaj na poczatek" << endl;
		cout << "[1] Dodaj na koniec" << endl;
		cout << "[2] Dodaj na losowa pozycje" << endl;
		cout << "[3] Dodaj na pozycje" << endl;
		cout << "[4] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			AddToArrayBegining(array);
			break;
		case 1:
			AddToArrayEnd(array);
			break;
		case 2:
			AddToArrayRandPos(array);
			break;
		case 3:
			int pos;
			int value;
			cout << "Podaj pozycje do dodania: ";
			cin >> pos;
			if (pos <= array->getSize())
			{
				cout << "podaj wartosc: ";
				cin >> value;
				array->AddToPos(value, pos);
			}
			else
			{
				cout << "pozycja przekroczyla rozmiar tablicy" << endl;
			}
			break;
		case 4:
			return;
			break;

		}
	}
}

void AddToArrayEnd(Array * array)
{
	PerformanceCounter counter;
	int size, value;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;

		counter.startTimer();
		//for (int i = 0; i < m; i++)
		//{
			array->AddToEnd(value);
		//}

		cout << "time: " << counter.endTimer() << endl;
	}
}

void AddToArrayBegining(Array  * array)
{
	PerformanceCounter counter;
	int size, value;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;
		counter.startTimer();
		//for (int i = 0; i < m; i++)
		//{
			array->AddToBegining(value);
		//}

		cout << "time: " << counter.endTimer()  << endl;
	}
}

void AddToArrayRandPos(Array * array)
{
	PerformanceCounter counter;
	int size, value, randPos;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		if (array->getSize() != 0)
		{
			randPos = rand() % array->getSize();
		}
		else
		{
			randPos = 0;
		}
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;

		counter.startTimer();
		//for (int i = 0; i < m; i++)
		//{
			array->AddToPos(value, randPos);
		//}

		cout << "time: " << counter.endTimer()  << endl;
	}
}

//Linked List

void menuLinkedList(LinkedList * linkedList)
{
	int value;
	bool find;
	int menu;
	int * tab;
	PerformanceCounter counter;
	while (true)
	{
		int no;
		//system("cls");
		cout << "[0] Zbuduj z pliku" << endl;
		cout << "[1] Usun" << endl;
		cout << "[2] Dodaj" << endl;
		cout << "[3] Znajdz" << endl;
		cout << "[4] Wyswietl" << endl;
		cout << "[5] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			menu = menuFromFile();
			tab = readFromFile("dane.txt");

			counter.startTimer();

			linkedList->FromFile(tab, menu);
			cout << "time: " << counter.endTimer() / m << endl;

			break;
		case 1:
			menuLinkedListRemove(linkedList);
			break;
		case 2:
			menuLinkedListAdd(linkedList);
			break;
		case 3:
			value = findValue();
			counter.startTimer();
			for (int i = 0; i < m; i++)
			{
				find = linkedList->find(value);
			}

			cout << "time: " << counter.endTimer() / m << endl;
			
			if (find)
			{
				cout << "znaleziono" << endl;
			}
			else
			{
				cout << "nie znaleziono" << endl;
			}
			break;
		case 4:
			linkedList->print();
		case 5:
			return;
			break;
		}
	}
}

void menuLinkedListRemove(LinkedList * linkedList)
{
	PerformanceCounter counter;
	while (true)
	{

		int no;
		//system("cls");
		cout << "[0] Usun z poczatku" << endl;
		cout << "[1] Usun z konca" << endl;
		cout << "[2] Usun z pozycji " << endl;
		cout << "[3] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			counter.startTimer();
			//for (int i = 0; i < m; i++)
			//{
				linkedList->removeFront();
			//}

			cout << "time: " << counter.endTimer() << endl;
			
			break;
		case 1:
			
			counter.startTimer();
			//for (int i = 0; i < m; i++)
			//{
				linkedList->removeBack();
			//}

			cout << "time: " << counter.endTimer() << endl;
			break;
		case 2:
			int value;
			cout << "podaj wartosc do usuniecia: ";
			cin >> value;

			counter.startTimer();
			//for (int i = 0; i < m; i++)
			//{
				linkedList->remove(value);
			//}

			cout << "time: " << counter.endTimer()  << endl;
			
			break;
		case 3:
			return;
			break;
		}
	}
}

void menuLinkedListAdd(LinkedList * linkedList)
{
	PerformanceCounter counter;
	int randPos;
	while (true)
	{

		int no;
		//system("cls");
		cout << "[0] Dodaj na poczatek" << endl;
		cout << "[1] Dodaj na koniec" << endl;
		cout << "[2] Dodaj na losowa pozycje" << endl;
		cout << "[3] Dodaj na pozycje" << endl;
		cout << "[4] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			AddToLinkedListBegining(linkedList);
			break;
		case 1:
			AddToLinedListEnd(linkedList);
			break;
		case 2:
			int value1;
			if (linkedList->size() != 0)
			{
				randPos = rand() % linkedList->size();
			}
			else
			{
				randPos = 0;
			}
			cout << "podaj wartosc: ";
			cin >> value1;
			counter.startTimer();
			//for (int i = 0; i < m; i++)
			//{
				linkedList->addAfterPos(randPos, value1);
			//}

			cout << "time: " << counter.endTimer() << endl;
			break;
		case 3:
			unsigned pos;
			int value;
			cout << "Podaj pozycje do dodania: ";
			cin >> pos;
			if (pos <= linkedList->size())
			{
				cout << "podaj wartosc: ";
				cin >> value;
				linkedList->addAfterPos(pos, value);
			}
			else
			{
				cout << "pozycja przekroczyla rozmiar tablicy" << endl;
			}
			break;
		case 4:
			return;
			break;

		}
	}
}

void AddToLinedListEnd(LinkedList * linkedList)
{
	PerformanceCounter counter;
	int size, value;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;
		counter.startTimer();
		//for (int i = 0; i < m; i++)
		//{
			linkedList->addToEnd(value);
		//}

		cout << "time: " << counter.endTimer()  << endl;
		
	}
}

void AddToLinkedListBegining(LinkedList * linkedList)
{
	PerformanceCounter counter;
	int size, value;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;
		counter.startTimer();
		//for (int i = 0; i < m; i++)
		//{
			linkedList->addToBegining(value);
		//}

		cout << "time: " << counter.endTimer() << endl;
		
	}
}

void AddToLinkedListPos(LinkedList * linkedList)
{
	PerformanceCounter counter;
	int size, value, pos;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;
		cout << "pozycja: ";
		cin >> pos;
		counter.startTimer();
		//for (int i = 0; i < m; i++)
		//{
			linkedList->addAfterPos(pos, value);
		//}

		cout << "time: " << counter.endTimer()  << endl;
		
	}
}

//double linked list

void menuDLinkedList(DoublyLinkedList * linkedList)
{
	PerformanceCounter counter;
	int value;
	bool find;
	while (true)
	{
		int no;
		//system("cls");
		cout << "[0] Zbuduj z pliku" << endl;
		cout << "[1] Usun" << endl;
		cout << "[2] Dodaj" << endl;
		cout << "[3] Znajdz" << endl;
		cout << "[4] Wyswietl" << endl;
		cout << "[5] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:

			linkedList->FromFile("dane.txt", menuFromFile());
			break;
		case 1:
			menuDLinkedListRemove(linkedList);
			break;
		case 2:
			menuDLinkedListAdd(linkedList);
			break;
		case 3:
			value = findValue();
			counter.startTimer();
			for (int i = 0; i < 100; i++)
			{
				find = linkedList->find(value);
			}

			cout << "time: " << counter.endTimer() / 100 << endl;

			if (find)
			{
				cout << "znaleziono" << endl;
			}
			else
			{
				cout << "nie znaleziono" << endl;
			}
			break;
		case 4:
			linkedList->print();
		case 5:
			return;
			break;
		}
	}
}

void menuDLinkedListRemove(DoublyLinkedList * linkedList)
{
	PerformanceCounter counter;
	while (true)
	{

		int no;
		//system("cls");
		cout << "[0] Usun z poczatku" << endl;
		cout << "[1] Usun z konca" << endl;
		cout << "[2] Usun z pozycji " << endl;
		cout << "[3] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			counter.startTimer();
			for (int i = 0; i < 100; i++)
			{
				linkedList->removeFront();
			}

			cout << "time: " << counter.endTimer() / 100 << endl;

			break;
		case 1:

			counter.startTimer();
			for (int i = 0; i < 100; i++)
			{
				linkedList->removeBack();
			}

			cout << "time: " << counter.endTimer() / 100 << endl;
			break;
		case 2:
			int value;
			cout << "podaj wartosc do usuniecia: ";
			cin >> value;

			counter.startTimer();
			for (int i = 0; i < 100; i++)
			{
				linkedList->remove(value);
			}

			cout << "time: " << counter.endTimer() / 100 << endl;

			break;
		case 3:
			return;
			break;
		}
	}
}

void menuDLinkedListAdd(DoublyLinkedList * linkedList)
{
	PerformanceCounter counter;
	int randPos;
	while (true)
	{

		int no;
		//system("cls");
		cout << "[0] Dodaj na poczatek" << endl;
		cout << "[1] Dodaj na koniec" << endl;
		cout << "[2] Dodaj na losowa pozycje" << endl;
		cout << "[3] Dodaj na pozycje" << endl;
		cout << "[4] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			AddToDLinkedListBegining(linkedList);
			break;
		case 1:
			AddToDLinkedListEnd(linkedList);
			break;
		case 2:
			int value1;
			if (linkedList->size != 0)
			{
				randPos = rand() % linkedList->size;
			}
			else
			{
				randPos = 0;
			}
			cout << "podaj wartosc: ";
			cin >> value1;
			counter.startTimer();
			//for (int i = 0; i < 100; i++)
			//{
				linkedList->addAfterPos(randPos, value1);
			//}

			cout << "time: " << counter.endTimer() / 100 << endl;
			break;
		case 3:
			unsigned pos;
			int value;
			cout << "Podaj pozycje do dodania: ";
			cin >> pos;
			if (pos <= linkedList->size)
			{
				cout << "podaj wartosc: ";
				cin >> value;
				linkedList->addAfterPos(pos, value);
			}
			else
			{
				cout << "pozycja przekroczyla rozmiar tablicy" << endl;
			}
			break;
		case 4:
			return;
			break;

		}
	}
}

void AddToDLinkedListEnd(DoublyLinkedList * linkedList)
{
	PerformanceCounter counter;
	int size, value;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;
		counter.startTimer();
		for (int i = 0; i < 100; i++)
		{
			linkedList->addToEnd(value);
		}

		cout << "time: " << counter.endTimer() / 100 << endl;

	}
}

void AddToDLinkedListBegining(DoublyLinkedList * linkedList)
{
	PerformanceCounter counter;
	int size, value;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;
		counter.startTimer();
		for (int i = 0; i < 100; i++)
		{
			linkedList->addToBegining(value);
		}

		cout << "time: " << counter.endTimer() / 100 << endl;

	}
}

void AddToDLinkedListPos(DoublyLinkedList * linkedList)
{
	PerformanceCounter counter;
	int size, value, pos;
	cout << "podaj ile liczb chcesz wprowadzic: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe: ";
		cin >> value;
		cout << "pozycja: ";
		cin >> pos;
		counter.startTimer();
		for (int i = 0; i < 100; i++)
		{
			linkedList->addAfterPos(pos, value);
		}

		cout << "time: " << counter.endTimer() / 100 << endl;

	}
}

//Heap

void menuHeap(Heap * heap)
{
	PerformanceCounter counter;
	int * tab;
	while (true)
	{
		int no;
		//system("cls");
		cout << "[0] Zbuduj z pliku" << endl;
		cout << "[1] Usun korzen" << endl;
		cout << "[2] Dodaj" << endl;
		cout << "[3] Znajdz" << endl;
		cout << "[4] Wyswietl" << endl;

		cout << "[5] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:

			tab = readFromFile("dane.txt");

			counter.startTimer();

			heap->FromFile(tab);
			cout << "time: " << counter.endTimer() / m << endl;
			break;
		case 1:
			counter.startTimer();
			//for (int i = 0; i < 1; i++)
			//{
				heap->removeRoot();
			//}

			cout << "time: " << counter.endTimer()  << endl;
			
			break;
		case 2:
			int size, value;
			cout << "podaj ile liczb chcesz wprowadzic: ";
			cin >> size;

			for (int i = 0; i < size; i++)
			{
				cout << "Podaj " << i + 1 << " liczbe: ";
				cin >> value;
				counter.startTimer();
				//for (int i = 0; i < m; i++)
				//{
					heap->add(value);
				//}

				cout << "time: " << counter.endTimer()  << endl;
				
			}
			break;
		case 3:
			//bool find;
			int find;
			value = findValue();
			counter.startTimer();
			for (int i = 0; i < m; i++)
			{
				find = heap->find(1, value);
			}
			cout.setf(ios::fixed);
			cout << "time: " << counter.endTimer() / m << endl;

			if (find != -1)
			{
				cout << "znaleziono" << endl;
			}
			else
			{
				cout << "nie znaleziono" << endl;
			}
			break;
		case 4:
			heap->print();


		case 5:
			return;
			break;
		}
	}
}

//Red Black Tree

void menuRBTree(RedBlackTree * RBT)
{
	PerformanceCounter counter;
	int * tab;
	while (true)
	{
		int no;
		//system("cls");
		cout << "[0] Zbuduj z pliku" << endl;
		cout << "[1] Usun" << endl;
		cout << "[2] Dodaj" << endl;
		cout << "[3] Znajdz" << endl;
		cout << "[4] Wyswietl" << endl;
		cout << "[5] Wroc" << endl;
		cout << endl;
		cout << "nr menu: ";
		cin >> no;

		switch (no)
		{
		case 0:
			tab = readFromFile("dane.txt");

			counter.startTimer();

			RBT->FromFile(tab);
			cout << "time: " << counter.endTimer() / m << endl;
			break;
		case 1:
			int value;
			cout << "podaj wartosc do usuniecia: ";
			cin >> value;
			counter.startTimer();
			//for (int i = 0; i < m; i++)
			//{
				RBT->remove(value);
			//}

			cout << "time: " << counter.endTimer()  << endl;
			
			break;
		case 2:
			int size, val;
			cout << "podaj ile liczb chcesz wprowadzic: ";
			cin >> size;

			for (int i = 0; i < size; i++)
			{
				cout << "Podaj " << i + 1 << " liczbe: ";
				cin >> val;
				counter.startTimer();
				//for (int i = 0; i < m; i++)
				//{
					RBT->add(val);
				//}

				cout << "time: " << counter.endTimer()  << endl;
				
			}
			break;
		case 3:
			bool find;
			value = findValue();
			counter.startTimer();
			for (int i = 0; i < m; i++)
			{
				find = RBT->find(value);
			}

			cout << "time: " << counter.endTimer() / m << endl;

			if (find)
			{
				cout << "znaleziono" << endl;
			}
			else
			{
				cout << "nie znaleziono" << endl;
			}
			break;

		case 4:
			RBT->print();
		case 5:
			return;
			break;
		}
	}
}

int menuFromFile()
{
	int dzialanie;
	cout << "[0] dodaj na poczatek" << endl;
	cout << "[1] dodaj na koniec" << endl;
	cout << "[2] dodaj na losowa pozycje" << endl;
	cout << "podaj nr menu: ";
	cin >> dzialanie;
	return dzialanie;
}

void zapiszDoPliku(int n)
{
	int * losuj = new int[n];

	for (int i = 0; i < n; i++)
	{
		losuj[i] = ((rand() % 10000) );
	}

	std::fstream plik;
	plik.open("dane.txt", std::ios::out);
	if (plik.good() == true)
	{
		plik << n<<endl;
		for (int i = 0; i < n; i++)
		{
			plik << losuj[i]<<endl;
		}
		plik.close();
	}



}

int * readFromFile(string name)
{
	int *tab = new int[0];
	int sizeFile;
	int value;
	std::fstream plik;
	plik.open(name, ios::in);
	if (plik.good() == true)
	{
		plik >> sizeFile;

		tab = new int[sizeFile];

		tab[0] = sizeFile;
		for (int i = 1; i <= sizeFile; i++)
		{
			plik >> tab[i];


		}
		plik.close();
	}
	return tab;
}

int main()
{
	Array array;
	LinkedList linkedList;
	DoublyLinkedList doublyLinkedList;
	Heap heap;
	RedBlackTree RBT;


	srand(time(NULL));

	zapiszDoPliku(m);

	menu(&array, &linkedList, &doublyLinkedList, &heap, &RBT);


	system("pause");

	return 0;
	
}

