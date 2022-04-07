// SeqList2.cpp : 定义控制台应用程序的入口点。
//
// 动态顺序表 - 数据结构

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define INIT_LIST_SIZE 10		//初始化列表大小
#define DILATION_SIZE 10		//扩容尺寸

typedef struct {
	char name[10];
	int no;
}Element;

typedef struct {
	Element *data;
	int iMaxsize;
	int iLength;
}SeqList, *PSeqList;


int InitList(PSeqList LL)
{
	LL->data = (Element*)malloc(sizeof(Element)* INIT_LIST_SIZE);
	if (LL->data == NULL) return -1;
	LL->iLength = 0;
	LL->iMaxsize = 10;
	return 1;
}

int DestoryList(PSeqList LL)
{
	if (LL == NULL) return 0;
	free(LL->data);
	return 1;
}

int ExpandList(PSeqList LL)
{
	if (LL == NULL) return -1;
	SeqList TMP;
	TMP.data = (Element*)malloc(sizeof(Element)*(LL->iLength + DILATION_SIZE));
	if (TMP.data)
	{
		memcpy(TMP.data, LL->data, sizeof(Element)*LL->iLength);
		DestoryList(LL);
		LL->data = TMP.data;
		LL->iMaxsize = LL->iLength + DILATION_SIZE;
		return 1;
	}
	else
	{
		return -1;
	}
}



int size(PSeqList LL)
{
	if (LL == NULL) return -1;
	return LL->iLength;
}

int max_size(PSeqList LL)
{
	if (LL == NULL) return -1;
	return LL->iMaxsize;
}
int insert(PSeqList LL, int index, Element* ee)
{
	if (LL == NULL || ee == NULL) return -1;
	if (index<0 || index>LL->iLength) return -1;
	if (LL->iLength == LL->iMaxsize)
	{
		if (!ExpandList(LL)) return -1;
	}
	for (int i = LL->iLength; i > index; i--)
	{
		memcpy(LL->data + i, LL->data + i - 1, sizeof(Element));
	}
	memcpy(LL->data + index, ee, sizeof(Element));
	LL->iLength++;
	return 1;
}

int GetElem(PSeqList LL, int index, Element* ee)
{
	if (LL == NULL || ee == NULL) return -1;
	if (index < 0 || index >= LL->iLength) return -1;
	memcpy(ee, LL->data + index, sizeof(Element));
	return 1;
}

int push_back(PSeqList LL, Element* ee)
{
	if (LL == NULL || ee == NULL) return -1;
	return insert(LL, LL->iLength, ee);
}

void PrintList(PSeqList LL)
{
	if (LL == NULL) return;
	printf("SeqList[%d]={\n", LL->iLength);
	Element ee;
	for (size_t i = 0; i < LL->iLength; i++)
	{
		GetElem(LL, i, &ee);
		printf("\t[%d] Name=%s No=%d\n", i, ee.name, ee.no);
	}
	printf("}\n");
}

int erase(PSeqList LL, int index)
{
	if (LL == NULL) return -1;
	if (index<0 || index>LL->iLength) return -1;
	for (size_t i = index; i < LL->iLength; i++)
	{
		memcpy(LL->data + i, LL->data + i + 1, sizeof(Element));
	}
	LL->iLength--;
	return 1;
}

int pop_back(PSeqList LL)
{
	if (LL == NULL) return -1;
	return erase(LL, LL->iLength - 1);
}

void clear(PSeqList LL)
{
	if (LL == NULL) return;
	memset(LL->data, 0, sizeof(Element)*LL->iLength);
	LL->iLength = 0;
	return;
}

int Front(PSeqList LL, Element* ee)
{
	if (LL == NULL || ee == NULL) return -1;
	return GetElem(LL, 0, ee);
}
int Empty(PSeqList LL)
{
	if (LL == NULL) return -1;
	return LL->iLength == 0 ? 1 : 0;
}

int FindElem(PSeqList LL, Element* ee)
{
	if (LL == NULL || ee == NULL) return -1;
	if (Empty(LL)) return -1;
	Element tmp;
	int index = -1;
	for (size_t i = 0; i < LL->iLength; i++)
	{
		memcpy(&tmp, LL->data + i, sizeof(Element));
		if (!strcmp(tmp.name, ee->name) && tmp.no == ee->no)
		{
			index = i;
			break;
		}
	}
	return index;
}

int UpdateElem(PSeqList LL, int index, Element* ee)
{
	if (LL == NULL || ee == NULL) return -1;
	if (index<0 || index>LL->iLength) return -1;
	memcpy(LL->data + index, ee, sizeof(Element));
	return 1;
}

int main()
{
	SeqList LL;
	printf("Init List Res:%d\n", InitList(&LL));
	printf("Size:%d\n", size(&LL));
	printf("Max_Size:%d\n", max_size(&LL));

	//添加元素到顺序表
	Element ee;
	strcpy(ee.name, "zly");
	ee.no = 2;
	push_back(&LL, &ee);
	printf("Size:%d\n", size(&LL));
	PrintList(&LL);

	strcpy(ee.name, "lyc");
	ee.no = 1;
	push_back(&LL, &ee);
	printf("Size:%d\n", size(&LL));
	PrintList(&LL);


	strcpy(ee.name, "zbc");
	ee.no = 3;
	push_back(&LL, &ee);
	printf("Size:%d\n", size(&LL));
	PrintList(&LL);

	pop_back(&LL);
	PrintList(&LL);

	erase(&LL, 0);
	PrintList(&LL);

	for (int i = 0; i < 15; i++)
	{
		strcpy(ee.name, "wb0");
		ee.no = 10 + i;
		insert(&LL, 0, &ee);
	}
	printf("Size:%d\n", size(&LL));
	PrintList(&LL);

	GetElem(&LL, 3, &ee);
	printf("GetElem[3] Name=%s No=%d\n", ee.name, ee.no);

	strcpy(ee.name, "hj");
	ee.no = 5;
	UpdateElem(&LL, 3, &ee);
	printf("GetElem[3] Name=%s No=%d\n", ee.name, ee.no);

	printf("Find Elem index: %d\n", FindElem(&LL, &ee));

	strcpy(ee.name, "jnl");
	ee.no = 5;
	printf("Find Elem index: %d\n", FindElem(&LL, &ee));


	Front(&LL, &ee);
	printf("Front Name=%s No=%d\n", ee.name, ee.no);

	clear(&LL);
	PrintList(&LL);

	printf("Destroy Res:%d\n", DestoryList(&LL));
	system("pause");
    return 0;
}

