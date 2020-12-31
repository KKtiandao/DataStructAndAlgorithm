#include "list.h"

template <class T> class BiList: public List<T> {
	public:
		BiList(): List<T>(){
			List<T>::head->pre = nullptr;
		}
		
		bool PushFront(Node<T>* a);
		bool PushBack(Node<T>* a);
		bool PushFront(T a);
		bool PushBack(T a);
		
		Node<T>* PopFront();
		Node<T>* PopBack();
		
		void DumpFromBack() const;
};

template <class T> 
bool BiList<T>::PushFront(Node<T>* a){
	a->next = List<T>::head->next;
	List<T>::head->next->pre = a;
	a->pre = List<T>::head;
	List<T>::head->next = a;
	List<T>::size++;	
}

template <class T> 
bool BiList<T>::PushBack(Node<T>* a){
	List<T>::tail->next = a;
	a->pre = List<T>::tail;
	List<T>::tail = a;
	List<T>::size++;
}


template <class T> 
bool BiList<T>::PushFront(T a) {
	auto pNode = new Node<T>(a);
	PushFront(pNode);
}

template <class T> 
bool BiList<T>::PushBack(T a) {
	auto pNode = new Node<T>(a);
	PushBack(pNode);
}


template <class T> 
Node<T>* BiList<T>::PopFront(){
	if (List<T>::size == 0) {
		return nullptr;	
	}
	
	auto result = List<T>::head->next;
	if (result != List<T>::tail) {
		result->next->pre = result->pre;
		result->pre->next = result->next;
	} else {
		result->pre = List<T>::tail;
		result->pre->next = nullptr;
		result->pre = nullptr;
	}
	return result;
}

template <class T> 
Node<T>* BiList<T>::PopBack(){
	if (List<T>::size == 0) {
		return nullptr;	
	}
	
	auto result = List<T>::tail;
	result->pre = List<T>::tail;
	result->pre->next = nullptr;
	result->pre = nullptr;
	return result;
}

template <class T> 
void BiList<T>::DumpFromBack() const{
	std::cout<< __FILE__ << __FUNCTION__ << __LINE__ << std::endl;
	auto pNode = List<T>::tail;
    while ( pNode != nullptr ) {
		pNode->Print();
		pNode = pNode->pre;
	}	
}

