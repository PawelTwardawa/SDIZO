#include "Heap.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

Heap::Heap()
{
	size = 0;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
}


Heap::~Heap()
{
}


void Heap::add(int value)
{
	data[size + 1] = value; //przpisanie nowej liczby size + 1 elementu tablicy
	int tmpSize = size + 1;
	//szukanie ostatnigo 
	while (tmpSize != 1)
	{
		if (data[tmpSize / 2] < data[tmpSize])
		{
			swap(data[tmpSize / 2], data[tmpSize]); // umieszczamy rodzica w miejscu syna 
			tmpSize /= 2; // przechodzimy do rodzica
		}
		else
		{
			break; // jezeli warunek kopca nie jest spelniony
		}
	}
	size++;

}


void Heap::removeRoot()
{
	data[1] = data[size]; //zamieniamy korzen z ostatnim elementem
	size--;
	int tmp = 1;
	//naprawiamy poprawnosc drzewa
	while (tmp * 2 <= size) 
	{
		if (data[tmp] < data[tmp * 2] || data[tmp] < data[tmp * 2 + 1]) //lewy syn, prawy syn
		{
			if (data[tmp * 2] > data[tmp * 2 + 1] || tmp * 2 + 1 > size)
			{
				swap(data[tmp], data[tmp * 2]); //zamieniamy miejscami
				tmp *= 2;
			}
			else
			{
				swap(data[tmp], data[tmp * 2 + 1]);
			}
			tmp = tmp *2 +1;
		}
		else
		{
			break;
		}
	}
}

void Heap::print()
{

	for (int i = 1; i <= size; i++)
	{
		cout << data[i] << " ";
	}
	cout<<endl;
	drawHeap("", "", 0);
}


int Heap::find(int pos, int value)
{
	for (int i = pos; i < size; i++)
	{
		if (data[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void Heap::FromFile(int * tab)
{
	int size = tab[0];

		for (int i = 1; i <= size; i++)
		{
			add(tab[i]); //dodawnaie elementow do struktury 
		}
	
}

void Heap::drawHeap(string sp, string sn, int v)
{
	string s;

	if (v < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		drawHeap(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << data[v+1] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		drawHeap(s + cp, cl, 2 * v + 1);
	}
}
