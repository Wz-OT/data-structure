/*
* 线索二叉树
* 利用空指针域存放“线索”
* tag==0时，表示指针指向孩子
* tag==1时，表示指针指向“线索”
*/
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
//定义线索二叉树
typedef struct ThreadNode {
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;
//全局变量 ，指向当前访问结点的 前驱
ThreadNode* pre;
//初始化
void InitTree(ThreadTree* T) {
	*T = NULL;
}
//判空
bool Empty(ThreadTree T) {
	if (T == NULL)
		return true;
	else
		return false;
}
//插入根节点
bool InsertRoot(ThreadTree* T, int e) {
	ThreadNode* root = (ThreadNode*)malloc(sizeof(ThreadNode));
	if (root == NULL)
		return false;
	root->data = e;
	root->lchild = NULL;
	root->rchild = NULL;
	root->ltag = 0;
	root->rtag = 0;
	(*T) = root;
	return true;
}
//给指定结点插入左孩子
bool InsertLchild(ThreadNode* p, int e) {
	ThreadNode* s = (ThreadNode*)malloc(sizeof(ThreadNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->lchild = NULL;
	s->rchild = NULL;
	s->ltag = 0;
	s->rtag = 0;
	p->lchild = s;
	return true;
}
//给指定结点插入右孩子
bool InsertRchild(ThreadNode* p, int e) {
	ThreadNode* s = (ThreadNode*)malloc(sizeof(ThreadNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->lchild = NULL;
	s->rchild = NULL;
	s->ltag = 0;
	s->rtag = 0;
	p->rchild = s;
	return true;
}
//先序遍历二叉树，一边遍历一边线索化
void PreThread(ThreadTree T) {
	if (T != NULL) {
		if (T->lchild == NULL) {
			T->lchild = pre;
			T->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = T;
			pre->rtag = 1;
		}
		pre = T;
		if (T->ltag == 0)
			PreThread(T->lchild);
		if (T->rtag == 0)
			PreThread(T->rchild);
	}
}
//先序线索化二叉树
void CreatePreThread(ThreadTree T) {
	pre = NULL;
	if (T != NULL) {
		PreThread(T);
		if (pre->rchild == NULL)
			pre->rtag = 1;
	}
}
//在先序线索二叉树中找到p的后继结点
ThreadNode* PreNextNode(ThreadNode* p) {
	if (p->rtag == 0) {
		if (p->ltag == 0)
			return p->lchild;
		else
			return p->rchild;
	}
	else
		return p->rchild;
}
//先序遍历
void PreOrder(ThreadTree T) {
	for (ThreadNode* p = T; p != NULL; p = PreNextNode(p))
		printf("%d", p->data);
}
void main() {
	ThreadTree T;
	InitTree(&T);
	InsertRoot(&T, 1);
	InsertLchild(T, 2);
	InsertRchild(T, 3);
	InsertLchild(T->lchild, 4);
	InsertRchild(T->lchild, 5);
	InsertLchild(T->rchild, 6);
	InsertRchild(T->rchild, 7);
	InsertLchild(T->rchild->lchild, 8);
	InsertRchild(T->rchild->rchild, 9);
	//先序线索二叉树
	CreatePreThread(T);
	printf("先序遍历：");
	//124536879
	PreOrder(T);
}
