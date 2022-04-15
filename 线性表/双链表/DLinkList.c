#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
//定义一个双链表
typedef struct DNode {
	int data;
	struct DNode* next, * prior;
}DNode,*DLinkList;
//初始化
bool InitDLinkList(DLinkList* L) {
	(*L) = (DLinkList)malloc(sizeof(DLinkList));
	if ((*L) == NULL)
		return false;
	(*L)->data = 123;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return true;
}
//判空
bool Empty(DLinkList L) {
	if (L->next == NULL)
		return true;
	else
		return false;
}
//创建一个结点
DNode* CreateNode(int e) {
	DNode* p = (DNode*)malloc(sizeof(DNode));
	if (p == NULL)
		return NULL;
	p->data = e;
	return p;
}
//指定结点后插入一个结点
bool InsertNextNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	s->prior = p;
	if (p->next != NULL)
		p->next->prior = s;
	p->next = s;
	return true;
}
//按位序插入
bool InsertDLinkList(DLinkList* L, int i,int e) {
	if (i < 1)
		return false;
	DNode* p,* s;
	int j = 0;
	p = (*L);
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	s = (DNode*)malloc(sizeof(DNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	s->prior = p;
	if (p->next != NULL)
		p->next->prior = s;
	p->next = s;
	return true;
}
//指定结点前插
bool InsertPriorNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL)
		return false;
	s->next = p;
	s->prior = p->prior;
	p->prior->next = s;
	p->prior = s;
	return true;
}
//按位查找
DNode* GetElem(DLinkList L, int i) {
	if (i < 1)
		return NULL;
	DNode* p;
	p = L;
	int j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
//按值查找
DNode* LocateElem(DLinkList L, int e) {
	DNode* p;
	p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
//删除指定结点的下一个结点
bool DeleteNextNode(DNode* p) {
	if (p == NULL)
		return false;
	DNode* q;
	q = p->next;
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}
//销毁双链表
void DestoryList(DLinkList* L) {
	while ((*L)->next != NULL)
		DeleteNextNode((*L));
}
void main() {
	DLinkList L;
	InitDLinkList(&L);
	if (Empty(L))
		printf("该双链表为空！\n");
	else
		printf("该双链表非空！\n");
	if(InsertDLinkList(&L,1,1))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if(InsertNextNode(GetElem(L,1),CreateNode(2)))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if(InsertPriorNode(LocateElem(L,1),CreateNode(3)))
		printf("插入成功！\n");
	else
		printf("插入失败\n");
	if (DeleteNextNode(L))
		printf("删除成功！\n");
	DLinkList p;
	p = L->next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	DestoryList(&L);
}
