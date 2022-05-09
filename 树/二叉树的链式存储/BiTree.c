/*
* 二叉树的链式存储
*/
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 10
//定义二叉树
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//定义一个顺序栈
typedef struct {
	BiTNode* T[MaxSize];
	int top;
}SeqStack;
//定义一个顺序队列
typedef struct {
	BiTNode* T[MaxSize];
	int front, rear;
}SeqQueue;
//初始化二叉树
void InitTree(BiTree* T) {
	*T = NULL;
}
//初始化顺序栈
void InitStack(SeqStack* S) {
	S->top = -1;
}
//初始化顺序队列
void InitQueue(SeqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
}
//二叉树判空
bool TEmpty(BiTree T) {
	if (T == NULL)
		return true;
	else
		return false;
}
//顺序栈判空
bool SEmpty(SeqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
//队列判空
bool QEmpty(SeqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
//插入根结点
bool InsertRoot(BiTree* T,int e) {
	BiTNode* s = (BiTNode*)malloc(sizeof(BiTNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->lchild = NULL;
	s->rchild = NULL;
	(*T) = s;
	return true;
}
//给结点p添加左孩子
bool InsertLchild(BiTNode* p, int e) {
	BiTNode* s = (BiTNode*)malloc(sizeof(BiTNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->lchild = NULL;
	s->rchild = NULL;
	p->lchild = s;
	return true;
}
//给结点p添加右孩子
bool InsertRchild(BiTNode* p, int e) {
	BiTNode* s = (BiTNode*)malloc(sizeof(BiTNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->lchild = NULL;
	s->rchild = NULL;
	p->rchild = s;
	return true;
}
//入栈
bool Push(SeqStack* S, BiTNode* p) {
	if (S->top == MaxSize - 1)
		return false;
	S->T[++S->top] = p;
	return true;
}
//出栈
BiTNode* Pop(SeqStack* S) {
	if (S->top == -1)
		return NULL;
	return S->T[S->top--];
}
//获取栈顶元素
BiTNode* GetTopElem(SeqStack S) {
	return S.T[S.top];
}
//入队
bool EnQueue(SeqQueue* Q, BiTNode *p) {
	if (Q->rear == MaxSize - 1)
		return false;
	Q->T[Q->rear++] = p;
	return true;
}
//出队
BiTNode* DeQueue(SeqQueue* Q) {
	if (Q->rear == Q->front)
		return NULL;
	BiTNode* e = Q->T[Q->front++];
	return e;
}
//先序遍历(递归）
void PreOrder(BiTree T) {
	if (T != NULL) {
		printf("%d", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//先序遍历（非递归）
void PreOrder1(BiTree T) {
	SeqStack S;
	InitStack(&S);
	BiTNode* p;
	p = T;
	while (p != NULL || !SEmpty(S)) {
		if (p != NULL) {
			printf("%d", p->data);
			Push(&S, p);
			p = p->lchild;
		}
		else {
			p = Pop(&S);
			p = p->rchild;
		}
	}
}
//中序遍历（递归）
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		printf("%d", T->data);
		InOrder(T->rchild);
	}
}
//中序遍历（非递归）
void InOrder1(BiTree T) {
	SeqStack S;
	InitStack(&S);
	BiTNode* p;
	p = T;
	while (p != NULL || !SEmpty(S)) {
		if (p != NULL) {
			Push(&S, p);
			p = p->lchild;
		}
		else {
			p = Pop(&S);
			printf("%d", p->data);
			p = p->rchild;
		}
	}
}
//后序遍历（递归）
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%d", T->data);
	}
}
//后序遍历（非递归）①
void PostOrder1(BiTree T) {
	SeqStack S;
	InitStack(&S);
	BiTNode* p;
	p = T;
	BiTNode* flag = NULL;
	while (p != NULL || !SEmpty(S)) {
		if (p != NULL) {
			Push(&S, p);
			p = p->lchild;
		}
		else {
			p = GetTopElem(S);
			if (p->rchild != NULL && flag != p->rchild)
				p = p->rchild;
			else {
				p = Pop(&S);
				printf("%d", p->data);
				flag = p;
				p = NULL;
			}
		}
	}
}
//后序遍历（非递归）②
void PostOrder2(BiTree T) {
	SeqStack S;
	SeqStack S1;
	InitStack(&S);
	InitStack(&S1);
	BiTNode* p;
	p = T;
	while (p != NULL || !SEmpty(S)) {
		if (p != NULL) {
			Push(&S1, p);
			Push(&S, p);
			p = p->rchild;
		}
		else {
			p = Pop(&S);
			p = p->lchild;
		}
	}
	while (!SEmpty(S1))
		printf("%d", Pop(&S1)->data);
}
//层次遍历
void LevelOrder(BiTree T) {
	SeqQueue Q;
	InitQueue(&Q);
	BiTree p;
	EnQueue(&Q, T);
	while (!QEmpty(Q)) {
		p = DeQueue(&Q);
		printf("%d", p->data);
		if (!TEmpty(p->lchild))
			EnQueue(&Q,p->lchild);
		if (!TEmpty(p->rchild))
			EnQueue(&Q,p->rchild);
	}
}
void main() {
	BiTree T;
	InitTree(&T);
	if (TEmpty(T))
		printf("此树为空！\n");
	else
		printf("此树非空！\n");
	InsertRoot(&T, 1);
	InsertLchild(T, 2);
	InsertRchild(T, 3);
	InsertLchild(T->lchild, 4);
	InsertRchild(T->lchild, 5);
	InsertLchild(T->rchild, 6);
	InsertRchild(T->rchild, 7);
	InsertLchild(T->rchild->lchild, 8);
	InsertRchild(T->rchild->rchild, 9);
	PreOrder(T);    //124536879
	printf("\n");
	PreOrder1(T);
	printf("\n");
	InOrder(T);		//425186379
	printf("\n");
	InOrder1(T);
	printf("\n");
	PostOrder(T);	//452869731
	printf("\n");
	PostOrder1(T);
	printf("\n");
	LevelOrder(T);	//123456789
}
