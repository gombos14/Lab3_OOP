#pragma once
#include "Node.h"

class Tree
{
private:
	Node* root;
	int nrNodes = 0;
public:
	Tree();
	void insert(int x);
	Node* ins(int v, Node* t);
	void inorder(Node* n);
	void display();
	Node* findMin(Node* t);
	Node* del(int v, Node* t);
	void remove(int v);
	void preorder(Node* n);
	void postorder(Node* n);
	int countNodes(Node* n);
	void countedNodes();
	int countEdges(Node* v);
	void countedEdges();
};