///--------copysight by hongwei dong (hwdong.com)---------------
// SqList.cpp: implementation of the SqList class.
//
//////////////////////////////////////////////////////////////////////

#include "SqList.h"
#include <malloc.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//void exit(int r){}

int InitList(SqList &L){
/*	L.elem = (ElemType*)malloc
	         (LIST_INIT_SIZE*
          	 sizeof(ElemType));*/
	L.elem = new ElemType[LIST_INIT_SIZE];
	if(!L.elem)	return 1;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 0;
}

int ListInsert(SqList &L, int i, ElemType e)
{
	// �ж�i�Ƿ�Ϸ�
	if(i < 1 || i > L.length + 1)
		return ERROR;
	// �����Ա�ռ䲻�㣬�ٷ���һЩ�ռ�
	if(L.length >= L.listsize)
	{
		ElemType *newbase = new ElemType[L.listsize+LISTINCREMENT];		
		if(!newbase)	exit(OVERFLOW);
		for(int i = 0;i<L.length;i++){
			newbase[i] = L.elem[i];
		}
		delete[] L.elem;	
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	/*
	// qָ������λ��
	ElemType *q = &(L.elem[i-1]);  
	// pָ�����һ��Ԫ�أ�
	// ��p��q������Ԫ�غ���һ����Ԫ
	for(ElemType *p = &(L.elem[L.length - 1]);
					p >= q; --p)
		*(p+1) = *p;
	*q = e;         // д���������Ԫ��e
	*/
	for(int j = L.length;j>=i)
	++ L.length;    // ����1
	return OK;
}

int ListGet(const SqList L, int i, ElemType &e){
	if(i < 1 || i > L.length)
		return ERROR;
	e=L.elem[i-1];
	return OK;
}
int ListSet(SqList& L, int i, ElemType e){
	if(i < 1 || i > L.length)
		return ERROR;
	L.elem[i-1]=e;
	return OK;
}

void DestoryList(SqList& L){
	delete[] L.elem;
	L.elem = 0;
	L.listsize = 0;
}