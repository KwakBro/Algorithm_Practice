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
			if (*pare > *Last) {		// Pare �� Last �� Task -> Priority ��
				acTree.swap(pare, Last);		//���� �ٲ�.
				Last.setpTN(pare.getpTN());	// ������ �������� ������ ������ ���� �ٲٱ� ����.
				continue;
				}		// if �� ��

				break;
		}	//while �� ��
	}	//insert �Լ� ��.
	void removeMin() {
		if (size() == 1)
			acTree.removeLast();
		else {
			Position tree_root = acTree.getRoot();
			Position tree_last = acTree.getLast();

			acTree.swap(tree_root, tree_last);
			acTree.removeLast();				// �� �ٲٰ� �ּҿ����� ��������.

			while (acTree.hasLeft(tree_root) == true) {
				Position to_comp = acTree.left(tree_root);
				if (acTree.hasRight(tree_root) == true)
					if( *acTree.left(tree_root) > *acTree.right(tree_root) )
						to_comp = acTree.right(tree_root);

				if (*tree_root > *to_comp) {		// Pare �� Last �� Task -> Priority ��
					acTree.swap(tree_root, to_comp);
					tree_root.setpTN(to_comp.getpTN());
					// ������ �������� ������ ������ ���� �ٲٱ� ����.
					continue;
				}
				break;
			}	// while ��

		}	// else ��
	}	// removeMin ��

};

#endif