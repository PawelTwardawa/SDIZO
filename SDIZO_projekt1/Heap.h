#pragma once
#define N 50000
#include <string>
using namespace std;
class Heap
{
public:
	int data[N];
	int size;
	string cr;
	string cl;
	string cp;

	Heap();
	~Heap();

	void add(int value);
	void removeRoot();
	void print();
	int find(int pos, int value);
	void FromFile(int * tab);

	void drawHeap(string sp, string sn, int v);
};

