#pragma once

#include "stdafx.h"

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

AlGraph CreatGraph() {
	AlGraph G;
	InitAlGraph(G);
	printf("请使用英文输入法\n请输入图的顶点数，边数：");
	scanf("%d,%d%*c", &G.vnum, &G.anum);
	int i;
	
	for ( i = 0; i < G.vnum; i++)
	{
#if CHAR
		G.vertices[i].vertex = char(65 + i);
		printf("%c\t", G.vertices[i].vertex);
#elif INT
		G.vertices[i].vertex = i ;
		printf("%d\t", G.vertices[i].vertex);
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
		n = v;
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

void TraverseG(AlGraph G) {
	int i;
	ArcNode *vn;
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