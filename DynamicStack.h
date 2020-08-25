#ifndef STACK_H
#define STACK_H

#include <cstddef>

template<typename T>
struct SNode
{
	T data;
	SNode* next;
};


template<typename T>
class Stack
{
	SNode<T>* top;
public:
	Stack();
	bool isEmpty();
	void push(T);
	T pop();
	~Stack();
};

#endif // !STACK_H

template<class T>
Stack<T>::Stack() {
	top = NULL;
}
template<class T>
bool Stack<T>::isEmpty() {
	return top == NULL;
}
template<class T>
void Stack<T>::push(T d) {
	SNode<T>* newNode = new SNode<T>;
	newNode->data = d;
	if (top == NULL) {
		top = newNode;
		top->next = NULL;
	}
	else{
		newNode->next = top;
		top = newNode;
	}
}
template<class T>
T Stack<T>::pop() {
	if (isEmpty()) {
		return NULL;
	}
	else {
		T data = top->data;
		SNode<T>* temp = top;
		top = top->next;
		delete temp;
		return data;
	}
}

template<typename T>
Stack<T>::~Stack() {}
