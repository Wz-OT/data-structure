/*
* 顺序表（静态分配）实现线性表
* 不可拓展容量
*/
#include <stdio.h>
#define MaxSize 10
typedef int bool;
#define true 1
#define false 0
//定义顺序表（静态分配）
typedef struct {
	int data[MaxSize];
	int length;
}SqList;
//初始化顺序表
void InitList(SqList *L) {
	for (int i = 0; i < MaxSize; i++) {
		L->data[i] = 0;
		L->length = 0;
	}
}
//在第i个位置上插入指定元素
bool ListInsert(SqList *L, int i, int e) {
	if (i < 1 || i > L->length + 1) {		//i值不合法
		return false;
	}
	if (L->length >= MaxSize) {		//顺序表已满
		return false;
	}
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i-1] = e;
	L->length++;
	return true;
}
//删除第i个位置上的元素并返回删除的元素
int ListDelete(SqList* L, int i) {
	if (i < 1 || i > L->length) {		//i值不合法
		return 9999;
	}
	int e = L->data[i-1];
	for (int j = i; j < L->length; j++) {
		L->data[j - 1] = L->data[j];
	}
	L->length--;
	return e;
}
//按位查找
int GetElem(SqList L, int i) {
	if (i < 1 || i > L.length) {
		return 9999;
	}
	return L.data[i - 1];
}
//按值查找
int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
void main() {
	SqList L;
	InitList(&L);
	int e;
	if (ListInsert(&L, 1, 1))
		printf("插入成功！\n");
	else
		printf("插入失败!\n");
	//e = ListDelete(&L, 1);
	//if (e == 9999)
	//	printf("删除失败!\n");
	//else 
	//	printf("删除成功!删除的值为%d\n",e);
	e = GetElem(L, 1);
	if(e==9999)
		printf("查询失败！\n");
	else
		printf("第1个位置元素为%d\n", e);
	e = LocateElem(L, 1);
	if(e)
		printf("元素1在第%d个位置上\n", e);
	else
		printf("查询失败！\n");
}
