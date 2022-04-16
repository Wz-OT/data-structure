/*
* 单链表（带头结点）
*/
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0
//定义一个单链表
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
//初始化单链表
bool InitList(LinkList* L) {
	(*L) = (LNode*)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	(*L)->next = NULL;
	return true;
}
//判空
bool Empty(LinkList L) {
	if (L->next == NULL)
		return true;
	else
		return false;
}
//按位序插入
bool ListInsert(LinkList* L, int i,int e) {
	if (i < 1)
		return false;
	LNode* p;
	p = (*L);
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//指定结点的后插操作
bool InsertNextNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//指定结点的前插操作
bool InsertPriorNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = p->data;
	s->next = p->next;
	p->data = e;
	p->next = s;
	return true;
}
//按位序删除,并返回删除的元素
int ListDelete(LinkList* L, int i) {
	if (i < 1)
		return 0;
	LNode* p;
	int j = 0;
	int e;
	p = (*L);
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL)
		return 0;
	LNode* q = p->next;
	p->next = q->next;
	e = p->data;
	free(q);
	return e;
}
//指定结点的删除(无法删除最后一个元素)
bool DeleteNode(LNode* p) {
	if (p == NULL)
		return false;
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}
//按位查找
LNode* GetElem(LinkList L, int i) {
	if (i < 0)		//i=0时返回头结点
		return NULL;
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
//按值查找
LNode* LocateElem(LinkList L, int e) {
	LNode* p;
	p = L->next;
	while (p != NULL && p->data != e )
		p = p->next;
	return p;
}
//求表长
int length(LinkList L) {
	int len = 0;
	LNode* p;
	p = L;
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	return len;
}
//尾插法建立单链表
bool Insert_Tail(LinkList *L) {
	int x;
	(*L) = (LinkList)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	LNode* s, * r;		//r为尾结点
	r = (*L);
	printf("输入一个数：");
	scanf_s("%d", &x);
	while (x != 9999) {				//输入9999结束
		s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL)
			return false;
		r->next = s;
		s->data = x;
		r = s;
		printf("输入一个数：");
		scanf_s("%d", &x);
	}
	r->next = NULL;
	return true;
}
//头插法建立单链表
bool Insert_Head(LinkList* L) {
	int x;
	(*L) = (LinkList)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	(*L)->next = NULL;
	printf("输入一个数：");
	scanf_s("%d", &x);
	LNode* s;
	while (x != 9999) {				//输入9999结束
		s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL)
			return false;
		s->next = (*L)->next;
		s->data = x;
		(*L)->next = s;
		printf("输入一个数：");
		scanf_s("%d", &x);
	}
	return true;
}
void main() {
	LinkList L;
	Insert_Head(&L);
	//Insert_Tail(&L);
	//InitList(&L);
	//if (Empty(L))
	//	printf("此单链表为空！\n");
	//else
	//	printf("此单链表非空！\n");
	//if (ListInsert(&L, 1, 1))
	//	printf("插入成功！\n");
	//else
	//	printf("插入失败！\n");
	//InsertNextNode(GetElem(L, 1),2);
	//InsertPriorNode(LocateElem(L, 2), 3);
	//ListDelete(&L, 4);
	//DeleteNode(GetElem(L, 4));
	LNode* p;
	p = L;
	while (p->next != NULL) {
		p = p->next;
		printf("%d\n", p->data);
	}
}
