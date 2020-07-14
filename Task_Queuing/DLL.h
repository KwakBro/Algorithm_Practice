#pragma once
#include<iostream>
using namespace std;

template<typename E>
class T_DN {
public:
	T_DN() { };
	const E& getElem() const { return elm; }
	void setElem(const E e) { elm = e; }
	T_DN* getPrev() { return prev; }
	T_DN* getNext() { return next; }
	void setPrev(T_DN* p) { prev = p; }
	void setNext(T_DN* n) { next = n; }
private:
	E elm;
	T_DN* prev;
	T_DN* next;
};

template<typename E>
class T_DLL {
public:
	T_DLL() {
		num_entry = 0;
		header = new T_DN<E>;
		trailer = new T_DN<E>;
		header->setNext(trailer);
		trailer->setPrev(header);
	}
	~T_DLL() {
		while (!empty()) {
			removeFront();
		}
		delete header;
		delete trailer;
	}
	bool empty() {
		if (header->getNext() == trailer)
			return true;
		return false;
	}
	const E& front() const {
			return (header->getNext())->getElem();
	}
	const E& back()  {
			return (trailer->getPrev())->getElem();
	}
	void addFront(const E& e) {
		T_DN<E> *temp = new T_DN<E>;
		temp->setElem(e);
		temp->setPrev(header);
		temp->setNext(header->getNext());
		(header->getNext())->setPrev(temp);
		header->setNext(temp);
		num_entry++;
	}
	void addBack(const E& e) {
		T_DN<E> *temp = new T_DN<E>;
		temp->setNext(trailer);
		temp->setPrev(trailer->getPrev());
		(trailer->getPrev())->setNext(temp);
		trailer->setPrev(temp);
		num_entry++;
	}
	void removeFront() {
		if (empty()) {
			cout << " DLL is empty!";
			exit(1);
		}
		else {
			T_DN<E> *A = header;
			T_DN<E> *B = header->getNext()->getNext();
			T_DN<E> *C = header->getNext();
			A->setNext(B);
			B->setPrev(A);
			delete C;
			num_entry--;
		}
	}
	void removeBack() {
		if (empty()) {
			cout << " DLL is empty!";
			exit(1);
		}
		else {
			T_DN<E> *A = trailer->getPrev()->getPrev();
			T_DN<E> *B = trailer;
			T_DN<E> *C = trailer->getPrev();
			A->setNext(B);
			B->setPrev(A);
			delete C;
			num_entry--;
		}
	}
	int getNumEntry() {
		return num_entry;
	}
private:
	int num_entry;
	T_DN<E>* header;
	T_DN<E>* trailer;
};
