#include "stdafx.h"
#include "graph.h"


void test() {

	AlGraph G=CreatGraph();
	PrintG(G);
	DFS(G);
	BFS(G);
	system("pause");
	getchar();
}
