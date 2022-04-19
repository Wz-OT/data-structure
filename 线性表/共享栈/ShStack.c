/*
* 共享栈
*/
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 10
//定义一个共享栈
typedef struct {
	int data[MaxSize];
	int top0;
	int top1;
}ShStack;
//初始化
bool InitStack(ShStack* S) {
	S->top0 = -1;
	S->top1 = MaxSize;
}
//判空
bool Empty(ShStack S) {
	if (S.top0 == -1 && S.top1 == MaxSize)
		return true;
	else
		return false;
}
//入栈0
bool Push0(ShStack* S, int e) {
	if (S->top0 + 1== S->top1)
		return false;
	S->data[++S->top0] = e;
	return true;
}
//入栈1
bool Push1(ShStack* S, int e) {
	if (S->top1 - 1== S->top0)
		return false;
	S->data[--S->top1] = e;
	return true;
}
//栈0出栈
int Pop0(ShStack* S) {
	if (S->top0 == -1)
		return 9999;
	return S->data[S->top0--];
}
//栈1出栈
int Pop1(ShStack* S) {
	if (S->top1 == MaxSize)
		return 9999;
	return S->data[S->top1++];
}
//读取栈0的栈顶元素
int GetTopElem0(ShStack S) {
	if (S.top0 == -1)
		return 9999;
	return S.data[S.top0];
}
//读取栈1的栈顶元素
int GetTopElem1(ShStack S) {
	if (S.top1 == MaxSize)
		return 9999;
	return S.data[S.top1];
}
void main() {
	ShStack S;
	InitStack(&S);
	if (Empty(S))
		printf("此顺序栈为空！\n");
	else
		printf("此顺序栈非空！\n");
	if (Push0(&S, 3))
		printf("进栈0成功！\n");
	else
		printf("进栈0失败！\n");
	if (Push0(&S, 2))
		printf("进栈0成功！\n");
	else
		printf("进栈0失败！\n");
	if (Push0(&S, 1))
		printf("进栈0成功！\n");
	else
		printf("进栈0失败！\n");
	if (Push1(&S, 10))
		printf("进栈1成功！\n");
	else
		printf("进栈1失败！\n");
	if (Push1(&S, 9))
		printf("进栈1成功！\n");
	else
		printf("进栈1失败！\n");
	if (Push1(&S, 8))
		printf("进栈1成功！\n");
	else
		printf("进栈1失败！\n");
	for (int i = S.top0; i >= 0; i--)
		printf("%d\n", S.data[i]);
	printf("\n");
	for(int i=MaxSize-1;i>=S.top1;i--)
		printf("%d\n", S.data[i]);
	int e = Pop0(&S);
	printf("出栈0成功！元素为%d\n", e);
	e = Pop1(&S);
	printf("出栈1成功！元素为%d\n", e);
	for (int i = S.top0; i >= 0; i--)
		printf("%d\n", S.data[i]);
	printf("\n");
	for (int i = MaxSize - 1; i >= S.top1; i--)
		printf("%d\n", S.data[i]);
	e = GetTopElem0(S);
	printf("当前栈0的栈顶元素为%d\n", e);
	e = GetTopElem1(S);
	printf("当前栈1的栈顶元素为%d\n", e);
}
