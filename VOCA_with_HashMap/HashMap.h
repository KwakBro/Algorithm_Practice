#pragma once
#include<iostream>
#include<list>
#include<vector>
#include"Entry.h"
using namespace std;


template<typename K , typename V , typename H>
class HashMap {
public:
	typedef Entry<const K, V> Entry;

	typedef list<Entry> Bucket;			// Entry Ŭ������ ���ø� �μ� ������ص� �ǳ�? ��?

	typedef vector<Bucket> BktArray;

	typedef typename BktArray::iterator BItor; // Bucket ������ ������ Itor.

	typedef typename Bucket::iterator EItor; // Entry �� ���� ����Ʈ�� Itor.

private:
	int n;
	H hash;
	BktArray B;
public:
	class Iterator {
		friend class HashMap;
	private:
		EItor ent;
		BItor bkt;
		const BktArray *ba;
	public:
		Iterator() {}
		Iterator(const BktArray& a, const EItor& b, const BItor& c) :
			ba(&a), ent(b), bkt(c) {}
		Iterator(const BktArray& a, const BItor& c) :
			ba(&a), bkt(c) {}
		Entry& operator*() { return *ent; }
		V getValue() {
			Entry& e = *ent;
			return e.value();
		}
		bool operator == (const Iterator& right) {
			if (this->bkt != right.bkt)
				return false;
			if (this->ent != right.ent)
				return false;
			return true;
		}
		bool operator != (const Iterator& right) {
			if (this->bkt == right.bkt)
				if (this->ent == right.ent)
				return false;
			return true;
		}
		Iterator& operator++() {
			++ent;
			if (endOfBkt(*this)) {		// this �� �ް� ��Ŷ�� ������ ��.
				do {
					++bkt;
				} while (bkt != ba->end() && bkt->empty());

				if (bkt == ba->end())
					return *this;

				ent = bkt->begin();
			}
			return *this;
		}
	};
public:
	HashMap(int capacity = 101) :
		n(0), B(capacity) {}	// ���� ����� �� �뷮�� 101 ( Ȧ���ؾ� �� )
	int size() const { return n; }
	bool empty() { return (n == 0); }
	Iterator find(const K& k) {
		Iterator temp = finder(k);
		if (endOfBkt(temp))
			return end();
		else
			return temp;
	}
	Iterator put(const K& k, const V& v) {
		Iterator p = finder(k);
		if (endOfBkt(p)) {
			return inserter(p,Entry(k,v)) // �˻���� ��� ������.
		}
		else {
			p.ent->setValue(v);
			return p;
		}
	}
	void erase(const K& k) {
		Iterator p = finder(k);
		if (endOfBkt(p))
			throw "Erase of nonexistent";
		eraser(p);
	}
	void erase(const Iterator& p) {
		eraser(p);
	}
	Iterator begin() {
		if (empty())
			return end();
		BItor bkt = B.begin();

		while (bkt->empty())
			bkt++;

		return Iterator(B, bkt->begin(), bkt);
	}
	Iterator end() {
		return Iterator(B,B.end());
		}
protected:
	Iterator& finder(const K& k) {
		int i = hash(k) % B.size();
		BItor bkt = B.begin() + i;			// �ؽ� �ڵ�� ���� �̵�
		Iterator* p = new Iterator(B, bkt->begin(), bkt);
		while (!endOfBkt(*p) && (*(*p)).key() != k)
			nextEntry(*p);		// Ž������! - ���ų� ���������ϸ� ����
		return *p;
	}
	Iterator inserter(const Iterator& p, const Entry& e) {
		EItor temp = p.bkt->insert(p.ent, e);	// ���� ����Ű�� entry ������ ����
		n++;
		return Iterator(B, temp, p.bkt);
	}
	void eraser(const Iterator& p) {
		p.bkt->erase(p.ent);
		n--;
	}
	static void nextEntry(Iterator& p) { ++(p.ent); }	
	static bool endOfBkt(Iterator& p) {
		return p.ent == p.bkt->end();
	}
};