#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
	int _Size = 0;
public:
	class Node
	{
	public:
		T value;
		Node* next = NULL;
		Node* prev = NULL;
	};
	Node* head = NULL;

	void PrintList()
	{
		Node* Current = head;

		while (Current != NULL)
		{
			cout << Current->value << " ";
			Current = Current->next;
		}

		cout << "\n";
	}

	void InsertAtBeginning(T value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = head;
		new_node->prev = NULL;

		if (head != NULL)
		{
			head->prev = new_node;
		}
		head = new_node;

		_Size++;
	}

	Node* Find(T value)
	{
		Node* Current = head;

		while (Current != NULL)
		{
			if (Current->value == value)
			{
				return Current;
			}
			Current = Current->next;
		}
		return NULL;
	}

	void InsertAfter(Node* Current, T value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = Current->next;
		new_node->prev = Current;

		if (Current->next != NULL)
		{
			Current->next->prev = new_node;
		}
		Current->next = new_node;

		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = NULL;

		if (head == NULL)
		{
			new_node->prev = NULL;
			head = new_node;
		}
		else
		{
			Node* Current = head;
			while (Current->next != NULL)
			{
				Current = Current->next;
			}

			Current->next = new_node;
			new_node->prev = Current;
		}

		_Size++;
	}

	void DeleteNode(Node* &NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}
		
		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}

		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (head == NULL)
		{
			return;
		}

		Node* temp = head;
		head = head->next;

		if (head != NULL)
		{
			head->prev = NULL;
		}

		delete temp;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_Size--;
			return;
		}

		Node* Current = head;
		while (Current->next->next != NULL)
		{
			Current = Current->next;
		}

		Node* temp = Current->next;
		Current->next = NULL;

		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* Current = head;
		Node* temp = nullptr;

		while (Current != nullptr)
		{
			temp = Current->prev;
			Current->prev = Current->next;
			Current->next = temp;

			Current = Current->prev;
		}

		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}

	Node* GetNode(int Index)
	{
		int Counter = 0;

		if (Index > _Size - 1 || Index < 0)
			return NULL;

		Node* Current = head;
		while (Current != NULL && (Current->next != NULL))
		{
			if (Index == Counter)
				break;

			Current = Current->next;
			Counter++;
		}

		return Current;
	}

	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->value;
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			ItemNode->value = NewValue;
			return true;
		}
		else
			return false;
	}

	bool InsertAfter(int Index, T Value)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, Value);
			return true;
		}
		else
			return false;
	}
};