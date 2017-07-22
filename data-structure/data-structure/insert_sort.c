#include<stdio.h>
#define MAXSIZE 20	//����˳�����󳤶�
typedef int KeyType;	//�ؼ�������
typedef char InfoType;	//��������������
typedef struct {
	KeyType key;	//�ؼ�����
	InfoType otherinfo;	//����������
} RedType;
typedef struct {
	RedType r[MAXSIZE + 1];	//r[0]���û������ڱ���Ԫ
	int length;	//˳�����
}SqList;	//˳�������
//*********��������**********************
//*********ϣ����������(���ȶ�)***********
void sheel_insert_sort(SqList *L) {
	int i, j, dk;
	int len = L->length;
	for (dk = len / 2; dk >= 1; dk = dk / 2) {	//ÿɨ��һ�Σ�������dk����һ���۰봦����
		for (i = dk + 1; i <= len; ++i) {
			if (L->r[i].key < L->r[i - dk].key) {
				L->r[0]=L->r[i];	//�ݴ���r[0]
				for (j = i - dk; j > 0 && L->r[0].key < L->r[j].key; j -= dk)
					L->r[j + dk] = L->r[j];	//��¼����
				L->r[j + dk] = L->r[0];	//���뵽��ȷλ��
			}
		}
	}
}
//*********�۰��������(�ȶ�)***********
void half_insert_sort(SqList *L) {
	int i, j, low, high, mid, len = L->length;
	for (i = 2; i <= len; i++) {
		L->r[0] = L->r[i];	//�ݴ���r[0]
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;	//�۰�
			if (L->r[mid].key > L->r[0].key)	
				high = mid - 1;	//������ڵͰ���
			else
				low = mid + 1;	//������ڸ߰���
		}
		for (j = i - 1; j >= high + 1; --j)
			L->r[j + 1] = L->r[j];	//��¼����
		L->r[high + 1]= L->r[0];	//���뵽��ȷλ��
	}
}
//*********ֱ�Ӳ�������(�ȶ�)***********
void direct_insert_sort(SqList *L) {
	int i, j, len = L->length;
	for (i = 2; i <= len; i++) {
		if (L->r[i].key < L->r[i-1].key) {
			L->r[0] = L->r[i];		//L->r[0]�����ڱ�λ
			L->r[i] = L->r[i - 1];
			for (j = i - 2; L->r[0].key < L->r[j].key; --j) {
				L->r[j + 1] = L->r[j];		//��¼����
			}
			L->r[j + 1] = L->r[0];			//���뵽��ȷλ��
		}
	}
};

void insert_sort_test() {
	int length = 8;
	SqList L = { 
		{ 
			{ 0,0 },{ 21,'a' },{ 32,'b' },{ 46,'d' },{ 40,'c' },
			{ 80,'f' },{ 69,'e' },{ 90,'g' },{ 94,'h' }
		},
		length 
	};
	//direct_insert_sort(&L);
	//half_insert_sort(&L);
	sheel_insert_sort(&L);
	for (int i = 1; i <= length; i++){
		printf("{%d,%c}, ", L.r[i].key, L.r[i].otherinfo);
	}
	printf("\n");
	
};