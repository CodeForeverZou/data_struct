// Tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "tree_methord.h"


int main()
{
	BTree T;
	T = (BTree)malloc(sizeof(BTNode));
	InitNode(T);
	CreatBTree(T);
	//N_PreOrder(T);
	//N_InOrder(T);
	N2_InOrder(T);
	scanf("%c");
    return 0;
}

