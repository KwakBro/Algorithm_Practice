#include<iostream>
#include"MyVoca.h"
using namespace std;

Struct_Voca myTOEICVocaList[] = {
	/*{ (string)"A" , NOUN , {"AMEAw" , " dsdsd " } ,{" ILOVE YOU"} },
	{ (string)"A" , NOUN ,{ "AMEA", " dsdsds D " , " DSdsd " } ,{ " ILOVE YOU" } },
	{ (string)"B" , NOUN ,{ "BMEA" } ,{ " ILOVE YOU" } },
	{ (string)"C" , NOUN ,{ "CMEA" } ,{ " ILOVE YOU" } },
	{ (string)"-1" , NOUN ,{ "CMEA" } ,{ " ILOVE YOU" } },*/
	{ (string)"풍부한" , (string)"abundant" , ADJ , { "plentiful" , "copious" , "rich" , "profuse" , "ample"} , {" I have abundant hair . "} } ,
	{ (string)"업적 , 공적" , (string)"accomplishment" , NOUN ,{ "achievement","triumph","success","deed","feat" } ,{ " I have accomplishment of world war II ." } } ,
	{ (string)"완수" , (string)"accomplishment" , NOUN ,{ "completion","execution","finishing","realization","attainment" } ,{ " I have experience that accomplishment of LAB ." } } ,
	{ (string)"재주 , 기량" , (string)"accomplishment" , NOUN ,{ "skill","talent","ability","expertise","capability" } ,{ " I have accomplishment of programming ." } } ,
	{ (string)"-를 묶다,합치다." , (string)"bring together" , VERB ,{ "combine","mix","blend","concentrate","focus" } ,{ " Bread maked by bring together with meal and water ." } } ,
	{ (string)"-를 화해시키다." , (string)"bring together" , VERB ,{ "gather","amass","rally","compile","collect" } ,{ " My friend bring to with his friend who were fighten ." } } ,
	{ (string)"-를 재결합시키다." , (string)"bring together" , VERB ,{ "recognize","integrate","unite","link","organize" } ,{ " North Korea and South Korea can not bring together . " } } ,
	{ (string)"도전자 , 후보자" , (string)"candidate" , NOUN ,{ "applicant","contender","entrant","aspirant","nominee" } ,{ " There are three candidate of president." } } ,
	{ (string)"-를 찾아내다." , (string)"come up with" , VERB ,{ "discover","create","produce","supply","procure" } ,{ " Can you come up with my pencil ? " } } ,
	{ (string)"적합한 , 어울리는" , (string)"commensurate" , ADJ ,{ "equal","proportionate","corresponding","appropriate","adequate" } ,{ " He is commensurate candidate to be leader . " } } ,
	{ (string)"경쟁,경기" , (string)"match" , NOUN ,{ "competition","game","contest","tie" } ,{ " I love soccer match . " } } ,
	{ (string)"배우자 , 짝" , (string)"match" , NOUN ,{ "equal","counterpate","pair","partner" } ,{ " I love my match who meeted 1 years early." } } ,
	{ (string)"조직화하다 , 조정하다." , (string)"match" , VERB ,{ "complement","harmonize","accord","coordinate" } ,{ " We match our academy schedule . " } } ,
	{ (string)"일치하다 , 부합하다." , (string)"match" , VERB ,{ "correspond","tally","fit","equal" } ,{ " My gene is matched with my fathers gene . " } } ,
	{ (string)"윤곽 , 옆모습" , (string)"profile" , NOUN ,{ "outline","shape","silhouette","contour","side view"} ,{ " What a pretty profile ! " } } ,
	{ (string)"요약 , 개요" , (string)"profile" , NOUN ,{ "summary","sketch","outline","report","precis" } ,{ " Please send me your profile . " } } ,
	{ (string)"묘사하다." , (string)"profile" , VERB ,{ "summarize","sketch","describe" } ,{ " Can you profile me suspects face ? " } } ,
	{ (string)"단서, 조건" , (string)"qualification" , NOUN ,{ "requirement","prerequisite","condition","criterion","proviso" } ,{ " We fine qualification of this crime . " } } ,
	{ (string)"자격" , (string)"qualification" , NOUN ,{ "ability","aptitude","skill","attribute","talent" } ,{ " You have to have qualification of driving before buy your car ." } } ,
	{ (string)"신입 사원 , 회원 , 신병 등" ,  (string)"recruit" , NOUN ,{ "employee","trainee","beginner","novice","newcomer" } ,{ " Our company have many revruit . " } } ,
	{ (string)"모집하다 , 고용하다." , (string)"recruit" , VERB ,{ "employ","enlist","draft","engage","hire" } ,{ " Our company recruit ambitious human . " } } ,
	{ (string)"제출하다." , (string)"submit" , VERB ,{ "succumb","acquiesce","defer to","bow to","yield to" } ,{ " You should submit your report ." } } ,
	{ (string)"말하다 , 진술하다." , (string)"submit" , VERB ,{ "present","propose","offer","suggest","tender" } ,{ " Submit your acomplice is good for you . " } } ,
	{ (string)"항복하다 , 굴복하다" , (string)"submit" , VERB ,{ "surrender","yield","accept","acquiesce","give in","resist" } ,{ " We submit in 20 minutes " } } ,
	{ (string)"힘든 , 비효율적인" , (string)"time-consuming" , ADJ ,{ "laborious","slow","inefficient","long","onerous" } ,{ " This is time-consuming way to go . " } },
	{ (string)"" , (string)"-1" , NOUN ,{ "" } ,{ "" } },
}