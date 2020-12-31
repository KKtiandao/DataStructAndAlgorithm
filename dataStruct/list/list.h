#include "../common/node.h"

template <class T> class List {
	public:
		List(){
			head = new Node<T>();
			head->next = nullptr;
			tail = head;
			size = 0;
		}
		virtual ~List(){
			Clear();
		};
		List(Node<T>* a):head(a), tail(a){};
		
		bool Erase(Node<T>* a);
		bool Clear();
		
		bool PushFront(Node<T>* a);
		bool PushBack(Node<T>* a);
		
		bool PushFront(T a);
		bool PushBack(T a);
		
		Node<T>* PopFront();
		Node<T>* PopBack();
		
		int Size() const;
		void Sort();
		void Dump() const;
		
		Node<T>* Tail() const;
		Node<T>* Head() const;
	protected:
		Node<T>* head;
		Node<T>* tail;
		int size;
};

int test();

template <class T>
int List<T>::Size() const{
	return size;
}

template <class T>
bool List<T>::Clear(){
	while (head->next != nullptr)  {
		auto p = head;
		head = head->next;
		delete p;
	}
	tail = head;
	size = 0;
	return true;
}

template <class T>
bool List<T>::PushFront(T a){
	auto pNode = new Node<T>(a);
	return PushFront(pNode);
}

template <class T>
bool List<T>::PushBack(T a){
	auto pNode = new Node<T>(a);
	return PushBack(pNode);
}

template <class T>
bool List<T>::PushFront(Node<T>* a){
	std::cout<< __FILE__ << __FUNCTION__ << __LINE__ << std::endl;
	a->next = head->next;
	head->next = a;
	size++;
	return true;
}

template <class T>
bool List<T>::PushBack(Node<T>* a){
	std::cout<< __FILE__ << __FUNCTION__ << __LINE__ << std::endl;
	tail->next = a;
	tail = a;
	size++;
	return true;
}

template <class T>
Node<T>* List<T>::PopFront(){
	auto result = head->next;
	if (result->next != nullptr) {
		head->next = result->next;
	}
	size--;
	return result;
}

template <class T>
Node<T>* List<T>::PopBack(){
	auto result = tail;
	auto p = head;
	auto t = p->next;
	while (t != nullptr) {
		p = p->next;
	    t = p->next;
		if (t == tail) {
			p->next = nullptr;
			tail = p;
			size--;
			break;
		}	
	}
	return result;
}

template <class T>
void List<T>::Dump() const {
	std::cout<< __FILE__ << __FUNCTION__ << __LINE__ << std::endl;
	auto pNode = head->next;
    while ( pNode != nullptr ) {
		pNode->Print();
		pNode = pNode->next;
	}	
}
