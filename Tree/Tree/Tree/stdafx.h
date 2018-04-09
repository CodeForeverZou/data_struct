// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: 在此处引用程序需要的其他头文件
#include "stdlib.h"
#include "string.h"

typedef char Elem;
const int MAX = 50;

typedef struct BTNode {
	Elem data;
	struct BTNode *lchild, *rchild;
}BTNode, *BTree;

typedef struct Queue {
	int top;
	int rear;
	BTree node[MAX];
}Queue;

struct Stack {
	BTree node[MAX];
	int top;
};