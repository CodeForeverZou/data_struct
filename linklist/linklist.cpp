#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct LNode{
	int data;
	struct LNode *next;			//����д��struct List *
}LNode,*List;


//ͷ�巨
void headCreat(List &L){
	int d=0;
	LNode *head=L,*p;
	scanf("%d",&d);
	while(d){
		p=(List)malloc(sizeof(LNode));

		p->data=d;
		p->next=L->next;
		L->next=p;
		scanf("%d",&d);
	}
}



//β�巨
List tailCreat(){
	int d=0;
	LNode *head,*p,*q;
	scanf("%d",&d);
	if(d){
		head=p=(List)malloc(sizeof(LNode));
		p->data=d;
		p->next=NULL;
		scanf("%d",&d);
		while(d){
			q=(List)malloc(sizeof(LNode));
			p->next=q;
			q->data=d;						//��TM������д��p->dat=d;!!!!!!
			p=q;
			scanf("%d",&d);
		}
		q->next=NULL;
	}
	else{
		head=NULL;
	}
	return head;
			
}




//����
void Traverse(List L){
	LNode *p=L;
	if(p->data==0)p=p->next;				//�����õ�==��������һ��
	while(p){
		printf("%d->",p->data);
		p=p->next;
	}
	printf("\n");

}


void main(){
	List L=(List)malloc(sizeof(LNode));
	L->next=NULL;
	L->data=0;
	headCreat(L);
	Traverse(L);

	L=tailCreat();
	Traverse(L);
	scanf("%d");
}