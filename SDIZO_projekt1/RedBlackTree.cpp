#include "RedBlackTree.h"
#include<iostream>
#include <fstream>

using namespace std;


void RedBlackTree::leftRotate(RedBlackTreeNode * nodeA)
{
	RedBlackTreeNode * nodeB;
	RedBlackTreeNode *tmp;

	nodeB = nodeA->right;
	if (nodeB != &NIL)
	{
		tmp = nodeA->parent;
		nodeA->right = nodeB->left;
		if (nodeA->right != &NIL)
		{
			nodeA->right->parent = nodeA;
		}

		nodeB->left = nodeA;
		nodeB->parent = tmp;
		nodeA->parent = nodeB;

		if (tmp == &NIL)
		{
			root = nodeB;
		}
		else
		{
			if (tmp->left == nodeA)
			{
				tmp->left = nodeB;
			}
			else
			{
				tmp->right = nodeB;
			}
		}
	}
}

void RedBlackTree::rightRotate(RedBlackTreeNode * nodeA)
{

	RedBlackTreeNode * nodeB;
	RedBlackTreeNode *tmp;

	nodeB = nodeA->left;
	if (nodeB != &NIL)
	{
		tmp = nodeA->parent;
		nodeA->left = nodeB->right;
		if (nodeA->left != &NIL)
		{
			nodeA->left->parent = nodeA;
		}

		nodeB->right = nodeA;
		nodeB->parent = tmp;
		nodeA->parent = nodeB;

		if (tmp == &NIL)
		{
			root = nodeB;
		}
		else
		{
			if (tmp->left == nodeA)
			{
				tmp->left = nodeB;
			}
			else
			{
				tmp->right = nodeB;
			}
		}
	}
}

RedBlackTree::RedBlackTree()
{
	q = NULL;
	root= NULL;
	
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	NIL.color = 'b'; // nil pusty element ktory nie zawiera danych( wartownik)
	NIL.parent = &NIL;
	NIL.left = &NIL;
	NIL.right = &NIL;
	root = &NIL;
	
}


RedBlackTree::~RedBlackTree()
{
}

void RedBlackTree::add(int value)
{

	RedBlackTreeNode * newNode;
	

	newNode = new RedBlackTreeNode;        // Tworzymy nowy wêze³
	newNode->left = &NIL;          // Inicjujemy pola
	newNode->right = &NIL;
	newNode->parent = root;
	newNode->data = value;
	if (newNode->parent != &NIL)
	{
		while (true)             // Szukamy liœcia do zast¹pienia przez X
		{
			if (value >= newNode->parent->data)
			{
				if (newNode->parent->right == &NIL)
				{
					newNode->parent->right = newNode; // X zastêpuje prawy liœæ
					break;
				}
				newNode->parent = newNode->parent->right;
			}
			else
			{
				if (newNode->parent->left == &NIL)
				{
					newNode->parent->left = newNode;  // X zastêpuje lewy liœæ
					break;
				}
				newNode->parent = newNode->parent->left;
			}
		}
	}
	else
	{
		root = newNode; // X staje siê korzeniem
	}
	newNode->color = 'r';         // Wêze³ kolorujemy na czerwono

	addRepair(newNode);
}

void RedBlackTree::addRepair(RedBlackTreeNode * newNode)
{
	RedBlackTreeNode *tmp;  
	while ((newNode != root) && (newNode->parent->color == 'r'))
	{
		if (newNode->parent != newNode->parent->parent->left)
		{
			tmp = newNode->parent->parent->left;

			if (tmp->color == 'r') // Przypadek 1
			{
				newNode->parent->color = 'b';
				tmp->color = 'b';
				newNode->parent->parent->color = 'r';
				newNode = newNode->parent->parent;
				continue;
			}

			if (newNode == newNode->parent->left) // Przypadek 2
			{
				newNode = newNode->parent;
				rightRotate(newNode);
			}

			newNode->parent->color = 'b'; // Przypadek 3
			newNode->parent->parent->color = 'r';
			leftRotate(newNode->parent->parent);
			break;
		}
		else
		{                  // Przypadki lustrzane


			tmp = newNode->parent->parent->right; //  wujek X

			if (tmp->color == 'r')  // Przypadek 1
			{
				newNode->parent->color = 'b';
				tmp->color = 'b';
				newNode->parent->parent->color = 'r';
				newNode = newNode->parent->parent;
				continue;
			}

			if (newNode == newNode->parent->right) // Przypadek 2
			{
				newNode = newNode->parent;
				leftRotate(newNode);
			}

			newNode->parent->color = 'b'; // Przypadek 3
			newNode->parent->parent->color = 'r';
			rightRotate(newNode->parent->parent);
			break;
		}
	}
	root->color = 'b';
}

void RedBlackTree::removeRepair(RedBlackTreeNode * node)
{
	RedBlackTreeNode * tmp;
	
	while ((node != root) && (node->color == 'b'))
		if (node != node->parent->left)
		{
			tmp = node->parent->left;

			if (tmp->color == 'r')
			{              // Przypadek 1
				tmp->color = 'b';
				node->parent->color = 'r';
				rightRotate(node->parent);
				tmp = node->parent->left;
			}

			if ((tmp->left->color == 'b') && (tmp->right->color == 'b'))
			{              // Przypadek 2
				tmp->color = 'r';
				node = node->parent;
				continue;
			}

			if (tmp->left->color == 'b')
			{              // Przypadek 3
				tmp->right->color = 'b';
				tmp->color = 'r';
				leftRotate(tmp);
				tmp = node->parent->left;
			}

			tmp->color = node->parent->color;  // Przypadek 4
			node->parent->color = 'b';
			tmp->left->color = 'b';
			rightRotate(node->parent);
			node = root;         // To spowoduje zakoñczenie pêtli


			
		}
		else
		{                // Przypadki lustrzane
			tmp = node->parent->right;

			if (tmp->color == 'r')
			{              // Przypadek 1
				tmp->color = 'r';
				node->parent->color = 'r';
				leftRotate(node->parent);
				tmp = node->parent->right;
			}

			if ((tmp->left->color == 'b') && (tmp->right->color == 'b'))
			{              // Przypadek 2
				tmp->color = 'r';
				node = node->parent;
				continue;
			}

			if (tmp->right->color == 'b')
			{              // Przypadek 3
				tmp->left->color = 'b';
				tmp->color = 'r';
				rightRotate(tmp);
				tmp = node->parent->right;
			}

			tmp->color = node->parent->color; // Przypadek 4
			node->parent->color = 'b';
			tmp->right->color = 'b';
			leftRotate(node->parent);
			node = root;         // To spowoduje zakoñczenie pêtli
		}

	node->color = 'b';
}

void RedBlackTree::remove(int value)
{
	RedBlackTreeNode *tmpX, *tmpY, *del;

	del = find(value);

	if (del != NULL)
	{

		if ((del->left == &NIL) || (del->right == &NIL))
		{
			tmpX = del;
		}
		else
		{
			tmpX = successor(del);
		}

		if (tmpX->left == &NIL)
		{
			tmpY = tmpX->right;
		}
		else
		{

			tmpY = tmpX->left;
		}

		tmpY->parent = tmpX->parent;

		if (tmpX->parent == &NIL)
		{
			root = tmpY;
		}
		else if (tmpX != tmpX->parent->left)
		{
			tmpX->parent->right = tmpY;
		}
		else
		{
			tmpX->parent->left = tmpY;
		}
		if (tmpX != del)
		{
			del->data = tmpX->data;
		}

		if (tmpX->color == 'r')
		{
			removeRepair(tmpY);
		}

		delete tmpX;
	}
	
}

RedBlackTreeNode * RedBlackTree::successor(RedBlackTreeNode * node)
{	
	RedBlackTreeNode *tmp = &NIL;

	if (node->left != &NIL)
	{
		tmp = node->right;
		while (tmp->left != &NIL)
		{
			tmp = tmp->left;
		}
	}
	else
	{
		tmp = node->left;
		while (tmp->right != &NIL)
		{
			tmp = tmp->right;
		}
	}
	return tmp;
}

RedBlackTreeNode * RedBlackTree::find(int value)
{
	RedBlackTreeNode * p;

	p = root;
	while ((p != &NIL) && (p->data != value))
	{


		if (value < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if (p == &NIL)
	{
		return NULL;
	}
		return p;
}

void RedBlackTree::print()
{
	printTree("", "", root);
}

void RedBlackTree::printTree(string sp, string sn, RedBlackTreeNode * p)
{
	string t;

	if (p != &NIL)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		printTree(t + cp, cr, p->right);

		t = t.substr(0, sp.length() - 2);
		cout << t << sn << p->color << ":" << p->data << endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		printTree(t + cp, cl, p->left);
	}
	
}

void RedBlackTree::FromFile(int * tab)
{
	int size = tab[0];

		for (int i = 1; i <= size; i++)
		{
			add(tab[i]);
		}

	

}
