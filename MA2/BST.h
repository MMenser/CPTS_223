#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <vector>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	void destructorHelper(Node<T>* root) {
		if (root != nullptr) {
			destructorHelper(root->left);
			destructorHelper(root->right);
			delete root;
		}
	}

	bool containHelper(Node<T>* root, T target) {
		if (root == nullptr) {
			return false;
		}
		

		if (root->value > target) {
			return containHelper(root->left, target);
		}
		else if (root->value < target) {
			return containHelper(root->right, target);
		}
		else {
			return true;
		}

		return false;

	}

	void maxPathHelper(Node<T>* root, vector<T>& path, vector<T>& maxPath, int& curLength, int& maxLength) {
		if (root != nullptr) {
			path.push_back(root->value);
			curLength++;
			maxPathHelper(root->left, path, maxPath, curLength, maxLength);
			maxPathHelper(root->right, path, maxPath, curLength, maxLength);
			path.pop_back();		//Need to remove the last node after all nodes searched thru
			curLength--;
		}
		if (curLength > maxLength) {
			maxLength = curLength;
			maxPath = path;
		}
	}

	void printLevelHelper() {
		vector<Node<T>*> list;
		vector<int> newline;
		Node<T>* curNode;
		int curLine = 0, level = 0;

		newline.push_back(0);
		list.insert(list.begin(), this->_root);

		while (!list.empty()) {
			curNode = list.front();
			level = newline.front();

			if (curLine < level) {
				std::cout << endl;
				curLine = level;
			}

			std::cout << curNode->value << " ";
			list.erase(list.begin());
			newline.erase(newline.begin());

			if (curNode->left != nullptr) {
				list.push_back(curNode->left);
				newline.push_back(level + 1);
			}
		
			if (curNode->right != nullptr) {
				list.push_back(curNode->right);
				newline.push_back(level + 1);
			}
			

		}

		std::cout << endl;
	}

	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	~BST() {
		destructorHelper(this->_root);
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	void printLevelOrder() {
		printLevelHelper();
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}


	void printMaxPath() {
		vector<T> path, maxPath;
		int currentLength = 0, maxLength = -1;
		maxPathHelper(this->_root, path, maxPath, currentLength, maxLength);
		for (auto v : maxPath) {
			std::cout << v << " ";
		}
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	bool contains(T value) {
		return containHelper(this->_root, value);
	}
};

#endif

