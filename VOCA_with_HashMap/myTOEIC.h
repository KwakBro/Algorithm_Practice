#include<iostream>
#include"MyVoca.h"
using namespace std;

Struct_Voca myTOEICVocaList[] = {
	/*{ (string)"A" , NOUN , {"AMEAw" , " dsdsd " } ,{" ILOVE YOU"} },
	{ (string)"A" , NOUN ,{ "AMEA", " dsdsds D " , " DSdsd " } ,{ " ILOVE YOU" } },
	{ (string)"B" , NOUN ,{ "BMEA" } ,{ " ILOVE YOU" } },
	{ (string)"C" , NOUN ,{ "CMEA" } ,{ " ILOVE YOU" } },
	{ (string)"-1" , NOUN ,{ "CMEA" } ,{ " ILOVE YOU" } },*/
	{ (string)"ǳ����" , (string)"abundant" , ADJ , { "plentiful" , "copious" , "rich" , "profuse" , "ample"} , {" I have abundant hair . "} } ,
	{ (string)"���� , ����" , (string)"accomplishment" , NOUN ,{ "achievement","triumph","success","deed","feat" } ,{ " I have accomplishment of world war II ." } } ,
	{ (string)"�ϼ�" , (string)"accomplishment" , NOUN ,{ "completion","execution","finishing","realization","attainment" } ,{ " I have experience that accomplishment of LAB ." } } ,
	{ (string)"���� , �ⷮ" , (string)"accomplishment" , NOUN ,{ "skill","talent","ability","expertise","capability" } ,{ " I have accomplishment of programming ." } } ,
	{ (string)"-�� ����,��ġ��." , (string)"bring together" , VERB ,{ "combine","mix","blend","concentrate","focus" } ,{ " Bread maked by bring together with meal and water ." } } ,
	{ (string)"-�� ȭ�ؽ�Ű��." , (string)"bring together" , VERB ,{ "gather","amass","rally","compile","collect" } ,{ " My friend bring to with his friend who were fighten ." } } ,
	{ (string)"-�� ����ս�Ű��." , (string)"bring together" , VERB ,{ "recognize","integrate","unite","link","organize" } ,{ " North Korea and South Korea can not bring together . " } } ,
	{ (string)"������ , �ĺ���" , (string)"candidate" , NOUN ,{ "applicant","contender","entrant","aspirant","nominee" } ,{ " There are three candidate of president." } } ,
	{ (string)"-�� ã�Ƴ���." , (string)"come up with" , VERB ,{ "discover","create","produce","supply","procure" } ,{ " Can you come up with my pencil ? " } } ,
	{ (string)"������ , ��︮��" , (string)"commensurate" , ADJ ,{ "equal","proportionate","corresponding","appropriate","adequate" } ,{ " He is commensurate candidate to be leader . " } } ,
	{ (string)"����,���" , (string)"match" , NOUN ,{ "competition","game","contest","tie" } ,{ " I love soccer match . " } } ,
	{ (string)"����� , ¦" , (string)"match" , NOUN ,{ "equal","counterpate","pair","partner" } ,{ " I love my match who meeted 1 years early." } } ,
	{ (string)"����ȭ�ϴ� , �����ϴ�." , (string)"match" , VERB ,{ "complement","harmonize","accord","coordinate" } ,{ " We match our academy schedule . " } } ,
	{ (string)"��ġ�ϴ� , �����ϴ�." , (string)"match" , VERB ,{ "correspond","tally","fit","equal" } ,{ " My gene is matched with my fathers gene . " } } ,
	{ (string)"���� , �����" , (string)"profile" , NOUN ,{ "outline","shape","silhouette","contour","side view"} ,{ " What a pretty profile ! " } } ,
	{ (string)"��� , ����" , (string)"profile" , NOUN ,{ "summary","sketch","outline","report","precis" } ,{ " Please send me your profile . " } } ,
	{ (string)"�����ϴ�." , (string)"profile" , VERB ,{ "summarize","sketch","describe" } ,{ " Can you profile me suspects face ? " } } ,
	{ (string)"�ܼ�, ����" , (string)"qualification" , NOUN ,{ "requirement","prerequisite","condition","criterion","proviso" } ,{ " We fine qualification of this crime . " } } ,
	{ (string)"�ڰ�" , (string)"qualification" , NOUN ,{ "ability","aptitude","skill","attribute","talent" } ,{ " You have to have qualification of driving before buy your car ." } } ,
	{ (string)"���� ��� , ȸ�� , �ź� ��" ,  (string)"recruit" , NOUN ,{ "employee","trainee","beginner","novice","newcomer" } ,{ " Our company have many revruit . " } } ,
	{ (string)"�����ϴ� , ����ϴ�." , (string)"recruit" , VERB ,{ "employ","enlist","draft","engage","hire" } ,{ " Our company recruit ambitious human . " } } ,
	{ (string)"�����ϴ�." , (string)"submit" , VERB ,{ "succumb","acquiesce","defer to","bow to","yield to" } ,{ " You should submit your report ." } } ,
	{ (string)"���ϴ� , �����ϴ�." , (string)"submit" , VERB ,{ "present","propose","offer","suggest","tender" } ,{ " Submit your acomplice is good for you . " } } ,
	{ (string)"�׺��ϴ� , �����ϴ�" , (string)"submit" , VERB ,{ "surrender","yield","accept","acquiesce","give in","resist" } ,{ " We submit in 20 minutes " } } ,
	{ (string)"���� , ��ȿ������" , (string)"time-consuming" , ADJ ,{ "laborious","slow","inefficient","long","onerous" } ,{ " This is time-consuming way to go . " } },
	{ (string)"" , (string)"-1" , NOUN ,{ "" } ,{ "" } },
}