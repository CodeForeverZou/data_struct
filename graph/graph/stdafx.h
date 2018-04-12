// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: 在此处引用程序需要的其他头文件
#include "string.h"
#include "stdlib.h"

/*
#define CHAR 1
//#define INT

#ifdef CHAR
#define Elem char
#endif // CHAR

#ifdef INT
#define Elem int
#endif // 
*/

#define CHAR 1
#define INT 1

#if CHAR
#define Elem char
#elif INT
#define Elem int
#endif // CHAR

const int MAX = 50;

typedef struct ArcNode {
	Elem adjvex;			//写成Elem verter;
	struct ArcNode *nextarc;
}ArcNode,*ArcList;

typedef struct VNode {		//少写VNode
	Elem vertex;
	ArcNode	*firstarc;
}AdjList[MAX];

typedef struct{				//写成struct AlGraph
	int vnum, anum;
	AdjList vertices;
}AlGraph;







