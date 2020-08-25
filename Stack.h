#ifndef STACK_H
#define STACK_H
template<typename T>
class Stack
{
	T *array;
	int size;
	int top;
public:
	Stack(int);
	void push(T);
	bool isEmpty();
	bool isFull();
	void pop(T&);
	T peek();
	void sortStack();
	void sortedInsert(T&);
	~Stack();
};
#endif
template<typename T>
T Stack<T>::peek() {
	return array[top];
}
template<typename T>
Stack<T>::Stack(int s)
{
	size = s;
	top = -1;
		array = new T[size];
}

template<typename T>
void Stack<T>::push(T data) {
	if (!isFull()) {
		++top;
		array[top] = data;
	}
	else {
		cout << "Stack is full" << endl;
	}
}
template<typename T>
void Stack<T>::pop(T& data) {
	if (!isEmpty()) {
		data = array[top];
		top--;
	}
	else {
		cout << "Stack is Empty" << endl;
	}
}
template<typename T>
bool Stack<T>::isEmpty() {
	return top == -1;
}
template<typename T>
bool Stack<T>::isFull() {
	return top == size - 1;
}
template<typename T>
Stack<T>::~Stack()
{
	delete[]array;
}

template<typename T>
void Stack<T>::sortStack() {
	if (!isEmpty()) {
		T data; pop(data);
		sortStack();
		sortedInsert(data);
	}
}
template<typename T	>
void Stack<T>::sortedInsert(T& data) {
	if (isEmpty() ||data>peek()) {
		push(data);
	}
	else {
		T data; pop(data);
		sortedInsert(data);
		push(data);
	}
}