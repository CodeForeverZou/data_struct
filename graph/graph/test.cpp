#include "stdafx.h"
#include "graph.h"


void test() {

	AlGraph G=CreatGraph();
	PrintG(G);
	DFS(G);
	BFS(G);
}

void test2() {
	int **node;
	node = (int **)malloc(sizeof(int) * 5 * 5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			*(node + i) = (int *)malloc(sizeof(int)*5);			//必须要再次申请
			*(*(node + i) + j) = 1;
			printf("%d ", *(*(node + i) + j));
		}
		printf("\n");
	}
}

void test3() {

	MGraph G = CreatMG();
	Kruskal(G);
	Prim(G, 1);
	
}