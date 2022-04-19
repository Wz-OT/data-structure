/*
* 循环队列
* 利用模运算在逻辑上实现循环
* 牺牲一个存储单元
* 队列中元素的个数为(rear + MaxSize - front) % MaxSize
*/
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 10
//定义一个循环队列
typedef struct {
	int data[MaxSize];
	int front, rear;
}SeqQueue;
//初始化
bool InitQueue(SeqQueue* Q) {
	Q->rear = 0;
	Q->front = 0;
	return true;
}
//判空
bool Empty(SeqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
//入队
bool EnQueue(SeqQueue* Q, int e) {
	if ((Q->rear + 1) % MaxSize == Q->front)
		return false;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MaxSize;
	return true;
}
//出队
int DeQueue(SeqQueue* Q) {
	if (Q->rear == Q->front)
		return 9999;
	int e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return e;
}
void main() {
	SeqQueue Q;
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
	for (int i = Q.front; i < Q.rear; i++)
		printf("%d\n", Q.data[i]);
	int e = DeQueue(&Q);
	printf("出队成功！出队元素为%d\n", e);
	e = DeQueue(&Q);
	printf("出队成功！出队元素为%d\n", e);
	for (int i = Q.front; i < Q.rear; i++)
		printf("%d\n", Q.data[i]);
}
