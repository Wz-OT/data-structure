/*
* 单链表(不带头结点）
*/
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
//定义一个单链表,LNode强调结点，LinkList强调链表
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*LinkList;
//初始化单链表
bool InitList(LinkList* L) {
	*L = NULL;
	return true;
}
//判空 
bool Empty(LinkList L) {
	if (L == NULL) {
		return true;
	}
	else 
		return false;
}
//在第i个位置上插入指定元素
bool ListInsert(LinkList *L, int i, int e) {
	if (i < 1)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)return false;			//内存分配失败
	if (i == 1) {
		s->data = e;
		s->next = *L;
		(*L) = s;
		return true;
	}
	LNode* p;
	int j = 1;		//当前p指向第几个结点
	p = *L;
	while (p != NULL && j < i - 1) {
		p = p->next;
	}
	if (p == NULL)
		return 0;
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;
}
//将指定元素插入到指点结点后
bool  InsertNextNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)		//内存分配失败
		return false;
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;
}
//将指定元素插入到指点结点前
bool InsertPriorNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)		//内存分配失败
		return false;
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}
//按序删除并返回删除的元素
int ListDelete(LinkList* L, int i) {
	if (i < 1)
		return 0;
	int e;
	int j = 1;		//当前p指向第几个结点
	LNode* p;
	p = (*L);
	if (i == 1) {
		e = p->data;
		(*L) = (*L)->next;
		free(p);
		return e;
	}
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL)
		return 0;
	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return e;
}
//删除指定结点
bool DeleteNode(LNode* p) {
	if (p == NULL)
		return false;
	LNode* q;
	q = p->next;
	p->data = q->data;
	p->next = q->next;
	return false;
}
//按位查找
LNode* GetElem(LinkList L, int i) {
	if (i < 1)
		return NULL;
	LNode* p;
	p = L;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	return p;
}
//按值查找
LNode* LocateElem(LinkList L, int e) {
	LNode* p;
	p = L;
	while (p != NULL) {
		if (p->data != e) {
			p = p->next;
		}
		else {
			return p;
		}
	}
	return p;
}
//求表长
int length(LinkList L) {
	int len = 0;
	LNode* p;
	p = L;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}
void main() {
	LinkList L;
	InitList(&L);
	if (ListInsert(&L, 1, 1)) {
		printf("插入成功！\n");
	}
	else {
		printf("插入失败！\n");
	}
	ListInsert(&L, 2, 2);
	InsertNextNode(GetElem(L, 1), 3);
	InsertPriorNode(GetElem(L, 2), 4);
	ListDelete(&L,5);
	DeleteNode(GetElem(L, 5));
	int len = length(L);
}
