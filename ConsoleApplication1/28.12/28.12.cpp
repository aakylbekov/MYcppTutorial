// 28.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//fhttp://www.dreamincode.net/forums/topic/78802-martyr2s-mega-project-ideas-list/
class Node {
public:
	Node *left, *right;
	int value;
	Node(int value) {
		this->value = value;
		left = right = NULL;
	}
};

class Tree {
public:
	Node *root;
	Tree() {
		root = NULL;
	}
	void add(int value) {
	if (root == NULL){
		root = new Node(value);
	}
	else {
		Node *temp = root;
		if (temp->value > value) {
			if (temp->left = NULL) {
				temp->left= new Node(value);
			}
			else {
				addToExistingTree(root, value);
			}
		}
	}

	void addToExistingTree(Node *root, int value) {
		if (root->value > value) {
			if (root->left = NULL) {
				root->left = new Node(value);
			}
			else {
				addToExistingTree(root->left, value);
			}
		}
		else if (root->value < value) {
			if (root->right = NULL) {
				root->right = new Node(value);
			}
			else {
				addToExistingTree(root->right, value);
			}
		}
	}
		
	}
	
	void remove() {}
	void show() {}
	~Tree(){}
};
int main()
{
    return 0;
}

