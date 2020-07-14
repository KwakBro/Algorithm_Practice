#include<iostream>
#include<string>
#include"HashDict.h"
#include"MyTOEIC.h"
#include"Çì´õ.h"
using namespace std;

#define HASH_DICT_CAPACITY 101
int main() {
	typedef HashDict<string, MyVoca, CyclicShiftHashCode> HashDict;
	typedef HashMap<string, MyVoca, CyclicShiftHashCode>::Iterator Iterator;
	Struct_Voca *pSV;
	string word;
	Word_type type;
	List_Str thesaurus, usages;
	List_Str_Itr sv_itr;
	int word_count;
	MyVoca mv;
	HashDict myVocaDic(HASH_DICT_CAPACITY);
	Iterator itr;
	
	cout << " Testing Hash Dictionary" << endl;
	cout << " Inserting My TOEIC Vocabularies to myVocaDict . . ." << endl;
	word_count = 0;
	for (pSV = &myTOEICVocaList[0] ; pSV->w != "-1"; pSV = &myTOEICVocaList[word_count++])
	{
		pSV = &myTOEICVocaList[word_count];
		word = pSV->w;
		if (word == "-1")
			break;
		myVocaDic.insert(word, *pSV);
	}

	cout << "  Total " << myVocaDic.size() << " words in my Voca_Dictionary . ." << endl;
	myVocaDic.printALL();
	
	string testWord = "match";
	HashDict::Range range;
	myVocaDic.printALL(testWord);
} 
