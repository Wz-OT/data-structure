/*
* 顺序栈
* top指向当前栈顶元素
*/
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 10
//定义一个顺序栈
typedef struct {
	int data[MaxSize];
	int top;
}SeqStack;
//初始化
bool InitStack(SeqStack* S) {
	S->top = -1;
	return true;
}
//判空
bool Empty(SeqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
//进栈
bool Push(SeqStack* S, int e) {
	if (S->top == MaxSize - 1)
		return false;
	S->data[++S->top] = e;
	return true;
}
//出栈,并返回出栈元素
int Pop(SeqStack* S) {
	if (S->top == -1)
		return 9999;
	return S->data[S->top--];
}
//读取栈顶元素
int GetTopElem(SeqStack S) {
	if (S.top == -1)
		return 9999;
	return 	S.data[S.top];
}
void main() {
	SeqStack S;
	InitStack(&S);
	if (Empty(S))
		printf("此顺序栈为空！\n");
	else
		printf("此顺序栈非空！\n");
	if (Push(&S, 3))
		printf("进栈成功！\n");
	else
		printf("进栈失败！\n");
	if(Push(&S,2))
		printf("进栈成功！\n");
	else
		printf("进栈失败！\n");
	if (Push(&S, 1))
		printf("进栈成功！\n");
	else
		printf("进栈失败！\n");
	for (int i = S.top; i >= 0; i--)
		printf("%d\n", S.data[i]);
	int e = Pop(&S);
	printf("出栈成功！元素为%d\n",e);
	e = GetTopElem(S);
	printf("当前栈顶元素为%d\n", e);
	for (int i = S.top; i >= 0; i--)
		printf("%d\n", S.data[i]);
}
