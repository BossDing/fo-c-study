#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sequence-list.h"

Status initSqList(SqList *L) {
	//�������ɹ��򷵻�ָ�򱻷����ڴ��ָ��(�˴洢���еĳ�ʼֵ��ȷ��)�����򷵻ؿ�ָ��NULL��
	L->elem = (ElemType *)malloc(DEFAULT_CAPACITY*sizeof(ElemType));
	if (!L->elem) exit(OVERFOLW);
	L->length = 0;
	L->capacity = DEFAULT_CAPACITY;
	return SUCCESS;
}
void increamSqListCapacity(SqList *L) {
	if (L->length >= L->capacity) {
		L->capacity = DEFAULT_CAPACITY * CAPACITY_INCREAM_MULTPLE;
		L->elem = (ElemType *)realloc(L->elem, L->capacity * sizeof(ElemType));
		if (!L->elem) exit(OVERFOLW);
	}
}
Status isSqListEmpty(SqList *L) {
	if (L->length == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status isInSqListLimit(SqList *L,int position) {
	if (position<1 || position > L->length) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}
Status addSqList(SqList *L, ElemType elem) {
	increamSqListCapacity(L);
	L->elem[(L->length++)] = elem;
	return SUCCESS;
}
Status setSqList(SqList *L, ElemType elem, int position) {
	if (!isInSqListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	increamSqListCapacity(L);
	L->length++;
	for (int i = L->length-1; i >= position ; i--) {
		L->elem[i] = L->elem[i-1];
	}
	L->elem[position - 1] = elem;
	return SUCCESS;
}
Status removeSqList(SqList *L, ElemType *elem) {
	if (isSqListEmpty(L)) {
		*elem = NULL;
		return FAIL_EMPTY;
	}
	*elem = L->elem[L->length - 1];
	L->length--;
	//�ͷ�ĩβλ�õ��ڴ棿
	//L->elem[L->length] = NULL;
	//free((*L).elem[(*L).length]);
	return SUCCESS;
}
Status removeSqListI(SqList *L, ElemType *elem,int position) {
	if (isSqListEmpty(L)) {
		*elem = NULL;
		return FAIL_EMPTY;
	}
	if (!isInSqListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	*elem = L->elem[position - 1];
	for (int i = position - 1, len = L->length; i <= len - 2; i++) {
		L->elem[i] = L->elem[i + 1];
	}
	L->length--;
	// �ͷ�ĩβԪ���ڴ�?
	return SUCCESS;
}
Status lastSqList(SqList *L, ElemType *elem) {
	if (isSqListEmpty(L)) {
		*elem = NULL;
		return FAIL_EMPTY;
	}
	*elem = L->elem[L->length - 1];
	return SUCCESS;
}

Status getSqList(SqList *L, ElemType *elem, int position) {
	if (!isInSqListLimit(L, position)) {
		*elem = NULL;
		return FAIL_LIMIT;
	}
	*elem = L->elem[position - 1];
	return SUCCESS;
}
Status clearSqList(SqList *L) {
	L->length = 0;
	return SUCCESS;
}
Status printSqList(SqList *L) {
	char *s = (char *)malloc(DEFAULT_ELEM_LENGTH);
	*s = 0;
	// *s = 0 �����������memset(s, 0, len);
	printf("SqList[");
	for (int i = 0, len = L->length; i <= len -1; i++){
		/*_itoa(L->elem[i], s, 10);
		if (strlen(s) > 6) {
			char sTemp[DEFAULT_ELEM_LENGTH*ELEM_LEN_INCREAM_MULTPLE] = { 0 };
			strcat(sTemp, s);
			*s = (char *)malloc(DEFAULT_ELEM_LENGTH*ELEM_LEN_INCREAM_MULTPLE);
			*s = *sTemp;
		}*/
		if (i != len - 1) {
			printf("%d, ", L->elem[i]);
		}
		else {
			printf("%d", L->elem[i]);
		}
	}
	printf("]\n");
	return SUCCESS;
}
