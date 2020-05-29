// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

template<typename T>
class TreeNode
{
public:
	TreeNode<T>()
	{
		left = right = nullptr;
		value = NULL;
	}
	TreeNode<T>(int value, TreeNode<T>* left, TreeNode<T>* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}

	void setValue(int value)
	{
		this->value = value;
	}

	void setLeftNode(TreeNode<T>* left)
	{
		this->left = left;
	}

	void setRightNode(TreeNode<T>* right)
	{
		this->right = right;
	}

	int getValue()
	{
		return value;
	}

	TreeNode<T>* getLeftNode()
	{
		return left;
	}

	TreeNode<T>* getRightNode()
	{
		return right;
	}
private:
	int value;
	TreeNode *left;
	TreeNode *right;
};

template<typename T>
class BinaryTree
{
public:
	BinaryTree()
	{
		root = nullptr;
	}
	BinaryTree(TreeNode<T> node)
	{
		root = node;
	}
	~BinaryTree()
	{
		deleteNode();
	}

	void Insert(int key)
	{
		if (root != NULL)
		{
			Insert(key, root);
		}
		else
		{
			TreeNode<T>* temp = new TreeNode<T>;
			temp->setValue(key);
			root = temp;
		}
	}

	TreeNode<T>* Search(int key)
	{
		return Search(key, root);
	}

	//void printNode() 
	//{
	//	printNode(root);
	//	cout << "\n";
	//}

	void CreateMinimalBST(int* array, int start, int end)
	{
		int median = (end + start) / 2;
		int pivot = array[median];

		Insert(pivot);
		if (median > start)
		{
			CreateMinimalBST(array, start, median - 1);
		}
		if (median < end)
		{
			CreateMinimalBST(array, median + 1, end);
		}
	}
	
private:
	void deleteNode(TreeNode<T>* node)
	{
		if (node != NULL)
		{
			deleteNode(node->left);
			deleteNode(node->right);
			delete node;
		}
	}

	void Insert(int key, TreeNode<T>* node)
	{
		if (key < node->getValue())
		{
			if (node->getLeftNode() != NULL)
			{
				Insert(key, node->getLeftNode());
			}
			else
			{
				TreeNode<T>* temp = new TreeNode<T>;
				temp->setValue(key);
				temp->setLeftNode(nullptr);
				temp->setRightNode(nullptr);
				node->setLeftNode(temp);
			}
		}
		else
		{
			if (node->getRightNode() != NULL)
			{
				Insert(key, node->getRightNode());
			}
			else
			{
				TreeNode<T>* temp = new TreeNode<T>;
				temp->setValue(key);
				temp->setLeftNode(nullptr);
				temp->setRightNode(nullptr);
				node->setRightNode(temp);
			}
		}
	}



	TreeNode<T>* Search(int key, TreeNode<T>* node)
	{
		if (node != NULL)
		{
			if (key == node->getValue())
			{
				return node;
			}
			if (key < node->getValue())
			{
				return Search(key, node->getLeftNode());
			}
			else
			{
				return Search(key, node->getRightNode());
			}
		}
		else
		{
			return NULL;
		}
	}


	//void printNode(TreeNode<T>* node) {
	//	if (node != NULL) {
	//		cout << node->getValue() << endl << ' ';
	//		printNode(node->getLeftNode());
	//		cout << ' ';
	//		printNode(node->getRightNode());
	//		cout << ' ';
	//	}
	//}

	TreeNode<T>* root;
};

int main()
{
	BinaryTree<int>* tree = new BinaryTree<int>();
	int array[7] = { 1,2,3,4,5,6,7 };
	int firstElement = 0;
	int lastElement = 6;
	tree->CreateMinimalBST(array, firstElement, lastElement);
}

