///--------copysight by hongwei dong (hwdong.com)---------------
#include "SqList.h"
#include <iostream>
using std::cout;

int main(){
	SqList L;
	InitList(L);
	ElemType e;

	e.name  = "Li"; e.score = 77;
	ListInsert(L,1,e);

	e.name  = "Wang"; e.score = 87;
	ListInsert(L,2,e);

	e.name  = "Zhang"; e.score = 27;
	ListInsert(L,3,e);

	e.name  = "KKKKK";
	ListSet(L,2,e);

	for(int i = 1;i<=L.length;i++){
		ListGet(L,i,e);
		cout<<e.name<<" "<<e.score<<"\n";
	}
	cout<<"\n";

	DestoryList(L);
	return 0;
}