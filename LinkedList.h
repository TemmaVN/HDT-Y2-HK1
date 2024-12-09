#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Library.h"

template <class T>
struct Node
{
	T data;
	Node* next;
};

template<class T>
Node<T>* MakeNode(T d)
{
	Node<T>* temp = new Node<T>;
	temp->data = d;
	temp->next = NULL;
	return temp;
}

template <class T>
class LList
{
private:
	Node<T>* first;
	int sl;
public:
	LList()
	{
		this->first = NULL;
		this->sl = 0;
	}
	void InsertFirst(T d)
	{
		Node<T>* temp = MakeNode<T>(d);
		if (this->first == NULL) this->first = temp;
		else
		{
			temp->next = this->first;
			this->first = temp;
		}
		sl++;
	}
	void InsertLast(T d)
	{
		Node<T> *temp = MakeNode<T>(d);
		Node<T> *run = this->first;
		if (this->first == NULL) {
			this->first = temp;
		}
		else
		{
			while (run->next != NULL)
			{
				run = run->next;
			}
			run->next = temp;
		}
		sl++;
	}
	void InsertPos(T d, int pos)
	{
		Node<T>* temp = MakeNode<T>(d);
		if (pos > sl + 1|| pos <= 0) {
			cout << "Khong co vi tri nay ! " << endl;
			return;
		}
		else
		{
			if (pos == 1)
			{
				InsertFirst(d);
				return;
			}
			if (pos == sl + 1)
			{
				InsertLast(d);
				return;
			}
			Node<T>* run = this->first;
			while (pos > 2)
			{
				run = run->next;
				pos--;
			}
			temp->next = run->next;
			run->next = temp;
		}
		sl++;
	}
	void DeleteFirst()
	{
		if (this->first == NULL) return;
		else {
			Node<T>* temp = this->first;
			this->first = this->first->next;
			temp->next = NULL;
			temp = NULL;
			delete temp;
			sl--;
		}
	}
	void DeleteLast() {
		if (this->first == NULL) return;
		else if (this->first->next == NULL) {
			DeleteFirst();
			return;
		}
		else {
			Node<T>* temp = this->first;
			while (temp->next->next != NULL) temp = temp->next;
			Node<T>* del = temp->next;
			temp->next = NULL;
			del = NULL;
			delete del;
			sl--;
		}
	}
	void DeletePos(int pos) {
		if (this->first == NULL) {
			cout << "Danh sach rong !!" << endl;
			return;
		}
		if (pos > sl || pos <= 0) {
			cout << "Khong co vi tri nay ! " << endl;
			return;
		}
		else
		{
			if (pos == 1)
			{
				DeleteFirst();
				return;
			}
			else if (pos == sl) {
				DeleteLast();
				return;
			}
			else
			{
				Node<T>* temp = this->first;
				while (pos > 2) {
					temp = temp->next;
					pos--;
				}
				Node<T>* del = temp->next;
				temp->next = del->next;
				del->next = NULL;
				del = NULL;
				delete del;
				sl--;
			}
		}
	}
	Node<T>* TakeNode(int pos)
	{
		Node<T>* temp = this->first;
		if (this->first == NULL) {
			return NULL;
		}
		if (pos > sl || pos <= 0) {
			return NULL;
		}
		int p = pos;
		while (p > 1)
		{
			temp = temp->next;
			p--;
		}
		DeletePos(pos);
		return temp;
	}
	void HienThi()
	{
		cout << "Danh sach la : ";
		for (Node<T>* temp = this->first;temp != NULL;temp = temp->next)
		{
			cout << temp->data << ' ';
		}
		cout << endl;
		cout << "Danh sach gom " << sl << " phan tu!" << endl;
	}
};
#endif // !LINKEDLIST_H