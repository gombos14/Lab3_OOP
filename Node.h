#pragma once

class Node
{
	friend class Tree;
private:
	int key;
	Node* left;
	Node* right;
public:
	Node(int val);
	
};