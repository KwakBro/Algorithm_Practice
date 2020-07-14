#include"HashMap.h"

template<typename K , typename V , typename H>
class HashDict : public HashMap<K, V, H> {
public:
	typedef HashMap<K, V, H>::Iterator Iterator;

	class Range {
	private:
		Iterator _begin;
		Iterator _end;
	public:
		Range() {}
		Range(const Iterator& start , const Iterator& end) :
			_begin(start) , _end(end) { }
		Iterator& begin() { return _begin; }
		Iterator& end() { return _end; }
	};
public:
	HashDict(int capacity = 101) :
		HashMap(capacity) {}
	Range findAll(const K& k) {
		Iterator b = finder(k);
		Iterator p = b;
		while (!endOfBkt(p) && (*p).key() == (*b).key())
			++p;
		return Range(b, p);
	}
	Iterator insert(const K& k, const V& v) {
		Iterator p = finder(k);
		Iterator q = inserter(p, Entry(k, v));
		return q;

	}
	void printALL() {
		Iterator T = begin();
		for (int i = 0; i < size(); i++) {
			cout << *T;
			++T;
		}
	}
	void printALL(const K& k) {
		Range temp;
		temp = findAll(k);
		Iterator T = temp.begin();
		Iterator TA = temp.end();
		do {
			cout << *(T);
			++T;
			if (*T == *TA)
				break;
		} while (1);
	}
};