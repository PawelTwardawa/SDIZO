#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>





Array::Array()
{
	size = 0; // rozmiar tablicy
	array = new int[size];
}


Array::~Array()
{
}


void Array::AddToEndResize()
{
	int m = size;
	if (++size >= m)
	{
		tmp = new int[m+1]; //usworzenie nowej wiekszej tablicy
		for (int i = 0; i < m ; i++)
		{
			tmp[i] = array[i]; // przepisanie elementow tablicy do nowej wiekszej tablicy
		}
		delete[] array; //usuniecie starej tablicy
		array = tmp;
		size = m + 1; // zmiana rozmiaru 
	}
}

void Array::AddToBeginingResize()
{
	int m = size;
	if (++size >= m)
	{
		tmp = new int[m + 1]; //utworzenie nowej wiekszej tabliicy
		for (int i = 0; i < m; i++)
		{
			tmp[i+1] = array[i]; //przepisanie elementow tablicy zaczynajac od  = 1
		}
		delete[] array; //usuwanie tablicy
		array = tmp; 
		size = m + 1;
	}
}

void Array::AddToRandPosResize(int pos)
{

	int m = size;
	if (++size >= m)
	{
		tmp = new int[m + 1];
		for (int i = 0; i < pos; i++) //prepisanie tablicy do indeksu pos
		{
			tmp[i] = array[i];
		}
		for (int i = pos; i < m; i++)//prepisanie tablicy od elementu pos + 1
		{
			tmp[i +1] = array[i];
		}
		delete[] array;
		array = tmp;
		size = m + 1;
	}
}

void Array::FromFile(int * tab, int dzialanie) // 0 na poczatek, 1 na koniec, 0 na losowe pozycje
{
	int sizeFile;
	
		sizeFile = tab[0];

		for (int i = 1; i <= sizeFile ; i++)
		{
			if (dzialanie == 0)
			{
				AddToBegining(tab[i]);
			}
			if (dzialanie == 1)
			{
				AddToEnd(tab[i]);
			}
			if (dzialanie == 2)
			{
				int rand = 0;
				if (size != 0)
				{
					rand = (std::rand() % size);
				}

				AddToPos(tab[i], rand);
			}
			
			
		}

	
}

int Array::getSize()
{
	return size;
}

void Array::AddToEnd(int value)
{
	AddToEndResize();
	array[size-1] = value;
}

void Array::AddToBegining(int value)
{
	AddToBeginingResize();
	array[0] = value;
}

void Array::AddToPos(int value, int pos)
{
	AddToRandPosResize(pos);
	array[pos] = value;
}

void Array::RemoveFromEnd()
{
	int m = size;
	if (--size <= m)
	{
		tmp = new int[m -1];
		for (int i = 0; i < size; i++) // przepisanie tablicy po usunieciu elementu
		{
			tmp[i] = array[i];
		}
		delete[] array;
		array = tmp;
		size = m-1;
	}
}

void Array::RemoveFromBegining()
{
	int m = size;
	if (--size <= m)
	{
		tmp = new int[m - 1];
		for (int i = 0; i < size; i++) // przepisanie tablicy po usunieciu elementu
		{
			tmp[i] = array[i+1];
		}
		delete[] array;
		array = tmp;
		size = m - 1;
	}
}

void Array::RemoveFromPos(int pos)
{
	int m = size;
	if (--size <= m)
	{
		tmp = new int[m - 1];
		for (int i = 0; i < pos; i++)
		{
			tmp[i] = array[i];
		}
		for (int i = pos; i < m; i++)
		{
			tmp[i] = array[i + 1];
		}
		delete[] array;
		array = tmp;
		size = m - 1;
	}

}


bool Array::Find(int value) //wyszukiwanie liniowe
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			return true;
		}
	}

	return false;
}

void Array::Print()
{
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << array[i] << std::endl;
		}
	}
}







