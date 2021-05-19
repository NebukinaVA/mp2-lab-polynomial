#pragma once
#include <iostream>

template <class T>
struct Node {
	T data;
	Node *next;
	Node(T data_ = {}, Node* next_ = nullptr)
	{
		data = data_;
		next = next_;
	}
};

template <class T>
class List
{
private:
	Node<T> *first;
	size_t Size;
public:
	class Iterator
	{
		Node<T>* pointer;
	public:
		Iterator() { pointer = 0; }
		Iterator(Node<T>* ptr) { pointer = ptr; }
		Iterator(const Iterator &i) { pointer = i.pointer; }
		Node<T>* get_node() { return pointer; }
		Node<T>& operator*() { return *pointer; }
		Node<T>* operator->() { return pointer; }
		Iterator operator++()  // prefix
		{
			if (pointer == nullptr) throw "Error";
			pointer = pointer->next;
			return *this;
		}
		Iterator operator++(int) //postfix
		{
			Iterator temp(pointer);
			++(*this);
			return temp;
		}
		Iterator& operator=(const Iterator &i)
		{
			pointer = i.pointer;
			return *this;
		}
		bool operator==(const Iterator i) { return (pointer == i.pointer); }
		bool operator!=(const Iterator i) { return !(*this == i); }
		Iterator operator+=(int n)
		{
			for (int i = 0; i < n; i++)
				++(*this);
			return *this;
		}
	};
	List();
	List(const List<T> &l);
	~List();
	bool empty();
	size_t size() { return Size; }
	void append(const T& elem, Node<T>* ptr);
	void remove(Node<T>* ptr);
	void push_front(const T& elem);
	void pop_front();
	void push_back(const T& elem);
	void pop_back();
	void change_node(const T& elem, Node<T>* ptr);
	void clear();
	Node<T>* head() { return first; }
	List<T>& operator=(const List<T> &l);
	bool operator==(const List<T> &l);
	bool operator!=(const List<T> &l);
	Iterator begin() { return Iterator(first); }
	Iterator end() { return Iterator(nullptr); }
};

template <class T>
List<T>::List()
{
	Size = 0;
	first = nullptr;
}

template <class T>
List<T>::List(const List<T> &l)
{
	Size = l.Size;
	first = nullptr;
	Node<T> *temp = l.first;
	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

template <class T>
List<T>::~List()
{
	Node<T> *temp = this->first;
	while (first != nullptr)
	{
		temp = first->next;
		delete first;
		first = temp;
	}
}

template <class T>
bool List<T>::empty()
{
	if (first == nullptr) return true;
	return false;
}

template <class T>
void List<T>::append(const T& elem, Node<T>* ptr)
{
	if (empty())
	{
		first = new Node<T>(elem);
	}
	else
	{
		Node<T>* temp = new Node<T>(elem, ptr->next);
		ptr->next = temp;
	}
	Size++;
}

template <class T>
void List<T>::remove(Node<T>* ptr)
{
	if (empty()) throw "Error";
	if (ptr == nullptr) throw "Error";
	Node<T>* temp = ptr->next;
	ptr->next = temp->next;
	delete temp;
	Size--;
}

template <class T>
void List<T>::push_front(const T& elem)
{
	Node<T>* temp = new Node<T>(elem, first);
	first = temp;
	Size++;
}

template <class T>
void List<T>::pop_front()
{
	if (empty()) throw "Error";
	Node<T>* temp = this->first;
	first = first->next;
	delete temp;
	Size--;
}

template <class T>
void List<T>::push_back(const T& elem)
{
	if (empty())
	{
		first = new Node<T>(elem);
	}
	else
	{
		Node<T>* temp = this->first;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Node<T>(elem);
	}
	Size++;
}

template <class T>
void List<T>::pop_back()
{
	if (empty()) throw "Error";
	Node<T>* temp = this->first;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp = nullptr;
	Size--;
}

template <class T>
void List<T>::change_node(const T& elem, Node<T>* ptr)
{
	ptr->data = elem;
}

template <class T>
void List<T>::clear()
{
	while (first != nullptr)
	{
		Node<T> *temp = first;
		first = first->next;
		delete temp;
	}
	Size = 0;
}

template <class T>
List<T>& List<T>::operator=(const List<T> &l)
{
	clear();
	Node<T> *temp = l.first;
	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
	Size = l.Size;
	return *this;
}

template <class T>
bool List<T>::operator==(const List<T> &l)
{
	if (l.Size != Size)	return false;
	Node<T> *temp1 = first;
	Node<T> *temp2 = l.first;
	while (temp1 != nullptr)
	{
		if (temp1->data == temp2->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else return false;
	}
	return true;
}

template <class T>
bool List<T>::operator!=(const List<T> &l)
{
	return !(*this == l);
}