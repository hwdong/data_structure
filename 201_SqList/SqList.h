///--------copysight by hongwei dong (hwdong.com)---------------
// SqList.h: interface for the SqList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SQLIST_H__D5972AA1_A6AD_4DEB_8DCC_9520F1D0304A__INCLUDED_)
#define AFX_SQLIST_H__D5972AA1_A6AD_4DEB_8DCC_9520F1D0304A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using std::string;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define OVERFLOW 1
#define ERROR 2
#define OK 0
typedef int Status;

//typedef double ElemType;

struct student{
	string name;
	double score;
};
typedef student ElemType;

struct SqList{
	ElemType *elem;
	int length;
	int listsize;
};

int InitList(SqList &L);
int ListInsert(SqList& L, int i, ElemType e); 
int ListGet(const SqList L, int i, ElemType &e); 
int ListSet(SqList& L, int i, ElemType e);
void DestoryList(SqList& L);
//int ListLength(SqList L){return L.length;};


#endif // !defined(AFX_SQLIST_H__D5972AA1_A6AD_4DEB_8DCC_9520F1D0304A__INCLUDED_)
