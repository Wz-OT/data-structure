/*
* 链队（带头结点）
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
	Q->front = (LinkNode*)malloc(sizeof(LinkNode));
	if (Q->front == NULL)
		return false;
	Q->rear = Q->front;
	Q->front->next = NULL;
	return true;
}
//判空
bool Empty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
//入队
bool EnQueue(LinkQueue* Q, int e) {
	LinkNode* s;
	s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return true;
}
//出队
int DeQueue(LinkQueue* Q) {
	if (Q->front == Q->rear)
		return 9999;
	LinkNode* p;
	p = Q->front->next;
	int e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) {
		Q->rear = Q->front;
	}
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
	p = Q.front->next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	int e = DeQueue(&Q);
	printf("出队成功！出队元素为%d\n", e);
	e = DeQueue(&Q);
	printf("出队成功！出队元素为%d\n", e);
	p = Q.front->next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
}
