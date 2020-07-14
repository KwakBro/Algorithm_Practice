#ifndef QUE_H
#define QUE_H

#include"Array_complete_tree.h"
#include"Task.h"

template<class E>
class HeapPriorityQueue {
private:
	Array_CompleteTree<E> acTree;
public:
	typedef typename Array_CompleteTree<E>::Position Position;
	HeapPriorityQueue() {}
	int size() const { return acTree.size(); }
	bool empty() const { return size() == 0; }
	Array_CompleteTree<E>* getacTree() { return &acTree; }
	Task getMin() {
		return *acTree.getRoot();
	}
	void insert(const Task& e) {
		acTree.addLast(e);
		Position Last = acTree.getLast();
		while (acTree.isRoot(Last) == false) {
			Position pare = acTree.parent(Last);
			if (*pare > *Last) {		// Pare 과 Last 의 Task -> Priority 비교
				acTree.swap(pare, Last);		//값만 바꿈.
				Last.setpTN(pare.getpTN());	// 연산은 끝났지만 실질적 포지션 까지 바꾸기 위함.
				continue;
				}		// if 문 끝

				break;
		}	//while 문 끝
	}	//insert 함수 끝.
	void removeMin() {
		if (size() == 1)
			acTree.removeLast();
		else {
			Position tree_root = acTree.getRoot();
			Position tree_last = acTree.getLast();

			acTree.swap(tree_root, tree_last);
			acTree.removeLast();				// 값 바꾸고 최소였던놈 날려버림.

			while (acTree.hasLeft(tree_root) == true) {
				Position to_comp = acTree.left(tree_root);
				if (acTree.hasRight(tree_root) == true)
					if( *acTree.left(tree_root) > *acTree.right(tree_root) )
						to_comp = acTree.right(tree_root);

				if (*tree_root > *to_comp) {		// Pare 과 Last 의 Task -> Priority 비교
					acTree.swap(tree_root, to_comp);
					tree_root.setpTN(to_comp.getpTN());
					// 연산은 끝났지만 실질적 포지션 까지 바꾸기 위함.
					continue;
				}
				break;
			}	// while 끝

		}	// else 끝
	}	// removeMin 끝

};

#endif