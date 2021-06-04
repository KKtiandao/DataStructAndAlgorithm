#include "list.h"

//template <class T>
//List<T>::~List() {
//	Clear();
//}

template <class T>
bool List<T>::Erase(Node<T>* a){
	return true;
}

//template <class T>
//bool List<T>::PushFront(Node<T>* a){
//	a->next = head->next;
//	head->next = a;
//	size++;
//	return true;
//}
//
//template <class T>
//bool List<T>::PushBack(Node<T>* a){
//	tail->next = a;
//	tail = a;
//	size++;
//	return true;
//}

//template <class T>
//int List<T>::Size() const{
//	return size;
//}

template <class T>
void List<T>::Sort(){

}

template <class T>
Node<T>* List<T>::Tail() const{
	return tail;
}

template <class T>
Node<T>* List<T>::Head() const{
	return head;
}

