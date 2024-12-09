#ifndef STACK_H
#define STACK_H

template<class T>
class Stack
{
private:
	int Top;
	int Size;
	T* Stprt;
public:
	Stack()
	{
		this->Size = 10;
		Top = 0;
		Stprt = new T[Size];
	}
	Stack(int s)
	{
		this->Size = (s > 0 && s < 100) ? s : 10;
		Top = -1;
		Stprt = new T[Size];
	}
	bool Isfull(){
		return (Top >= Size - 1);
	}
	bool IsEmpty() {
		return (Top == 0);
	}
	void Push(T data)
	{
		if (Isfull()) { 
			cout << "Ngan xep da day !!" << endl;
			return;
		}
		else {
			Top++;
			Stprt[Top] = data;
		}
	}
	void Pop() {
		if (IsEmpty()){
			cout << "Ngan xep rong!!" << endl;
			return;
		}
		else {
			Top--;
		}
	}
	T Peek() {
		if (!IsEmpty()) {
			Top--;
			return Stprt[Top+1];
		}
		return 0;
	}
	void InStack(){
		cout << "Ngan xep cua ban la : ";
		for (int i = Top;i >= 0;i--)
		{
			cout << Stprt[i] << ' ';
		}
		cout << endl;
		cout << "Ngan xep con du " << Size - Top - 1 << " ngan !!" << endl;
	}
};

#endif // !STACK_H