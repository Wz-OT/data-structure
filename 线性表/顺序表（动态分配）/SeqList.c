/*
* 顺序表（动态分配）实现线性表
* 可以拓展容量，但是时间代价高
*/
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
#define InitSize 10
//定义顺序表（动态分配）
typedef struct {
	int* data;
	int MaxSize;
	int length;
}SeqList;
//初始化
void InitList(SeqList* L) {
	L->data = (int*)malloc(InitSize * sizeof(int));
	L->length = 0;
	L->MaxSize = InitSize;
}
//在第i个位置上插入指定元素e
bool ListInsert(SeqList* L, int i, int e) {
	if (i < 1 || i > L->length + 1)
		return false;
	if (L->length >= L->MaxSize)
		return false;
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
//删除第i个位置上的元素并返回该元素
int ListDelete(SeqList* L, int i) {
	if (i < 1 || i > L->length)
		return 9999;
	int e = L->data[i - 1];
	for (int j = i; j < L->length; j++) {
		L->data[j - 1] = L->data[j];
	}
	L->length--;
	return e;
}
//按位查找
int GetElem(SeqList L, int i) {
	if (i<1 || i>L.length)
		return 9999;
	return L.data[i - 1];
}
//	按值查找
int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 9999;
}
//拓展容量
bool IncreaseSize(SeqList* L, int len) {
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	if (L->data == NULL)
		return false;
	for (int i = 0; i < L->length; i++) {
		L->data[i] = p[i];
	}
	L->MaxSize += len;
	free(p);
	return true;
}
void main() {
	SeqList L;
	InitList(&L);
	//int e;
	//if (ListInsert(&L, 1, 1))
	//	printf("插入成功！\n");
	//else
	//	printf("插入失败！\n");
	//ListInsert(&L, 2, 2);
	////e = ListDelete(&L, 1);
	////if (e == 9999)
	////	printf("删除失败!\n");
	////else
	////	printf("删除成功，删除元素为%d\n", e);
	//if (e != 9999)
	//	printf("第1个位置元素为%d\n", e);
	//else 
	//	printf("查找失败！\n");
	//e = LocateElem(L, 1);
	//if (e != 9999)
	//	printf("元素1在第%d个位置上\n",e);
	//else 
	//	printf("查找失败！\n");
	IncreaseSize(&L, 5);
	for (int i = 1; i <= L.MaxSize; i++)
		ListInsert(&L, i, i);
	for (int i = 0; i < L.MaxSize; i++)
		printf("%d ", L.data[i]);
}
