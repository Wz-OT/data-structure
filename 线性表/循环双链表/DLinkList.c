/*
* 循环双链表
*/
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
//定义一个双链表
typedef struct DNode {
	int data;
	struct DNode* next, * prior;
}DNode, * DLinkList;
//初始化
bool InitDLinkList(DLinkList* L) {
	(*L) = (DNode*)malloc(sizeof(DNode));
	if ((*L) == NULL)
		return false;
	(*L)->prior = (*L);
	(*L)->next = (*L);
	return true;
}
//判空
bool Empty(DLinkList L) {
	if (L->next = L)
		return true;
	else
		return false;
}
//判断结点是否为表尾节点
bool IsTail(DLinkList L,DNode* p) {
	if (p->next == L)
		return true;
	else
		return false;
}
//创建一个新结点
DNode* CreateNode(int e) {
	DNode* p;
	p = (DNode*)malloc(sizeof(DNode));
	if (p == NULL)
		return NULL;
	p->data = e;
	p->next = NULL;
	p->prior = NULL;
	return p;
}
//按位序插入
bool InsertDLinkList(DLinkList* L, int i, int e) {
	if (i < 1)
		return false;
	DNode* p, * s;
	int j = 0;
	p = (*L);
	while (p->next != (*L) && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j < i - 1)
		return false;
	s = (DNode*)malloc(sizeof(DNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	s->prior = p;
	p->next->prior = s;
	p->next = s;
	return true;
}
//在p结点后插入s结点
bool InsertNextNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}
//删除指定节点的后继节点
bool DeleteNextNode(DNode* p) {
	if (p == NULL)
		return false;
	DNode* q;
	q = p->next;
	q->next->prior = p;
	p->next = q->next;
	free(q);
	return true;
}
//按位查找
DNode* GetElem(DLinkList L, int i) {
	if (i < 1)
		return NULL;
	DNode* p;
	int j = 0;
	p = L;
	if (p == NULL)
		return NULL;
	while (p->next != L && j < i) {
		p = p->next;
		j++;
	}
	if (j == i)
		return p;
	return NULL;
}
//按值查找
DNode* LocateElem(DLinkList L, int e) {
	DNode* p;
	p = L->next;
	if (p == NULL)
		return NULL;
	while (p != L && p->data != e)
		p = p->next;
	if (p != L)
		return p;
	return NULL;
}
void main() {
	DLinkList L;
	InitDLinkList(&L);
	if (Empty(L))
		printf("该双链表为空！\n");
	else
		printf("该双链表非空！\n");
	if (InsertDLinkList(&L, 1, 1))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if (InsertNextNode(GetElem(L,1),CreateNode(2)))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if (InsertNextNode(GetElem(L, 2), CreateNode(3)))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	DeleteNextNode(LocateElem(L, 1));
	DNode* p;
	p = L->next;
	while (p != L) {
		printf("%d\n", p->data);
		p = p->next;
	}
}
