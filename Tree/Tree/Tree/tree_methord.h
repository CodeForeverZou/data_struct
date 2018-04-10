#pragma once

#include "stdafx.h"
#include "queue.h"
#include "stack.h"

void InitNode(BTNode *p) {
	p->lchild = NULL;
	p->rchild = NULL;
}

/*
BTree CreatTree() {
BTNode *T,*p, *q;
printf("按先序遍历递归建树\n请依次输入节点信息，以‘#’结束\n");
Elem data;
char str;
scanf("%c%*c", &data);


if (data!='#')
{
T = p = (BTree)malloc(sizeof(BTNode));
InitNode(T);
T->data = data;
scanf("%c%*c", &data);

while (data!='#')
{
q = (BTree)malloc(sizeof(BTNode));
InitNode(q);
q->data =data;

}
}


}
*/

void CreatBTree(BTree &T) {
	char data;
	scanf("%c%*c", &data);
	if (data!='#')
	{
		T = (BTree)malloc(sizeof(BTNode));
		T->data = data;
		CreatBTree(T->lchild);
		CreatBTree(T->rchild);
	}
	else
	{
		T = NULL;
	}
}

void Visit(BTNode *p) {
	if (p)printf("%c->", p->data);
}

void PreOrder(BTree T) {
	if (T)
	{
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BTree T) {
	if (T)
	{
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}

void PostOrder(BTree T) {
	if (T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T);
	}
}

void N_PreOrder(BTree T) {
	Stack S;
	InitStack(S);
	BTNode *p;
	if (T)
	{
		Visit(T);

		if (T->rchild)
		{
			Push(S, T->rchild);
		}
		if (T->lchild)
		{
			Push(S, T->lchild);
		}

		while (S.top>0)
		{
			p = Pop(S);
			Visit(p);

			if (p->rchild)
			{
				Push(S, p->rchild);
			}
			if (p->lchild)
			{
				Push(S, p->lchild);
			}
		}
	}
	printf("\n");
}

void N_InOrder(BTree T) {
	Stack S;
	InitStack(S);
	BTNode *p=T;
	while (p||S.top>0)
	{
		if (p)
		{
			Push(S, p);
			p = p->lchild;
		}
		else
		{
			p=Pop(S);
			Visit(p);
			p = p->rchild;
		}
	}
	printf("\n");
}

void N2_InOrder(BTree T) {
	Stack S;
	InitStack(S);
	BTNode *p = T;
	Push(S, p);
	while (S.top>0)
	{
		while (p = S.node[S.top - 1]) {		//GerTop(S)
			p = p->lchild;
			Push(S, p);
		}
		Pop(S);						//空指针出栈
		if (S.top ==0) break;		//判断栈空，用== ！！！
		if (p=Pop(S))
		{
			Visit(p);
			Push(S, p->rchild);
		}
	}
	/*
	while (p||S.top>0)
	{
		while (p) {
			Push(S, p);
			p = p->lchild;
		}
		if (p = Pop(S)) {
			Visit(p);
			p = p->rchild;
			Push(S, p);
		}
	}
	*/
	printf("\n");
}