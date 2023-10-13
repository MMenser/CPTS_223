#pragma once
#include "AVLNode.h"
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;

template<class T> 
class AVLTree {
public:
	AVLTree() {
		this->root = nullptr;
	}

	~AVLTree() {
		delete this->root;
	}

	int height() {
		if (this->root == nullptr) {
			return -1;
		}

		return this->root->height;
	}

	int contains(T value) {
		bool found = false;
		AVLNode<T>* temp = this->root;

		while (temp != nullptr && !found) {
			if (value == temp->data) {
				return 1;
			}
			if (value > temp->data) {
				temp = temp->right;
			}
			else {
				temp = temp->left;
			}
		}

		return 0;
	}

	int validate() {
		return this->validate(this->root);
	}

	int validate(AVLNode<T>*& node) {
		int leftS = 0, rightS = 0;
		if (node == nullptr) return 0;

		validate(node->left);
		if (node->left != nullptr) {
			leftS = node->left->height;
		}
		if (node->right != nullptr) {
			rightS = node->right->height;
		}
		if (abs(leftS - rightS) > 1) {
			return false;
		}
		validate(node->right);
		return true;
	}

	void insert(T newVal) {
		insert(newVal, this->root);
	}


	void insert(T newVal, AVLNode<T>*& node) {
		if (node == nullptr) {
			node = new AVLNode<T>(newVal);
		}
		else if (newVal < node->data) {
			insert(newVal, node->left);
		}
		else {
			insert(newVal, node->right);
		}

		this->setHeight(node);
		int balNeeded = this->findBalanceNeeded(node);
		this->balance(balNeeded, node);

	}

	void leftRotate(AVLNode<T>*& node) {
		AVLNode<T>* temp = node;
		AVLNode<T>* right = node->right;

		node->right = right->left;
		right->left = node;
		node = right;
		setHeight(temp);
		setHeight(right);
		setHeight(node);

	}

	void rightRotate(AVLNode<T>*& node) {
		AVLNode<T>* temp = node;
		AVLNode<T>* left = node->left;

		node->left = left->right;		//Switches cur node left to left->right
		left->right = node;
		node = left;
		setHeight(temp);
		setHeight(left);
		setHeight(node);	
	}

	

	void setHeight(AVLNode<T>*& node) {
		if (node->left == nullptr && node->right == nullptr) {
			node->height = 0;
		}
		else if (node->left == nullptr) {			//No left subtree
			node->height = node->right->height + 1;
		}
		else if (node->right == nullptr) {			//No right subtree
			node->height = node->left->height + 1;
		}
		else {	//Both left and right subtrees
			if (node->left->height > node->right->height) {		//If left is bigger subtree
				node->height = node->left->height + 1;
			}
			else {		//If right is bigger subtree
				node->height = node->right->height + 1;
			}
		}
	}

	int findBalanceNeeded(AVLNode<T>* node) {
		if (node == nullptr) {
			return 0;
		}
		else {		//If there is atleast one node in the tree
			if (node->right == nullptr && node->left == nullptr) {
				return 0;
			}
			else if (node->left == nullptr) {
				return -1 - node->right->height;		//Negative if no left child
			}
			else if (node->right == nullptr) {
				return node->left->height + 1;		//Positive if no right child
			}
			else {
				return node->left->height - node->right->height;
			}
		}
	}

	void balance(int balanceNeeded, AVLNode<T>*& node) {
		if (1 < abs(balanceNeeded)) {
			if (this->findBalanceNeeded(node->right) <= 0 && balanceNeeded < -1) {
				this->leftRotate(node);
			}
			if (this->findBalanceNeeded(node->left) >= 0 && balanceNeeded > 1) {
				this->rightRotate(node);
			}
			if (this->findBalanceNeeded(node->right) > 0 && balanceNeeded < -1) {
				this->rightRotate(node->right);
				this->leftRotate(node);
			}
			if (this->findBalanceNeeded(node->left) < 0 && balanceNeeded > 1) {
				this->leftRotate(node->left);
				this->rightRotate(node);
			}
			
		}

	}

private:
	AVLNode<T>* root;
};