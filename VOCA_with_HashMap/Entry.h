#pragma once

#include<iostream>
using namespace std;

template<typename K , typename V>
class Entry {
	friend ostream& operator <<(ostream& out,Entry& right) {
		out << right.value();
		return out;
	}
private:
	K _key;
	V _value;			// My Voca 가 되네.
public:
	Entry(const K& k = K(), const V& v = V()) :		// K() V() 은 뭘까.
		_key(k), _value(v) {}
	const K& key() const { return _key; }
	V& value() { return _value; }
	void setKey(const K& k) { _key = k; }
	void setValue(const V& v) { _value = v; }
	bool operator ==(Entry A) {
		return A._value == this->_value;
	}
};