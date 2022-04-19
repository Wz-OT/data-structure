/*
* 链栈（带头结点）
*/
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
//定义一个链栈
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkStack;
//初始化
bool InitStack(LinkStack* S) {
	(*S) = (LinkStack)malloc(sizeof(LNode));
	if ((*S) == NULL)
		return false;
	(*S)->next = NULL;
	return true;
}
//判空
bool Empty(LinkStack S) {
	if (S->next == NULL)
		return true;
	else
		return false;
}
//入栈
bool Push(LinkStack* S, int e) {
	LNode* s;
	s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = (*S)->next;
	(*S)->next = s;
	return true;
}
//出栈
int Pop(LinkStack* S) {
	if (Empty((*S)))
		return 9999;
	LNode* p;
	p = (*S)->next;
	int e = p->data;
	(*S)->next = p->next;
	free(p);
	return e;
}
//查看栈顶元素
int GetTopElem(LinkStack S) {
	if (Empty(S))
		return 9999;
	return S->next->data;
}
void main() {
	LinkStack S;
	InitStack(&S);
	if (Empty(S))
		printf("此链栈为空！\n");
	else
		printf("此链栈非空！\n");
	if (Push(&S, 1))
		printf("入栈成功！\n");
	else
		printf("入栈失败！\n");
	if (Push(&S, 2))
		printf("入栈成功！\n");
	else
		printf("入栈失败！\n");
	if (Push(&S, 3))
		printf("入栈成功！\n");
	else
		printf("入栈失败！\n");
	LinkStack p;
	p = S->next ;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	int e = Pop(&S);
	printf("出栈成功！出栈元素为%d\n", e);
	p = S->next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	e = GetTopElem(S);
	printf("当前栈顶元素为%d\n", e);
}
