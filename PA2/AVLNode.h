#include <stdlib.h>

template<class T>
class AVLNode
{
public:
	AVLNode<T>* left;
	AVLNode<T>* right;
	T data;
	int height;

	AVLNode(T data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
		this->height = 0;
	}

	~AVLNode()
	{
		if (this->left != nullptr) {
			delete this->left;
			this->left = nullptr;
		}

		if (this->right != nullptr) {
			delete this->right;
			this->right = nullptr;
		}
	}


private:
};