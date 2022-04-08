// LinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[5];
	int number;
}Element;

typedef struct LNode{
	Element data;
	struct LNode* next;
}LNode, *LinkList;

LNode* InitNode1()
{
	LNode* head = (LNode*)malloc(sizeof(LNode));
	if (head == NULL) return NULL;//申请失败
	head->next = NULL;
	return head;
}

int InitNode2(LinkList* LL)
{
	if (*LL == NULL) return -1;
	LNode* head = (LNode*)malloc(sizeof(LNode));
	if (head == NULL) return -1;//申请失败
	head->next = NULL;
	*LL = head;
	return 1;
}

int InitNode3(LinkList& LL)
{
	if (LL == NULL) return -1;
	LNode* head = (LNode*)malloc(sizeof(LNode));
	if (head == NULL) return -1;//申请失败
	head->next = NULL;
	LL = head;
	return 1;
}

void Destroy1(LinkList LL)
{
	if (LL == NULL) return;
	LNode* p;
	while (LL->next != NULL)
	{
		p = LL->next;
		free(LL);
		LL = p;
	}
}

void Destroy2(LinkList* LL) {
	if (*LL == NULL) return;
	LNode* tmp;
	while ((*LL)->next != NULL)
	{
		tmp = (*LL)->next;
		free(*LL);
		*LL = tmp;
	}
	*LL = NULL;
	return;
}

void Destroy2(LinkList& LL) {
	if (LL == NULL) return;
	LNode* tmp;
	while (LL->next != NULL)
	{
		tmp = LL->next;
		free(LL);
		LL = tmp;
	}
	LL = NULL;
	return;
}

int main()
{
    return 0;
}

