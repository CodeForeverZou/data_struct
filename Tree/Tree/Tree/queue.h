#pragma once

#include "stdafx.h"

#if TREE
void InitQueue(Queue &Q) {
	Q.rear = 0;
	Q.top = 0;
}
void EnQueue(Queue &Q, BTree p) {
	Q.node[Q.top++] = p;
}

BTree DeQueue(Queue &Q) {
	return Q.node[Q.rear++];
}
#elif GRAPH
void InitQueue(Queue &Q) {
	Q.rear = 0;
	Q.top = 0;
	for (int i = 0; i < MAX; i++)
	{
		Q.node[i] = 0;
	}
}
void EnQueue(Queue &Q, int p) {
	Q.node[Q.top++] = p;
}

int DeQueue(Queue &Q) {
	return Q.node[Q.rear++];
}
#endif // TREE



