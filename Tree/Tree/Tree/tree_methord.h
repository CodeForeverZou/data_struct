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
}