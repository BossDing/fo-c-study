#include<stdio.h>
#define MAXSIZE 20	//����˳�����󳤶�
#define TRUE 1  
#define FALSE 0 
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

//*********ð������-begin***********
void bubble_sort(SqList *L) {
	int i, j, flag, len = L->length;
	for (i = 1; i < len - 1; i++) {
		flag = FALSE; //������ʶ����ð���Ƿ��������ı�־
		for (j = len - 1; j > i; j--) {	//һ��ð�ݹ���
			if (L->r[j - 1].key > L->r[j].key) {	//��Ϊ����
				//���н���
				L->r[0] = L->r[j - 1];	//�ݴ���r[0]
				L->r[j - 1] = L->r[j];
				L->r[j] = L->r[0];
				flag = TRUE;
			}
		}
		if (flag == FALSE) {
			return;	//����ð��û�з���������˵�����Ѿ������ˣ���������
		}
	}
};//*********ð������-end***********

//****************��������-begin****************
int partition(SqList *L, int low, int high) {
	RedType pivot = L->r[low];	//���õ�һ��Ԫ����Ϊ��Ŧֵ���Ա���л��֣������㷨������Ӱ��Ĺؼ�֮����
	while (low < high) {	//ѭ����������
		while (low < high && L->r[high].key >= pivot.key)
			--high;
		L->r[low] = L->r[high];	//������ŦֵС��Ԫ���ƶ������
		while (low < high && L->r[low].key <= pivot.key)
			++low;
		L->r[high] = L->r[low];	//������Ŧֵ���Ԫ���ƶ����Ҷ�
	}
	L->r[low] = pivot;	//��ŦԪ�ش�ŵ�����λ��
	return low;	//���ش����Ŧ������λ��
}
void quick_sort1(SqList *L, int low, int high) {
	if (low < high) {	//�ݹ���������
		int pivotpos = partition(L, low, high);	//����
		//���ζ������ӱ���еݹ�����
		quick_sort1(L, low, pivotpos - 1);	
		quick_sort1(L, pivotpos + 1, high);
	}
}
void quick_sort(SqList *L) {
	quick_sort1(L, 1, L->length);
};//****************��������-end****************

void main() {
	int length = 8;
	SqList L = {
		{
			{ 0,0 },{ 21,'a' },{ 32,'b' },{ 46,'d' },{ 40,'c' },
			{ 80,'f' },{ 69,'e' },{ 90,'g' },{ 94,'h' }
		},
		length
	};
	//bubble_sort(&L);
	quick_sort(&L);
	for (int i = 1; i <= length; i++) {
		printf("{%d,%c}, ", L.r[i].key, L.r[i].otherinfo);
	}
	printf("\n");

};