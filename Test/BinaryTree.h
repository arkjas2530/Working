#pragma once
class BinaryTree
{
	int val,level;
	int *father, *l_child, *r_child;
public:
	BinaryTree();
	~BinaryTree();
	void add();
};

