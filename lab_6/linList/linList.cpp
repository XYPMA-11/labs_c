#include "pch.h"
#include <iostream>
#include <locale>

using namespace std;

class Node
{
	friend class LinkList;
public:
	Node(int data, Node* next, Node* last)
	{
		this->data = data;
		this->next = next;
		this->last = last;
	}

	Node(int data)
	{
		this->data = data;
	}
private:
	int key;
	int data;
	Node* next;
	Node* last;
};

class LinkList
{
public:
	LinkList()
	{
		head = NULL;
		temp = NULL;
		size = 0;
		
	}

	void addNode(int data)
	{
		Node* nd = new Node(data, NULL, temp);
		temp = nd;

		if (head)
		{
			Node* current = head;
			while (current->next)
			{
				current = current->next;
			}
			current->next = nd;
			
		}
		else
		{
			head = nd;
		}
	}

	void deleteNodeDuplicate()
	{
		if (head == NULL)
		{
			return;
		}
		Node* current = head;
		while (current != NULL)
		{
			Node* runner = current;
			while (runner->next != NULL)
			{
				if (runner->next->data == current->data)
				{
					Node* toDelete = runner->next;
					runner->next = toDelete->next;
					delete toDelete;
				}
				else
				{
					runner = runner->next;
				}
			}
			current = current->next;
		}
			
	}

	void countSize()
	{
		size = 0;
		Node* current = head;
		while (current)
		{
			size++;
			current = current->next;
		}
	}


	void find(int k)
	{
		Node* current = head;
		if (k <= size)
		{
			while (current)
			{
				if (current->key == size - k + 1)
				{
					cout << k << " элемент с конца: " << current->data << endl;
				}
				current = current->next;
			}
		}
		else
		{
			cout << "Поиск невозможен, превышен размер списка" << endl;
		}
	}

	void printList()
	{
		Node* current = head;
		numNode();
		while (current)
		{
			size;
			cout << current->key << " - " << current->data << endl;
			current = current->next;
		}
	}

	void numNode()
	{
		Node* counter = head;
		int i = 0;
		while (counter)
		{
			counter->key = ++i;
			counter = counter->next;
		}
	}
private:
	Node* head;
	Node* temp;
	int size;
	
};
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	LinkList list;
	list.addNode(41);
	list.addNode(23);
	list.addNode(55);
	list.addNode(55);
	list.addNode(55);
	list.addNode(74);
	list.addNode(23);
	list.addNode(71);
	list.addNode(47);
	list.addNode(23);
	cout << "Список до удаления дубликатов:" << endl;
	list.printList();
	list.countSize();
	
	
	list.deleteNodeDuplicate();

	cout << "Список после удаления дубликатов:" << endl;
	list.printList();
	list.countSize();


	list.find(2);
}
