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
	// 判断i是否合法
	if(i < 1 || i > L.length + 1)
		return ERROR;
	// 若线性表空间不足，再分配一些空间
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
	// q指向插入的位置
	ElemType *q = &(L.elem[i-1]);  
	// p指向最后一个元素，
	// 从p到q的所有元素后移一个单元
	for(ElemType *p = &(L.elem[L.length - 1]);
					p >= q; --p)
		*(p+1) = *p;
	*q = e;         // 写进待插入的元素e
	*/
	for(int j = L.length;j>=i)
	++ L.length;    // 表长加1
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