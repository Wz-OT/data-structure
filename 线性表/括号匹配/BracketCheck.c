/*
* 括号匹配
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
void InitStack(SeqStack *S) {
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
//括号匹配
bool BracketCheck(char str[], int len) {
	SeqStack S;
	InitStack(&S);
	if (Empty(S))
		printf("此顺序栈为空！\n");
	else
		printf("此顺序栈非空！\n");
	for (int i = 0; i < len; i++) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(')
			Push(&S, str[i]);
		else {
			if (Empty(S))
				return false;
			if (str[i] == '}' && Pop(&S) != '{')
				return false;
			if (str[i] == ']' && Pop(&S) != '[')
				return false;
			if (str[i] == ')' && Pop(&S) != '(')
				return false;
		}
	}
	return Empty(S);
}
void main() {
	char str[] = "{{(())[]}";
	if (BracketCheck(str, strlen(str)))
		printf("匹配成功！\n");
	else
		printf("匹配失败！\n");
}
