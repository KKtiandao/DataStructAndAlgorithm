#ifndef TREE_H
#define TREE_H
#include <iostream>

template <class T> class Tree{
public:
    struct Node {
	T data;
	Node* L, *R;

	Node() : L(nullptr), R(nullptr) {
	}

	Node(T a) : data(a), L(nullptr), R(nullptr) {
	}

	void Dump(){ std::cout<< data <<std::endl;}
	};

	Tree() : num(0){
	}
	Tree(T a) : num(1){
		root = new Tree<T>::Node(a);//todo
	}
	virtual ~Tree(){
		Clean();
	}
	Node* GetRoot(){return root;}
	void Insert(T value);
	void PreOrder() const;
	void InOrder() const;
	void PostOrder() const;
	Node* GetMinNode() const;
	Node* GetMaxNode() const;
	void Clean();
	int High() const;
	int Size() const;

	void DeleteNode(T value);
private:
	void insert(Node* &preNode, Node* p_NewNode);
	void preOrder(Node* p) const;
	void inOrder(Node* p) const;
	void postOrder(Node* p) const;
	int  high(Tree<T>::Node* p, int high = 0)const ;
	void DestroySubTree(Tree<T>::Node* &p);
	void DeleteNode(Tree<T>::Node* &p, T value);
	Node* minNode(Node* position) const;
	Node* maxNode(Node* position) const;
	T deleteNode(Tree<T>::Node* & p);
	Node* root;
	int num;
};

template <class T> void Tree<T>::insert(Tree<T>::Node*& Position,  Tree<T>::Node* p_NewNode) {
	if (Position == nullptr) {
		Position = p_NewNode;
		num++;
	} else if (Position->data > p_NewNode->data) {
		insert(Position->L, p_NewNode);
	} else {
		insert(Position->R, p_NewNode);
	}
}

template <class T> void Tree<T>::Insert(T value){
	auto pNode = new Tree<T>::Node(value);
	insert(root, pNode);
}

template <class T> void Tree<T>::PreOrder() const {
	std::cout<<__FILE__<<__FUNCTION__<<__LINE__<<std::endl;
	return preOrder(root);
}

template <class T> void Tree<T>::InOrder() const {
	std::cout<<__FILE__<<__FUNCTION__<<__LINE__<<std::endl;
	return inOrder(root);
}

template <class T> void Tree<T>::PostOrder() const {
	std::cout<<__FILE__<<__FUNCTION__<<__LINE__<<std::endl;
	return postOrder(root);
}

template <class T> void Tree<T>::preOrder(Tree<T>::Node* p) const {
	if (p == nullptr) {
		return;
	} else {
		p->Dump();
		preOrder(p->L);
		preOrder(p->R);
	}
}

template <class T> void Tree<T>::inOrder(Tree<T>::Node* p) const {
	if (p == nullptr) {
		return;
	} else {
		inOrder(p->L);
		p->Dump();
		inOrder(p->R);
	}
}

template <class T> void Tree<T>::postOrder(Tree<T>::Node* p) const {
	if (p == nullptr) {
		return;
	} else {
		postOrder(p->L);
		postOrder(p->R);
		p->Dump();
	}
}

template <class T> typename Tree<T>::Node* Tree<T>::GetMinNode() const{
	return minNode(root);
}
template <class T> typename Tree<T>::Node* Tree<T>::GetMaxNode() const{
	return maxNode(root);
}
template <class T> typename Tree<T>::Node* Tree<T>::minNode(Tree<T>::Node* p) const {
		if (p == nullptr) {
			return nullptr;
		} else if (p->L == nullptr) {
			return p;
		} else {
			auto result = minNode(p->L);
			return result;
		} 
}

template <class T> typename Tree<T>::Node* Tree<T>::maxNode(Tree<T>::Node* p) const {
		if (p == nullptr) {
			return nullptr;
		} else if (p->R == nullptr) {
			return p;
		} else {
			auto result = maxNode(p->R);
			return result;
		} 
	}
template <class T> void Tree<T>::Clean(){
	DestroySubTree(root);	
}

template <class T> void Tree<T>::DestroySubTree(Tree<T>::Node* &p){
	if (p == nullptr) {
		return;
	} else if (p->L == nullptr && p->R == nullptr) {
		deleteNode(p);
	} else {
		DestroySubTree(p->L);
		DestroySubTree(p->R);
		deleteNode(p);
	}
}

template <class T> int Tree<T>::High() const {
	return high(root);
}

template <class T> int Tree<T>::high(Tree<T>::Node* p, int h) const {
	static int result = 0;
	std::cout<<__FILE__<<__FUNCTION__<<__LINE__<<std::endl<< "result:"<<result<< " high:"<<h<<std::endl;
	if (p == root) {
		result = 0;
	}
	if (p) {
		if (p->L != nullptr || p->R != nullptr) {
			++h;
		}
		high(p->L, h);
		high(p->R, h);
	}
	if (h > result) {
		result = h;
	}
	return result; 
}

template <class T> int Tree<T>::Size() const {
	return num;
}

template <class T> void Tree<T>::DeleteNode(T value){
	DeleteNode(root,value);
}

template <class T> void Tree<T>::DeleteNode(Tree<T>::Node* &p, T value){
	if (p == nullptr) {
		return;	
	} else if (p->data == value) {
		deleteNode(p);	
	} else if (p->data < value) {
		DeleteNode(p->R, value);
	} else {
		DeleteNode(p->L, value);
	}
}

template <class T> T Tree<T>::deleteNode(Tree<T>::Node* &p){
	if (p == nullptr) {
		std::cout<< "null pointer err" << std::endl;
	}
	auto temp = p;
	auto result = p->data;
    if (p->R == nullptr) {
		p = p->L; 
		auto result = temp->data;
		delete temp;
	} else {
		auto minNode = p->R;
		while (minNode->L) {
			minNode = minNode->L;
		}
		minNode->L = p->L;
		p = p->R;
		delete temp;
		// 二叉树退化
	}
	num--;
	return result;
}

#endif
