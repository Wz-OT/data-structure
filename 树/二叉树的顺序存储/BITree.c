/*
* 二叉树顺序存储
*/
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 100
//定义二叉树结点
typedef struct TreeNode {
	int value;
	bool empty;
}TreeNode;
//初始化
void InitTree(TreeNode* T) {
	for (int i = 1; i < MaxSize; i++)
		T[i].empty = true;
}
//判空
bool Empty(TreeNode* T) {
	if (T[1].empty)
		return true;
	else
		return false;
}
//插入新结点
bool Insert(TreeNode* T, int i, int e) {
	if (!T[i].empty)
		return false;
	if (T[i / 2].empty && i>1)
		return false;
	T[i].value = e;
	T[i].empty = false;
	return true;
}
//删除结点
bool Delete(TreeNode* T, int i) {
	if (T[i].empty)
		return false;
	T[i].empty = true;
	if (!T[2 * i].empty)
		Delete(T, 2 * i);
	if (!T[2 * i + 1].empty)
		Delete(T, 2 * i + 1);
	return true;
}
void main() {
	TreeNode T[MaxSize];
	InitTree(T);
	if (Empty(T))
		printf("此树为空！\n");
	else
		printf("此树非空！\n");
	if (Insert(T, 1, 2))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if(Insert(T, 2, 1))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if (Insert(T, 4, 3))
		printf("插入成功！\n");
	else
		printf("插入失败！\n");
	if (Delete(T, 2))
		printf("删除成功！\n");
	else
		printf("删除失败！\n");
	for (int i = 1; i < MaxSize; i++)
		if(!T[i].empty)
			printf("%d\n", T[i].value);
}
