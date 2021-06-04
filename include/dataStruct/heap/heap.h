#include "../tree/tree.h"

template <class T> class Heap : private Tree {
public:	
	typedef Tree<T>::Node Node;
	Heap(): Tree(){}
	Heap(T a): Tree(a){}
	virtual ~Heap(){ Tree<T>::Clean(); }
	void Push(T value);
	void Pop();
	void Top(T value);
private:
	void insert(Node *& subTree, Node* p_node);
};

template <class T> void Heap<T>::Push(T value) {
	auto pNode = new Tree<T>::Node(value);
	return insert(root, pNode);		
}

template <class T>  Heap<T>::Node* Heap<T>::Pop(T value) {

}

template <class T> Heap<T>::Node* Heap<T>::Top(T value) {
	return Tree<T>::root;
}

template <class T> void insert(Node *& subTree, Node* p_node) {
// todo
	if ( subTree == nullptr ) {
		subTree = p_node;
		return;
	}
	
	if ( subTree->data > p_node ) {
		insert(subTree->L, p_node);	
		insert(subTree->R, p_node);	
	} else {
		auto temp = subTree;
		subTree = p_node;
		p_node->L = temp;
		p_node->R = temp->R;
		temp->R = nullptr;
		return;
	}
}
