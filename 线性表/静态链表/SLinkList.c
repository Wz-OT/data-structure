/*
* 静态链表
*/
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 10
//定义一个静态链表
typedef struct {
	int data;
	int next;
}SLinkList[MaxSize];
//初始化
bool InitSLinkList(SLinkList L) {
	L[0].next = -1;
	int i;
	for ( i = 1; i < MaxSize; i++)
		L[i].next = -2;
	return true;
}
//判空
bool Empty(SLinkList L) {
	if (L[0].next == -1)
		return true;
	else
		return false;
}
//插入
bool InsertSLinkList(SLinkList L, int i, int e) {
	if (i < 1)
		return false;
	int j = 1;
	while (L[j].next != -2) {
		j++;
	}
	L[j].data = e;
	int cursor = 0;
	int k = 0;
	while (L[cursor].next > -1 && k < i - 1) {
		cursor = L[cursor].next;
		k++;
	}
	if (k < i - 1)
		return false;
	if (cursor == 0)
		L[j].next = -1;
	else
		L[j].next = L[cursor].next;
	L[cursor].next = j;
	return true;
}
//按位查找
int GetElem(SLinkList L, int i) {
	if (i < 1)
		return 9999;
	int cursor = 0;
	int j = 0;
	while (L[cursor].next > 0 && j < i) {
		cursor = L[cursor].next;
		j++;
	}
	if (j < i)
		return 9999;
	if (cursor == 0)
		return false;
	return L[cursor].data;
}
//按值查找
int LocateElem(SLinkList L, int e) {
	int cursor = L[0].next;
	while (cursor > 0) {
		if (L[cursor].data != e)
			cursor = L[cursor].next;
		else
			return cursor;
	}
	return 9999;
}
//删除
bool DeleteNode(SLinkList L, int i) {
	if (i < 1)
		return false;
	int cursor = 0;
	int j = 0;
	while (L[cursor].next > 0 && j < i - 1) {
		cursor = L[cursor].next;
		j++;
	}
	if (j < i - 1)
		return false;
	L[cursor].next = L[L[cursor].next].next;
	return true;
}
void main() {
	SLinkList L;
	InitSLinkList(L);
	if (Empty(L))
		printf("此静态链表为空\n");
	else
		printf("此静态链表非空\n");
	if (InsertSLinkList(L, 1, 1))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if (InsertSLinkList(L, 2, 2))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if (InsertSLinkList(&L, 3, 3))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	int i = LocateElem(L, 4);
	printf("%d\n", i);
	//DeleteNode(&L, 4);
	//int cursor = L[0].next;
	//while (cursor > 0) {
	//	printf("%d\n", L[cursor].data);
	//	cursor = L[cursor].next;
	//}
}
