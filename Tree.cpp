#include <iostream>
#include "Tree.h"
#include "Node.h"

Node* Tree::ins(int v, Node* t)
{
	if (t == NULL)
		t = new Node(v);
	else
	{
		if (v < t->key)
			if (t->left == NULL)
				t->left = new Node(v);
			else ins(v, t->left);
		else if (v >= t->key)
			if (t->right == NULL)
				t->right = new Node(v);
			else ins(v, t->right);
	}
	return t;
}


void Tree::insert(int x)
{
	root = ins(x, root);
}

void Tree::inorder(Node* n)
{
	if (n == NULL)
		return;
	inorder(n->left);
	std::cout << n->key << " ";
	inorder(n->right);

}

void Tree::display()
{
	int k;
	std::cout<<"1. Inorder\n2. Preorder\n3. Postorder\n" << std::flush;
	std::cin >> k;
	system("CLS");
	std::cout << std::flush;
	if (k == 1)
	{
		inorder(root);
		std::cout << std::endl;
	}
	else if (k == 2)
	{
		preorder(root);
		std::cout << std::endl;
	}
	else if (k == 3)
	{
		postorder(root);
		std::cout << std::endl;
	}
}

Node* Tree::findMin(Node* t)
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

Node* Tree::del(int v, Node* t)
{
	Node* temp;
	if (t == NULL)
		return NULL;
	else if (v < t->key)
		t->left = del(v, t->left);
	else if (v > t->key)
		t->right = del(v, t->right);
	else if (t->left && t->right)
	{
		temp = findMin(t->right);
		t->key = temp->key;
		t->right = del(t->key, t->right);
	}
	else
	{
		temp = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		delete temp;
	}

	return t;
}

void Tree::remove(int v)
{
	root = del(v, root);
}

void Tree::preorder(Node* n)
{
	if (n == NULL)
		return;
	std::cout << n->key << " ";
	preorder(n->left);
	preorder(n->right);
}

void Tree::postorder(Node* n)
{
	if (n == NULL)
		return;
	postorder(n->left);
	postorder(n->right);
	std::cout << n->key << " ";
}

int Tree::countNodes(Node* n)
{
	if (n == NULL) return 0;
	return 1 + countNodes(n->left) + countNodes(n->right);
}

void Tree::countedNodes()
{
	std::cout << countNodes(root);
	std::cout << std::endl;
}

int Tree::countEdges(Node* v)
{
	return v == NULL ? 0 : countNodes(v) - 1;
}

void Tree::countedEdges()
{
	std::cout << countEdges(root);
	std::cout << std::endl;
}