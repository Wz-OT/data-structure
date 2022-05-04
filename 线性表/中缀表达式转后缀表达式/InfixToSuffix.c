/*
* 中缀表达式转后缀表达式
*/
#include <stdio.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 10
//定义一个顺序栈
typedef struct {
	char data[MaxSize];
	int top;
}SeqStack;
//初始化
void InitStack(SeqStack* S) {
	S->top = -1;
}
//判空
bool Empty(SeqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
//入栈
bool Push(SeqStack* S, char e) {
	if (S->top == MaxSize - 1)
		return false;
	S->data[++S->top] = e;
	return true;
}
//出栈
char Pop(SeqStack* S) {
	if (S->top == -1)
		return '?';
	return S->data[S->top--];
}
//查看栈顶元素
char GetTopElem(SeqStack S) {
	if (S.top == -1)
		return ‘？’;
	return S.data[S.top];
}
//优先级比较
int Compare(char ch1, char ch2) {
	int i = 0;
	int j = 0;
	if (ch1 == '*' || ch1 == '/')
		i = 1;
	if (ch2 == '*' || ch2 == '/')
		j = 1;
	if (ch1 == '(' || ch2 == '(')
		return -1;
	return i - j;
}
//中缀转后缀
void InfixToSuffix(char str[],int len) {
	SeqStack S;
	InitStack(&S);
	if (Empty(S))
		printf("此顺序栈为空！\n");
	else
		printf("此顺序栈非空！\n");
	for (int i = 0; i < len; i++) {
		if (str[i] == '(')
			Push(&S, str[i]);
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			while (Compare(GetTopElem(S), str[i]) > -1 && !Empty(S)) {
				printf("%c", Pop(&S));
			}
			Push(&S, str[i]);
		}
		else if (str[i]==')') {
			while (GetTopElem(S) != '(') {
				printf("%c", Pop(&S));
			}
			Pop(&S);
		}
		else {
			printf("%c", str[i]);
		}
	}
	while (!Empty(S)) {
		printf("%c", Pop(&S));
	}
}
void main() {
	char str[] = "A+B*(C-D)-E/F";//ABCD-*+EF/-
	InfixToSuffix(str, strlen(str));
}
