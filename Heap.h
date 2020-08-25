#pragma once
#include<iostream>	
using namespace std;
template<class T>
class Heap {
	T* heapArr;
	int capacity;
	int heap_size;
	//utility function for swapping
	void swap(T* a, T* b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}
	void heapOrder(int i) {
		int left = leftChild(i);
		int right = rightChild(i);
		int smallest = i;
		if (left < heap_size && heapArr[left] < heapArr[i])
			smallest = left;
		if (right < heap_size && heapArr[right] < heapArr[smallest])
			smallest = right;
		if (smallest != i) {
			swap(&heapArr[i], &heapArr[smallest]);
			heapOrder(smallest);
		}
	}
public:
	Heap(int);
	int parent(int);
	int leftChild(int);
	int rightChild(int);
	void Insert(T);
	T getMin() { if (heap_size > 0)return heapArr[0]; else return T(); }
	int currSize() {return heap_size;}
	void print();
	T deleteMin();
	bool is_empty();
	~Heap();
};

template<class T>
Heap<T>::Heap(int cap) {
	capacity = cap;
	heap_size = 0;
	heapArr = new T[capacity];
}
template<class T>
int Heap<T>::parent(int i) {
	return (i - 1) / 2;
}
template<class T>
int Heap<T>::leftChild(int i) {
	return 2 * i + 1;
}
template<class T>
int Heap<T>::rightChild(int i) {
	return 2 * i + 2;
}
template<class T>
void Heap<T>::Insert(T obj) {
	if (heap_size == capacity) {
		cout << "Heap is full---- Can't add anymore item" << endl;
		return;
	}
	heapArr[heap_size++] = obj;
	int i = heap_size - 1;
	while (i != 0 && heapArr[i]<heapArr[parent(i)] ) {
		swap(&heapArr[i], &heapArr[parent(i)]);
		i = parent(i);
	}
}
template<class T>
T Heap<T>::deleteMin() {
	if (heap_size <= 0) {
		cout << "No entity in heap";
		return T();
	}
	if (heap_size == 1) {
		heap_size--;
		return heapArr[0];
	}
	T topElement = heapArr[0];
	heapArr[0] = heapArr[--heap_size];
	heapOrder(0);
	return topElement;
}
template<class T>
void Heap<T>::print() {
	for (int i = 0; i < heap_size; ++i) {
		cout << heapArr[i] << endl;
	}
}
template<class T>
bool Heap<T>::is_empty() {
	return heap_size == 0;
}
template<class T>
Heap<T>::~Heap() {
	if (capacity != 0) {
		delete []heapArr;
	}
}


