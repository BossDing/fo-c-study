#include<stdio.h>
#include "static-link-list.h"


Status initStaticLinkList(StaticLinkList L) {
	int i;
	for (i = 0; i < MAXSIZE - 1; i++) {
		L[i].cur = i+1;
	}
	L[MAXSIZE - 1].cur = 0;
	return SUCCESS;
}

int mallocStaticLinkList(StaticLinkList L) {
	int index = L[0].cur;
	//��������ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0
	if (L[0].cur)
		L[0].cur = L[index].cur;
	return index;
}
void freeStaticLinkList(StaticLinkList L, int position) {
	//�������ͷ����λ�õ�����������û����ɶԸ�λ��Ԫ�ص�ɾ�������ƺ�
	L[position].cur = L[0].cur;
	L[0].cur = position;
}

