#pragma once
#include <string>

using namespace std;

struct RedBlackTreeNode
{
	RedBlackTreeNode * parent;
	RedBlackTreeNode * left;
	RedBlackTreeNode * right;
	int data;
	char color;
};

class RedBlackTree
{
public:
	string cr, cl, cp;
	RedBlackTreeNode  NIL;
	RedBlackTreeNode * root;
	RedBlackTreeNode * q;

	void leftRotate(RedBlackTreeNode * node);
	void rightRotate(RedBlackTreeNode * node);


	RedBlackTree();
	~RedBlackTree();
	void add(int value);
	void addRepair(RedBlackTreeNode * newNode);
	void removeRepair(RedBlackTreeNode * Z);
	void remove(int value);
	RedBlackTreeNode * successor(RedBlackTreeNode * p);
	RedBlackTreeNode * find(int value);
	void print();
	void printTree(string sp, string sn, RedBlackTreeNode * p);
	void FromFile(int * tab);


};

