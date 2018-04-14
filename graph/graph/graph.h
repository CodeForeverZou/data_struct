#pragma once

#include "stdafx.h"
#include "E:\code\github\data_struct\Tree\Tree\Tree\queue.h"

//void InitArcNode(ArcList w) {
//	w->nextarc = NULL;
//}

void InitVNode(VNode &v) {
	v.firstarc = NULL;
}

void InitAlGraph(AlGraph &G) {
	G.anum = 0;
	G.vnum = 0;
	for (int i = 0; i < MAX; i++)
	{
		InitVNode(G.vertices[i]);
	}
}

//=============================== 邻接表法 实现图================================
AlGraph CreatGraph() {
	AlGraph G;
	InitAlGraph(G);

#if CHAR
	printf("<<----正在创建字符数据类型的图---->>\n注：请使用英文输入法,并用A、B…表示节点\n\n");
#elif INT
	printf("<<----正在创建数字数据类型的图---->>\n注：请使用英文输入法,并用1、2…表示节点\n\n");
#endif // CHAR

	printf("请输入图的顶点数，边数：");
	scanf("%d,%d%*c", &G.vnum, &G.anum);
	int i;
	
	for ( i = 0; i < G.vnum; i++)
	{
#if CHAR
		G.vertices[i].vertex = char(65 + i);
		//printf("%c\t", G.vertices[i].vertex);
#elif INT
		G.vertices[i].vertex = i+1 ;
		//printf("%d\t", G.vertices[i].vertex);
#endif // CHAR
	}

#if CHAR
	char v, w;
#elif INT
	int v, w;
#endif // CHAR

	int n = 0;
	ArcNode *vn, *wn,*pre;

	printf("请依次输入各边v-w:\n");
	for ( i = 0; i < G.anum; i++)
	{

#if CHAR
		scanf("%c-%c%*c", &v, &w);
		n = int(v) - 65;
#elif INT
		scanf("%d-%d%*c", &v, &w);
		n = v-1;
#endif // CHAR
	
		vn = G.vertices[n].firstarc;
		if (!vn)
		{
			G.vertices[n].vertex = v;
			vn = (ArcList)malloc(sizeof(ArcNode));
			vn->adjvex = w;
			vn->nextarc = NULL;
			G.vertices[n].firstarc = vn;			//少了这一句赋值，搞的firstarc总是NULL
		}
		else
		{
			pre = vn;
			if (vn->nextarc)
			{
				pre = wn = vn->nextarc;
				while (wn)wn = wn->nextarc;
			}
			wn = (ArcList)malloc(sizeof(ArcNode));
			pre->nextarc = wn;
			wn->adjvex = w;
			wn->nextarc = NULL;
		}
	}
	return G;
}

void PrintG(AlGraph G) {
	int i;
	ArcNode *vn;
	printf("\n邻接表法建立的图如下：\n");
	for ( i = 0; i < G.vnum; i++)
	{
		vn = G.vertices[i].firstarc;
#if CHAR
		printf("%c-->", G.vertices[i].vertex);
		while (vn)
		{
			printf("%c->", vn->adjvex);
			vn = vn->nextarc;
		}
#elif INT
		printf("%d-->", G.vertices[i].vertex);
		while (vn)
		{
			printf("%d->", vn->adjvex);
			vn = vn->nextarc;
		}
#endif // CHAR

		printf("\n");
	}
}

//======================深度优先======================//
bool visited[MAX] = { false };
void DFSTraverse(AlGraph G, int i);

void DFS(AlGraph G) {
	int i;
	printf("深度优先遍历顺序为：\n");
	for ( i = 0; i < G.vnum; i++)
	{
		if (!visited[i])
		{
			DFSTraverse(G, i);
		}
	}
	printf("\n");
}

void DFSTraverse(AlGraph G, int i) {
	ArcNode *p;
	if (!visited[i])
	{
		visited[i] = true;

#if CHAR
		printf("%c->", char(i + 65));
		for ( p=G.vertices[i].firstarc;  p ; p=p->nextarc)
		{
			int n = (int(p->adjvex) - 65);
			DFSTraverse(G, n);						//不能写成DFSTraverse[G,(int(p->adjvex) - 65)];
		}
#elif INT
		printf("%d->", i + 1);
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			DFSTraverse[G, p->adjvex - 1];
		}
#endif // CHAR


	}
}


//======================广度优先======================//
void BFSTraverse(AlGraph G, int i);

void BFS(AlGraph G) {
	for (int j = 0; j < MAX; j++) visited[j] = false;		//不能写成visited[MAX]={false}
	printf("广度优先遍历顺序为：\n");
	for (int i = 0; i < G.vnum; i++)
	{
		if (!visited[i]) BFSTraverse(G, i);
	}
	printf("\n");
}

void BFSTraverse(AlGraph G,int i) {
	Queue Q;
	InitQueue(Q);
	ArcNode *p;
	EnQueue(Q, i);
	visited[i] = true;

#if CHAR
	printf("%c->", char(i + 65));
#elif INT
	printf("%d->", i + 1);
#endif // CHAR

	while (Q.rear!=Q.top)
	{
		p = G.vertices[DeQueue(Q)].firstarc;
		for ( p ; p ; p=p->nextarc)
		{

#if CHAR
			i = int(p->adjvex) - 65;					//注意这里的i;
			if (!visited[i]) {
				EnQueue(Q, i);
				printf("%c->", char(i + 65));
				visited[i] = true;
			}
#elif INT
			i = p->adjvex - 1;					//注意这里的i;
			if (!visited[i]) {
				EnQueue(Q, i);
				printf("%d->", i + 1);
				visited[i] = true;
			}
#endif // CHAR

		}
	}
}



/*============================== 邻接矩阵 实现图==================================
=================================================================*/
MGraph CreatMG() {
	MGraph G;
	int i, j, n, v, w, info;
	printf("请输入图的顶点数，边数：");
	scanf("%d,%d%*c", &G.vnum, &G.anum);
	G.node = (int **)malloc(sizeof(int) * G.vnum* G.vnum);
	for (i = 0; i < G.vnum; i++)
	{
		*(G.node + i) = (int *)malloc(sizeof(int)*G.vnum);
		for (j = 0; j < G.vnum; j++)
		{
			*(*(G.node + i) + j) = INFINITE;
		}
	}

	printf("创建无向网1、有向网2：");
	scanf("%d%*c", &n);
	printf("请输入各边具体情况v-w，info：\n");
	if (n == 1)
	{
		for (j = 0; j < G.anum; j++)
		{
			scanf("%d-%d,%d%*c", &v, &w, &info);			//这是必要的%*c
			*(*(G.node + v - 1) + w - 1) = info;
			*(*(G.node + w - 1) + v - 1) = info;
		}
	}
	else
	{
		for (j = 0; j < G.anum; j++)
		{
			scanf("%d-%d,%d%*c", &v, &w, &info);
			*(*(G.node + v - 1) + w - 1) = info;
		}
	}

	for ( i = 0; i < G.vnum; i++)
	{
		for ( j = 0; j < G.vnum; j++)
		{
			printf("%d ", *(*(G.node + i) + j));
		}
		printf("\n");
	}
	return G;

}

typedef struct {
	int v;
	int w;
	int info;
	int visited;
}Dist;

//<<----------------加边法 实现最小生成树 -------------------->>

int Mindist = INFINITE;

int FindMindist(MGraph G,Dist *dist) {
	int j, n = 0;
	for (j = 0; j < G.anum; j++)
	{
		if (!(dist + j)->visited && Mindist >(dist + j)->info)
		{
			Mindist = (dist + j)->info;
			n = j;
		}
	}
	return n;
}

void Kruskal(MGraph G) {
	int i, j, n = 0;
	printf("kruskal算法遍历结果\n");
	Dist *dist;
	dist = (Dist *)malloc(sizeof(Dist)*G.anum);		//用来存储每条边的信息，及是否被访问过
	int *node = (int *)malloc(sizeof(int)*G.vnum);	//用来存储已有节点

	for ( i = 0; i < G.vnum; i++)			//初始化 存储参数
	{
		*(node + i) = 0;
		for ( j = 0; j < G.vnum; j++)
		{
			if (*(*(G.node+i)+j)!=INFINITE)		//这里必须再次新建，为其开辟空间
			{
				(dist + n)->v = i+1;
				(dist + n)->w = j+1;
				(dist + n)->info = *(*(G.node + i) + j);
				(dist + n)->visited = 0;
				n++;
			}
		}
	}

	for ( i = 0; i < G.vnum-1; i++)
	{
		n = FindMindist(G, dist);

		//出错最严重！！！写成▷  if(!*  (node + (dist + n)->w)  -1)；  ◁搞的老是假，然后还忽略后面 ||
		if (!*(node + (dist + n)->w - 1) /*|| !*(node + (dist + n)->v - 1)*/ )				//判断是否有环
		{
			printf("%d->%d\n", (dist + n)->v, (dist + n)->w);
			(dist + n)->visited = 1;
			Mindist = INFINITE;

			*(node + (dist + n)->w-1) = 1;
			*(node + (dist + n)->v-1) = 1;
		}
		else
		{
			(dist + n)->visited = 1;
			Mindist = INFINITE;
			i--;						//这一句非常重要！！！·！！！
		}
	}

}

//============================== Prim算法 ====================================
struct Pr_dist
{
	int v, w;
	int visited;
};

int IsLoop(int *node, int v, int w,int n) {
	int flag1= 0,flag2=0;
	for (int i = 0; i < n; i++)
	{
		if (*(node + i) == v) flag1 = 1;
		if (*(node + i) == w) flag2 = 1;
	}
	if (flag1 && flag2)
	{
		return 1;
	}
	return 0;
}

void Prim(MGraph G,int v) {
	int i, j, k, n = 0, x, y, p, q;
	//Dist *dist;
	//dist = (Dist *)malloc(sizeof(Dist)*G.anum);		//用来存储每条边的信息，及是否被访问过
	int *node = (int *)malloc(sizeof(int)*G.vnum);	//用来存储已有节点
	Pr_dist *dist = (Pr_dist *)malloc(sizeof(Pr_dist)*G.anum);

	for (i = 0; i < G.vnum; i++)			//初始化 存储参数
	{
		*(node + i) = 0;
		for (j = 0; j < G.vnum; j++)
		{
			if (*(*(G.node + i) + j) != INFINITE)		//这里必须再次新建，为其开辟空间
			{
				(dist + n)->v = i;
				(dist + n)->w = j;
				//(dist + n)->info = *(*(G.node + i) + j);
				(dist + n)->visited = 0;
				n++;
			}
		}
	}

	n = 0;
	printf("prim算法遍历结果\n");
	*(node + n++) = v-1;

	for (i = 0; i < G.vnum - 1; i++) {
		Mindist = INFINITE;
		for (j = 0; j < n; j++) {
			v = *(node + j);			//当前节点值（数组序号为：n值-1）
			for (k = 0; k < G.vnum; k++) {
				if ( Mindist > *(*(G.node+v)+k) )
				{
					for (p = 0; p < G.anum; p++)
					{
						if ((dist + p)->v == v && (dist + p)->w == k && (dist + p)->visited != 1
							&& !IsLoop(node,v,k,n)) {
							x = v;
							y = k;
							q = p;
							Mindist = *(*(G.node + v) + k);
						}
					}
				}//if

			}
		}
		printf("%d->%d\n", x+1, y+1);
		(dist + q)->visited = 1;		//设置该边已经访问
		*(node + n++) = y;

	}

}
