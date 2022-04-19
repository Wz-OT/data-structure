/*
* 顺序队列
*/
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 10
//定义一个顺序队列
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
/*
* Q->rear == MaxSize并不能作为判断队满的条件
* 若进行了出队操作，即使Q->rear == MaxSize队列仍然有位置可以存放元素
* 此时入队出现“上溢出”，是一种“假溢出”
*/
bool EnQueue(SeqQueue* Q, int e) {
	if (Q->rear == MaxSize)
		return false;
	Q->data[Q->rear++] = e;
	return true;
}
//出队
int DeQueue(SeqQueue* Q) {
	if (Q->rear == Q->front)
		return 9999;
	int e = Q->data[Q->front++];
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
