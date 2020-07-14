
#include<iostream>
#include<list>
#include<string>
using namespace std;

enum Word_type {NOUN , VERB , ADJ , ADV , PREPOS};
string wd_ty[] = { "n" , "v" , "adj" , "adv" , "prepos" };

typedef list<string> List_Str;
typedef list<string>::iterator List_Str_Itr;

typedef struct Struct_Voca {
	string mean;				//////////////
	string w;
	Word_type type;
	List_Str thes;
	List_Str usg;
} Struct_Voca ;

class MyVoca {
	friend ostream& operator <<(ostream& out, MyVoca& right) {
		out << " " << right.word << " ( ";
		switch (right.type) {
		case(0) :
			out << wd_ty[0];
			break;
		case(1) :
			out << wd_ty[1];
			break;
		case(2) :
			out << wd_ty[2];
			break;
		case(3) :
			out << wd_ty[3];
			break;
		case(4) :
			out << wd_ty[4];
			break;
		}
		out << " ) : " << right.mean << endl;			////////////////
		out << "    - Thesaurus ( ";	// 동의어 리스트 출력.
		List_Str_Itr temp = right.thesaurus.begin();
		for (int i = 0; i < right.thesaurus.size(); i++) {
			out << *(temp++) << " , ";
		}
		out << ")" << endl;

		out << "    - Usage ( ";	// 사용 리스트 출력.
		temp = right.usages.begin();
		for (int i = 0; i < right.usages.size(); i++) {
			out << *(temp++) ;
		}
		out << " )" << endl << endl;
		return out;
	}
public:
	MyVoca(string mean , string entry, Word_type wt, List_Str thes, List_Str ex_usg) :
		mean(mean) , word(entry), type(wt), thesaurus(thes), usages(ex_usg) {}		//////////
	MyVoca(Struct_Voca temp) {
		word = temp.w;
		type = temp.type;
		thesaurus = temp.thes;
		usages = temp.usg;
		mean = temp.mean;		/////////////////
	}
	bool operator ==(MyVoca A) {
		if (A.word == this->word)
			return true;
		return false;
	}
	MyVoca() {}			// V() 에 해당하는 부분이노
private:
	string mean;			//////////////
	string word; 
	Word_type type;
	List_Str thesaurus;
	List_Str usages;
};