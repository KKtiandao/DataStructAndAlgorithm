#ifndef QUENE_H
#define QUENE_H

#include "../list/list.h"


template <class T> class Quene : public List<T> {
public:
	Quene(): List<T>(){}
	Quene(T a): List<T>(a) {}
	bool Push(T a);
	Node<T>* Pop();
//	void Dump();
//	int Size();
};

template <class T> bool Quene<T>::Push(T a) {
	auto pNode = new Node<T>(a);
	return List<T>::PushFront(pNode);
}

template <class T> Node<T>* Quene<T>::Pop() {
	return List<T>::PopBack();
}

//template <class T> void Quene<T>::Dump(){
//	List<T>::Dump();
//}
//
//template <class T> int Quene<T>::Size(){
//	return List<T>::Size();
//}
#endif
