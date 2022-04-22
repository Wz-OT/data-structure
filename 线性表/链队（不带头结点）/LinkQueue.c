/*
* 链队（不带头结点）
*/
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
//定义一个链栈
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
//初始化
bool InitQueue(LinkQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	return true;
}
//判空
bool Empty(LinkQueue Q) {
	if (Q.front == NULL)
		return true;
	else
		return false;
}
//入队
bool EnQueue(LinkQueue* Q, int e) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = NULL;
	if (Q->front == NULL) {
		Q->front = s;
		Q->rear = s;
	}
	else {
		Q->rear->next = s;
		Q->rear = s;
	}
	return true;
}
//出队
int DeQueue(LinkQueue* Q) {
	if (Q->front == NULL)
		return 9999;
	LinkNode* p;
	p = Q->front;
	int e = p->data;
	Q->front = p->next;
	if (Q->rear == p) {
		Q->rear = Q->front;
	}
	free(p);
	return e;
}
void main() {
	LinkQueue Q;
	InitQueue(&Q);
	if (Empty(Q))
		printf("此队列为空！\n");
	else
		printf("此队列非空！\n");
	if (EnQueue(&Q, 1))
		printf("入队成功！\n");
	else
		printf("入队失败！\n");
	if (EnQueue(&Q, 2))
		printf("入队成功！\n");
	else
		printf("入队失败！\n");
	if (EnQueue(&Q, 3))
		printf("入队成功！\n");
	else
		printf("入队失败！\n");
	if (EnQueue(&Q, 4))
		printf("入队成功！\n");
	else
		printf("入队失败！\n");
	LinkNode* p;
	p = Q.front;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	int e = DeQueue(&Q);
	printf("出队成功！出队元素为%d\n", e);
	e = DeQueue(&Q);
	printf("出队成功！出队元素为%d\n", e);
	p = Q.front;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
}
