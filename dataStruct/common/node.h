#ifndef NODE_H
#define NODE_H
#include <iostream> 

template <class T> class Node {
public:
	T data;
	Node* next;
	Node* pre;
	Node():next(nullptr), pre(nullptr) {}
	Node(T a):data(a), next(nullptr), pre(nullptr){
}
	void Print() {
		std::cout<< "Print:"<< data <<std::endl;
	}
};

#endif
