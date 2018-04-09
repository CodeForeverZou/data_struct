#pragma once

#include "stdafx.h"

void InitStack(Stack &S) {
	S.top = 0;
}

void Push(Stack &S,BTNode *p) {
	if (S.top < MAX) {
		S.node[S.top++]=p;
	}
}

BTree Pop(Stack &S) {
	if (S.top>0)
	{
		return S.node[--S.top];
	}
}