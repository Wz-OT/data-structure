/*
* 中缀表达式的计算
*/
#include <stdio.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
#define MaxSize 10
//创建一个操作数栈
typedef struct {
	int data[MaxSize];
	int top;
}NStack;
//创建一个运算符栈
typedef struct {
	char data[MaxSize];
	int top;
}OStack;
//初始化操作数栈
void InitNStack(NStack* S) {
	S->top = -1;
}
//初始化运算符栈
void InitOStack(OStack* S) {
	S->top = -1;
}
//操作数栈判空
bool EmptyNStack(NStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
//运算符栈判空
bool EmptyOStack(OStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
//操作数栈入栈
bool PushNStack(NStack* S,int e) {
	if (S->top == MaxSize - 1)
		return false;
	S->data[++S->top] = e;
	return true;
}
//运算符栈入栈
bool PushOStack(OStack* S, char e) {
	if (S->top == MaxSize - 1)
		return false;
	S->data[++S->top] = e;
	return true;
}
//操作数栈出栈
int PopNStack(NStack* S) {
	if (S->top == -1)
		return 9999;
	return S->data[S->top--];
}
//运算符栈出栈
char PopOStack(OStack* S) {
	if (S->top == -1)
		return '?';
	return S->data[S->top--];
}
//查看运算符栈顶元素
char GetTopElem(OStack S) {
	if (S.top == -1)
		return '?';
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
//中缀表达式的计算
int CalcOfInfix(char str[],int len) {
	NStack NS;
	OStack OS;
	InitNStack(&NS);
	InitOStack(&OS);
	if (EmptyNStack(NS))
		printf("此操作数栈为空！\n");
	else
		printf("此操作数栈非空！\n");
	if (EmptyOStack(OS))
		printf("此运算符栈为空！\n");
	else
		printf("此运算符栈非空！\n");
	for (int i = 0; i < len; i++) {
		if (str[i] == '(')
			PushOStack(&OS, str[i]);
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			while (Compare(GetTopElem(OS), str[i]) > -1 && !EmptyOStack(OS)) {
				int r = PopNStack(&NS);
				int l = PopNStack(&NS);
				if (GetTopElem(OS) == '+')
					PushNStack(&NS, (l + r));
				else if (GetTopElem(OS) == '-')
					PushNStack(&NS, (l - r));
				else if (GetTopElem(OS) == '*')
					PushNStack(&NS, (l * r));
				else if (GetTopElem(OS) == '/') 
					PushNStack(&NS, (l / r));
				PopOStack(&OS);
			}
			PushOStack(&OS, str[i]);
		}
		else if (str[i] == ')') {
			while (GetTopElem(OS) != '(') {
				int r = PopNStack(&NS);
				int l = PopNStack(&NS);
				if (GetTopElem(OS) == '+')
					PushNStack(&NS, (l + r));
				else if (GetTopElem(OS) == '-')
					PushNStack(&NS, (l - r));
				else if (GetTopElem(OS) == '*')
					PushNStack(&NS, (l * r));
				else if (GetTopElem(OS) == '/')
					PushNStack(&NS, (l / r));
				PopOStack(&OS);
			}
			PopOStack(&OS);
		}
		else {
			PushNStack(&NS, (int)(str[i] - '0'));
		}
	}
	while (!EmptyOStack(OS)) {
		int r = PopNStack(&NS);
		int l = PopNStack(&NS);
		if (GetTopElem(OS) == '+')
			PushNStack(&NS, (l + r));
		else if (GetTopElem(OS) == '-')
			PushNStack(&NS, (l - r));
		else if (GetTopElem(OS) == '*')
			PushNStack(&NS, (l * r));
		else if (GetTopElem(OS) == '/')
			PushNStack(&NS, (l / r));
		PopOStack(&OS);
	}
	return PopNStack(&NS);
}
void main() {
	char str[] = "3+5*4/2+2*(1+1)*(2+2)";		//29
	printf("%d\n", CalcOfInfix(str, strlen(str)));
} 
