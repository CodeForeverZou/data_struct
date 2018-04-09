#pragma once

#include "stdafx.h"

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
