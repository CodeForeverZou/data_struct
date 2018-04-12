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

AlGraph CreatGraph() {
	AlGraph G;
	InitAlGraph(G);

#if CHAR
	printf("<<----���ڴ����ַ��������͵�ͼ---->>\nע����ʹ��Ӣ�����뷨,����A��B����ʾ�ڵ�\n\n");
#elif INT
	printf("<<----���ڴ��������������͵�ͼ---->>\nע����ʹ��Ӣ�����뷨,����1��2����ʾ�ڵ�\n\n");
#endif // CHAR

	printf("������ͼ�Ķ�������������");
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

	printf("�������������v-w:\n");
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
			G.vertices[n].firstarc = vn;			//������һ�丳ֵ�����firstarc����NULL
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
	printf("\n�ڽӱ�������ͼ���£�\n");
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

//======================�������======================//
bool visited[MAX] = { false };
void DFSTraverse(AlGraph G, int i);

void DFS(AlGraph G) {
	int i;
	printf("������ȱ���˳��Ϊ��\n");
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
			DFSTraverse(G, n);						//����д��DFSTraverse[G,(int(p->adjvex) - 65)];
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


//======================�������======================//
void BFSTraverse(AlGraph G, int i);

void BFS(AlGraph G) {
	for (int j = 0; j < MAX; j++) visited[j] = false;		//����д��visited[MAX]={false}
	printf("������ȱ���˳��Ϊ��\n");
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
			i = int(p->adjvex) - 65;					//ע�������i;
			if (!visited[i]) {
				EnQueue(Q, i);
				printf("%c->", char(i + 65));
				visited[i] = true;
			}
#elif INT
			i = p->adjvex - 1;					//ע�������i;
			if (!visited[i]) {
				EnQueue(Q, i);
				printf("%d->", i + 1);
				visited[i] = true;
			}
#endif // CHAR

		}
	}
}
