#pragma once
#include<iostream>	
using namespace std;
template<class T>
class QNode{
public:
	T value;
	QNode* next;
};
template<class T>
class Queue {
	QNode<T>* front;
	QNode<T>* rear;
public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	bool isEmpty() {
		return front == NULL;
	}
	void enqueue(T v) {
		QNode<T>* newNode;
		newNode = new QNode<T>;
		newNode->value = v;
		newNode->next = NULL;
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}
	T dequeue() {
		QNode<T>* temp;
		T v=T();
		if (isEmpty()) {
			return v;
		}
		else {
			v = front->value;
			temp = front->next;
			delete front;
			front = temp;
			return v;
		}
	}
	~Queue() {
		QNode<T>* curr = front;
		QNode<T>* next = NULL;
		while (curr) {
			next = front->next;
			delete curr;
			curr = next;
		}
		front = NULL;
		rear = front;
	}

};