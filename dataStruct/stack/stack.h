#ifndef STACK_H
#define STACK_H
#include "../list/list.h"
template <class T> class Stack : public List<T> {
public:
	Stack(): List<T>(){}
	Stack(T a): List<T>(a) {}
	bool Push(T a);
	Node<T>* Pop();
};

template <class T> bool Stack<T>::Push(T a) {
	auto pNode = new Node<T>(a);
	return List<T>::PushFront(pNode);
}

template <class T> Node<T>* Stack<T>::Pop() {
	return List<T>::PopFront();
}

#endif 
