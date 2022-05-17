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
//后序遍历二叉树，一边遍历，一边线索化
void PostThread(ThreadTree T) {
	if (T != NULL) {
		PostThread(T->lchild);
		PostThread(T->rchild);
		if (T->lchild == NULL) {
			T->lchild = pre;
			T->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = T;
			pre->rtag = 1;
		}
		pre = T;
	}
}
//后序线索化二叉树
void CreatePostThread(ThreadTree T) {
	pre = NULL;
	if (T != NULL) {
		PostThread(T);
		if (pre->rchild == NULL)
			pre->rtag = 1;
	}
}
//在后序线索二叉树中找到p的前驱结点
ThreadNode* PostPreNode(ThreadNode* p) {
	if (p->ltag == 0)
		if (p->rtag == 0)
			return p->rchild;
		else
			return p->lchild;
	else
		return p->lchild;
}
//逆向后序遍历
void RevPostOrder(ThreadTree T) {
	for (ThreadNode* p = T; p != NULL; p = PostPreNode(p))
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
  //后序线索二叉树
	CreatePostThread(T);
	//逆向后序遍历
	RevPostOrder(T);
}
