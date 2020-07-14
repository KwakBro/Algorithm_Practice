
#include<iostream>
using namespace std;

class CyclicShiftHashCode {
public:
	int operator() (const string key) {
		int len = key.length();
		unsigned int h = 0;
		for (int i = 0; i < len; i++) {
			h = (h << 5) | (h >> 27);
			h += (unsigned int)key.at(i);
		}
		return h;
	}
};