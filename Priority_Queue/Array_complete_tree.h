#ifndef TREE_H
#define TREE_H

#include<iostream>
using namespace std;
template<class E>
class Array_CompleteTree {
	enum { DEF_CAPACITY = 100};
private:
	E *pArray_CT;
	int numTN;
public:

	class Position {
	private:
		E *pTN;
	public:
		Position(E *_v = NULL) :
			pTN(_v) {}
		void setpTN(E *pE) { pTN = pE; }
		E* getpTN() { return pTN; }
		E& operator*() { return *pTN; }
		Position operator+(int i) {
			setpTN(pTN + i);
			return *this;
		}
		Position operator-(Position rpos) {
			return pTN - rpos.getpTN();
		}
	};

protected:
	Position pos(int i) { return Position(pArray_CT + i); }		// 시작점부터 i 번째 인덱스에 해당하는 포지션 변수 반환.
	int idx(Position& p) { return (p.getpTN() - pos(0).getpTN()); }	// 현재 포지션 주소변수 - 루트 포지션 주소변수
public:
	Array_CompleteTree(int cap = DEF_CAPACITY) {
		pArray_CT = new E[cap];
		numTN = 0;
	}
	int size() const { return numTN; }
	Position left(Position& p){
		return pos((2 * idx(p)) + 1);		//idx는 그냥 index 인가보다.
	}
	Position right(Position& p) {
		return pos((2 * idx(p)) + 2);
	}
	Position parent(Position& p) {
		return pos((int)(idx(p)-1 / 2.0));
	}
	bool hasLeft(Position& p) {
		return ( ( 2 * idx(p) ) +1 < numTN);
	}
	bool hasRight(Position& p) {
		return ( ( 2 * idx(p) ) + 2 < numTN);
	}
	bool isRoot(Position& p) {
		return (idx(p) == 0);
	}
	Position getRoot() { return pos(0); }
	Position getLast() { return pos(numTN-1); }
	E& getElem(Position& p) {
		return *p;
	}
	void addLast(const E& eNode) {
		pArray_CT[numTN] = eNode;
		numTN++;
	}
	void removeLast() { numTN--; }
	void swap(Position& p, Position& q) {
		E temp = *p;
		*p = *q;
		*q = temp;
	}
	void printArrayCompleteTreeByLevel(Position p, int level, ostream& fout) {
		Position child;
		if (level == 0) { // 루트 나타내기
			fout << endl << "Root ( data : ";
			fout << *p << " )" << endl;
		}

		for (int i = 0; i < level; i++)
			fout << "    ";
		if (hasLeft(p) == true) {
			child = left(p);
			fout << "L ( data : " << *left(p) << " )" << endl;			// data 들 출력하기 Task
			printArrayCompleteTreeByLevel(child, level + 1, fout);
		}
		else {
			fout << "L ( NULL )" << endl;
		}


		for (int i = 0; i < level; i++)
			fout << "    ";
		if (hasRight(p) == true) {
			child = right(p);
			fout << "R ( data : " << *right(p) << " )" << endl;
			printArrayCompleteTreeByLevel(child, level + 1, fout);
		}
		else {
			fout << "R ( NULL )" << endl;
		}

	}
};

#endif