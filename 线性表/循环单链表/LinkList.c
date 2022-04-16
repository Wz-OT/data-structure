/*
* 循环单链表
* L指向表尾元素
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
	(*L)->next = (*L);
	return true;
}
//判空
bool Empty(LinkList L) {
	if (L->next == L)
		return true;
	else
		return false;
}
//判断结点是否为表尾节点
bool IsTail(LinkList L,LNode *p) {
	if (p == L)
		return true;
	else 
		return false;
}
//按位序插入
bool ListInsert(LinkList* L, int i, int e) {
	if (i < 1)
		return false;
	LNode* p;
	p = (*L)->next;
	int j = 0;
	while (p != (*L) && j < i - 1) {
		p = p->next;
		j++;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	if ((*L)->next == s)
		(*L) = s;
	return true;
}
//头插法建立循环单链表
bool Insert_Head(LinkList* L) {
	int x;
	(*L) = (LinkList)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	(*L)->next = (*L);
	LNode* p;
	p = (*L)->next;
	printf("输入一个数：");
	scanf_s("%d", &x);
	LNode* s;
	while (x != 9999) {				//输入9999结束
		s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL)
			return false;
		s->next = p->next;
		s->data = x;
		p->next = s;
		if ((*L)->next == s)
			(*L) = s;
		printf("输入一个数：");
		scanf_s("%d", &x);
	}
	return true;
}
//尾插法建立循环单链表
bool Insert_Tail(LinkList* L) {
	int x;
	(*L) = (LinkList)malloc(sizeof(LNode));
	if ((*L) == NULL)
		return false;
	(*L) = (*L);
	(*L)->next = (*L);
	printf("输入一个数：");
	scanf_s("%d", &x);
	LNode* s;
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		if (s == NULL)
			return false;
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		(*L) = s;
		printf("输入一个数：");
		scanf_s("%d", &x);
	}
	return true;
}
//按位查找
LNode* GetElem(LinkList L, int i) {
	if (i < 1)
		return NULL;
	LNode* p;
	int j = 0;
	p = L->next;
	while (p != L && j < i) {
		p = p->next;
		j++;
	}
	if (j == i)
		return p;
	else 
		return NULL;
}
//按值查找
LNode* LocateElem(LinkList L, int e) {
	LNode* p;
	p = L->next->next;
	while (p != L->next && p->data != e) {
			p = p->next;
	}
	if (p != L->next)
		return p;
	return NULL;
}
//删除指定节点的下一个结点
bool DeleteNextNode(LinkList* L, LNode* p) {
	if (p == NULL)
		return false;
	LNode* q;
	if (IsTail((*L), p)) {
		q = p->next->next;
		(*L)->next->next = q->next;
		free(q);
		return true;
	}
	if (IsTail((*L), p->next)) {
		p->next = (*L)->next;
		free((*L));
		(*L) = p;
		return true;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
void main() {
	LinkList L;
	Insert_Tail(&L);
	//Insert_Head(&L);
	//InitList(&L);
	//if (Empty(L))
	//	printf("此循环链表为空！\n");
	//else
	//	printf("此循环链表非空！\n");
	//if(ListInsert(&L,1,1))
	//	printf("插入成功！\n");
	//else
	//	printf("插入失败！\n");
	//if (ListInsert(&L, 1, 2))
	//	printf("插入成功！\n");
	//else
	//	printf("插入失败！\n");
	LNode* p;
	p = L->next;
	while (!IsTail(L, p)) {
		p = p->next;
		printf("%d\n", p->data);
	}
	if(DeleteNextNode(&L,GetElem(L,1)))
		printf("删除成功！\n");
	else
		printf("删除失败！\n");
	p = L->next;
	while (!IsTail(L, p)) {
		p = p->next;
		printf("%d\n", p->data);
	}
}
