#pragma once

#include "stdafx.h"
#include "queue.h"
#include "stack.h"

void InitNode(BTNode *p) {
	p->lchild = NULL;
	p->rchild = NULL;
}

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

//============================================================================//
/*先序遍历——非递归*/
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

void N2_PreOrder(BTree T) {
	Stack S;
	InitStack(S);
	BTNode *r=NULL,*p=T;
	while (p||S.top>0)
	{
		if (p)
		{
			Push(S,p);
			Visit(p);				//与中序遍历非递归非常类似
			p = p->lchild;
		}
		else
		{
			p = Pop(S);
			p = p->rchild;
		}
	}
	printf("\n");
}

/*中序遍历——非递归*/
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


/*后序遍历——非递归*/
void N_PostOrder(BTree T) {
	Stack S;
	InitStack(S);
	BTree p = T, r = NULL;

	while (p||S.top>0)
	{
		if (p) {
			Push(S, p);
			p = p->lchild;
		}
		else {
			p = S.node[S.top - 1];
			if (p->rchild && p->rchild != r) {
				Push(S, p->rchild);
				p = p->rchild->lchild;				//搞成p=p->lchild了
			}
			else
			{
				p = Pop(S);
				Visit(p);
				r = p;
				p = NULL;
			}
		}
	}
	printf("\n");
}

//////////////////第二种方法搞复杂了/////////////////////
typedef struct PostTag
{
	BTNode *p;
	int tag;
}PostTag;

typedef struct PostStack {
	PostTag S[MAX];
	int top;
}PostStack;

void InitTag(PostStack &PS) {
	int i = 0;
	for ( i = 0; i < MAX; i++)
	{
		PS.S[i].p = NULL;
		PS.S[i].tag = 0;
	}
	PS.top = 0;
}

void N2_PostOrder(BTree T) {
	PostStack PS;
	BTNode *p=T;
	InitTag(PS);

	while (p||PS.top>0)
	{
		while (p)
		{
			PS.S[PS.top++].p = p;
			PS.S[PS.top-1].tag = 0;				//粘贴出错，PS.S[PS.top++].tag = 0   这一句是必须要有的
			p = p->lchild;
		}
		while (PS.top>0 && PS.S[PS.top-1].tag)
		{
			Visit(PS.S[--PS.top].p);			//粘贴出错，p=PS.S[--PS.top].p
		}
		if (PS.top>0)
		{
			PS.S[PS.top - 1].tag = 1;
			p = PS.S[PS.top - 1].p->rchild;
		}
	}
	printf("\n");
}