#include<stdio.h>
#include<stdlib.h>
#include "link-queue.h"

void InitLQueue(LinkQueue * Q)
{
	Q->front = (LinkNode *)malloc(sizeof(LinkNode));
	Q->rear = Q->front;
	Q->front->next = NULL;
}

Boolean LQueueEmpty(LinkQueue * Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

int LQueueLength(LinkQueue * Q)
{
	int len = 0;
	LinkNode *q =  Q->front;
	while (q != Q->rear) {
		len++;
		q = q->next;
	}
	return len;
}

void EnLQueue(LinkQueue * Q, ElemType x)
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q->rear->next= s;
	Q->rear = s;
}

void DeLQueue(LinkQueue * Q, ElemType * x)
{
	if (!LQueueEmpty(Q)) {
		LinkNode *p = Q->front->next;
		*x = p->data;
		Q->front->next = p->next;
		/*
			ע�⣺��ԭ�����г�ͷ�����ֻ��һ����ֵ�ڵ㣬��ɾ�����գ�
			��ʱ��βָ��Ҳ���գ������������Ļ����������Ҫ��βָ������ָ��ڵ��ָ�롣
			�������if������
		*/
		if (p == Q->rear)
			Q->rear = Q->front;
		free(p);
	}
	else {
		printf("Error:The Queue is empty!\n");
	}
}

void GetLHead(LinkQueue * Q, ElemType * x)
{
	if (!LQueueEmpty(Q)) {
		LinkNode *p = Q->front->next;
		*x = p->data;
	}
	else {
		printf("Error:The Queue is empty!\n");
	}
}
