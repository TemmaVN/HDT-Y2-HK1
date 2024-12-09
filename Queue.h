#ifndef QUEUE_H
#define QUEUE_H

template <class T>
struct QNode
{
	T data;
	QNode* next;
	QNode* pre;
};

template <class T>
QNode<T>* MakeQN(T d)
{
	QNode<T>* temp = new QNode<T>;
	temp->data = d;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}

template <class T>
class Queue
{
private:
	QNode<T>* first;
	QNode<T>* last;
	int sl;
public:
	Queue() {
		this->first = NULL;
		this->last = NULL;
		this->sl = 0;
	}
	void Put(T d) {
		QNode<T>* temp = MakeQN(d);
		if (this->first == NULL) {
			this->first = temp;
			this->last = temp;
		}
		else {
			temp->next = this->first;
			this->first->pre = temp;
			this->first = temp;
		}
		sl++;
	}
	void Pop()
	{
		QNode<T>* temp = this->last;
		if (this->last == NULL) return;
		else if (this->first == this->last) {
			this->first = NULL;
			this->last = NULL;
			temp = NULL;
			delete temp;
		}
		else {
			this->last = this->last->pre;
			temp->pre = NULL;
			this->last->next = NULL;
			temp = NULL;
			delete temp;
		}
		sl--;
	}
	QNode<T>* Out()
	{
		QNode<T>* temp = this->last;
		Pop();
		return temp;
	}
	void InQueue() {
		cout << "Hang doi hien la : ";
		for (QNode<T>* temp = this->first; temp != NULL;temp = temp->next)
		{
			cout << temp->data << ' ';
		}
		cout << endl;
		cout << "Hang doi co : " << sl << " phan tu !!" << endl;
	}
	
};

#endif // !QUEUE_H