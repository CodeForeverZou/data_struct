// Tree.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "tree_methord.h"

/*
void PreCreat(BTree &T) {
	char pre[20] = "";
	int i = 0;
	T->data = pre[0];
	BTNode *p=T;
	for ( i = 1; i < strlen(pre); i++)
	{
		p = (BTree)malloc(sizeof(BTNode));
		if (pre[i]!='#')
		{
			p->data = pre[i];
		}
	}

}
*/

/*
BTree CreatTree() {
BTNode *T,*p, *q;
printf("����������ݹ齨��\n����������ڵ���Ϣ���ԡ�#������\n");
Elem data;
char str;
scanf("%c%*c", &data);


if (data!='#')
{
T = p = (BTree)malloc(sizeof(BTNode));
InitNode(T);
T->data = data;
scanf("%c%*c", &data);

while (data!='#')
{
q = (BTree)malloc(sizeof(BTNode));
InitNode(q);
q->data =data;

}
}


}
*/


int main1()
{
#if GRAPH
	printf("�����л���TREE����\n");
	system("pause");
	return 0;
#endif // GRAPH

	BTree T;
	T = (BTree)malloc(sizeof(BTNode));
	InitNode(T);
	CreatBTree(T);

	N_PreOrder(T);
	N2_PreOrder(T);

	N_InOrder(T);
	N2_InOrder(T);

	N_PostOrder(T);
	N2_PostOrder(T);

	getchar();
	return 0;
}

