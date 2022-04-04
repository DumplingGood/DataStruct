// SeqList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int Element;

typedef struct {
	Element data[MAX_SIZE];
	unsigned int length;
}SeqList, *PSeqList;

void ClearList(PSeqList LL) {
	if (LL == NULL) return;
	LL->length = 0;
	memset(LL->data, 0, sizeof(Element)*MAX_SIZE);
}

void InitList(PSeqList LL) 
{
	ClearList(LL);
}

int ListInsert(PSeqList LL, unsigned int ind, Element* ee) {
	if (LL == NULL || ee == NULL) return -1;
	if (LL->length >= MAX_SIZE) return 0;
	if (ind<1 || ind>LL->length + 1) return -1;
	for (int i = LL->length; i >= ind; i--) {
		memcpy(&LL->data[i], &LL->data[i - 1], sizeof(Element));
	}
	memcpy(&LL->data[ind - 1], ee, sizeof(Element));
	LL->length++;
	return 0;
}

int ListUpdate(PSeqList LL, int ind, Element* ee) {
	if (LL == NULL || ee == NULL) return -1;
	if (ind<1 || ind>LL->length) return -1;
	memcpy(&LL->data[ind - 1], ee, sizeof(Element));
	return 0;
}

int ListDelete(PSeqList LL, int ind) {
	if (LL == NULL) return -1;
	if (ind < 1 || ind > LL->length) return -1;
	for (int i = ind; i < LL->length; i++) {
		memcpy(&LL->data[i - 1], &LL->data[i], sizeof(Element));
	}
	LL->length--;
	return 0;
}

int Length(PSeqList LL)
{
	if (LL == NULL)return -1;
	return LL->length;
}

void PrintList(PSeqList LL)
{
	if (LL == NULL) return;
	printf("SeqList[%d]={", LL->length);
	for (int i = 0; i < LL->length; i++)
	{
		if (i == 0)
		{
			printf("%d", LL->data[i]);
		}
		else
		{
			printf("-%d", LL->data[i]);
		}
	}
	printf("}\n");
}
int DestroyList(PSeqList LL) {
	if (LL == NULL) return 0;
	//free(LL->data);
	return 1;
}

int main()
{
	SeqList L;
	InitList(&L);
	Element e;
	e = 7; ListInsert(&L, 1, &e);
	e = 2; ListInsert(&L, 2, &e);
	e = 9; ListInsert(&L, 4, &e);
	e = 8; ListInsert(&L, 3, &e);
	e = 1; ListInsert(&L, 4, &e);
	e = 6; ListInsert(&L, 5, &e);
	PrintList(&L);
	ListDelete(&L, 1);
	PrintList(&L);
	ListDelete(&L, 3);
	PrintList(&L);
	e = 5; ListUpdate(&L, 1, &e);
	PrintList(&L);
	e = 4; ListUpdate(&L, 2, &e);
	PrintList(&L);
	DestroyList(&L);
	system("pause");
	return 0;
}

