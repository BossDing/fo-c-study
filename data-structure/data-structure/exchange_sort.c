#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20	//����˳�����󳤶�
#define TRUE 1  
#define FALSE 0 
typedef int KeyType;	//�ؼ�������
typedef char InfoType;	//��������������
typedef struct {
	KeyType key;	//�ؼ�����
	//InfoType otherinfo;	//����������
} RedType;
typedef struct {
	RedType r[MAXSIZE + 1];	//r[0]���û������ڱ���Ԫ
	int length;	//˳�����
}SqList;	//˳�������
//*********�������򣨽Բ��ȶ���*********
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
		//���Դ���,���ڹ۲�ÿһ��������
		
		for (int m = 1; m < L->length; m++) {
			printf("%d, ", L->r[m].key);
		}
		printf("(��%d��)\n",i);
		
		if (flag == FALSE) {
			return;	//����ð��û�з���������˵�����Ѿ������ˣ���������
		}
	}
};//*********ð������-end***********

//****************��������-begin****************
//**********��Ŧ���ֺ������ص㣩**************
int partition(SqList *L, int low, int high) {
	//һ���������
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

	//���Դ���,���ڹ۲�ÿһ��������
	
	for (int i = 1; i < L->length; i++) {
		printf("%d, ", L->r[i].key);
	}
	printf("(��Ŧֵ��%d)\n", pivot.key);
	

	return low;	//���ش����Ŧ������λ��
}
//**********�ݹ��������**************
void quick_sort_recurrence(SqList *L, int low, int high) {
	if (low < high) {	//�ݹ���������
		int pivotpos = partition(L, low, high);	//����
		//���ζ������ӱ���еݹ�����
		quick_sort_recurrence(L, low, pivotpos - 1);
		quick_sort_recurrence(L, pivotpos + 1, high);
	}
};
typedef struct {
	int begin;
	int end;
}Limits_1[MAXSIZE];
//��Էǵݹ��������ʹ�õĸ���ջ
typedef struct {
	Limits_1 limit;
	int top;
}LimitStack;
//��Էǵݹ��������ʹ�õĸ�������
typedef struct {
	Limits_1 limit;
	int font;
	int rear;
}LimitQueue;
//**********�ǵݹ�������򣨸���ջʵ�֣�**************
void quick_sort_1(SqList *L, int low, int high) {
	int pivotpos;
	LimitStack limit_stack;
	limit_stack.top = -1;
	limit_stack.top++;
	limit_stack.limit[limit_stack.top].begin = low;
	limit_stack.limit[limit_stack.top].end = high;
	while (limit_stack.top >= 0) {
		low = limit_stack.limit[limit_stack.top].begin;
		high = limit_stack.limit[limit_stack.top].end;
		limit_stack.top--;
		if (low < high) {
			pivotpos = partition(
				L,low,high
			);
			if (limit_stack.top < MAXSIZE - 1) {
				limit_stack.top++;
			}
			else {
				printf("����ջ��������������ջ�ĳ��Ⱥ��ٳ��ԣ�\n");
				return;
			}
			limit_stack.limit[limit_stack.top].begin = low;
			limit_stack.limit[limit_stack.top].end = pivotpos - 1;
			
			if (limit_stack.top < MAXSIZE-1) {
				limit_stack.top++;
			}
			else {
				printf("����ջ��������������ջ�ĳ��Ⱥ��ٳ��ԣ�\n");
				return;
			}
			limit_stack.limit[limit_stack.top].begin = pivotpos + 1;
			limit_stack.limit[limit_stack.top].end = high;
		}
	}
}
//**********�ǵݹ�������򣨸�������ʵ�֣����������ݹ���������ɨ�����������**************
void quick_sort_2(SqList *L, int low, int high) {
	int pivotpos;
	LimitQueue limit_queue;
	limit_queue.font = 0;
	limit_queue.rear = 0;
	limit_queue.limit[limit_queue.rear].begin = low;
	limit_queue.limit[limit_queue.rear].end = high;
	limit_queue.rear++;
	while (limit_queue.rear != limit_queue.font) {
		low = limit_queue.limit[limit_queue.font].begin;
		high = limit_queue.limit[limit_queue.font].end;
		limit_queue.font = (limit_queue.font + 1) % MAXSIZE;
		if (low < high) {
			pivotpos = partition(
				L, low, high
			);
			limit_queue.limit[limit_queue.rear].begin = low;
			limit_queue.limit[limit_queue.rear].end = pivotpos - 1;
			if ((limit_queue.rear + 1) % MAXSIZE != limit_queue.font ) {
				limit_queue.rear = (limit_queue.rear + 1) % MAXSIZE;
			}else {
				printf("�������������������������еĳ��Ⱥ��ٳ��ԣ�\n");
				return;
			}
			limit_queue.limit[limit_queue.rear].begin = pivotpos + 1;
			limit_queue.limit[limit_queue.rear].end = high;
			if ((limit_queue.rear + 1) % MAXSIZE != limit_queue.font) {
				limit_queue.rear = (limit_queue.rear + 1) % MAXSIZE;
			}else {
				printf("�������������������������еĳ��Ⱥ��ٳ��ԣ�\n");
				return;
			}
		}
	}
}
void quick_sort(SqList *L) {
	quick_sort_recurrence(L, 1, L->length-1);
	//quick_sort_1(L, 1, L->length - 1);
	//quick_sort_2(L, 1, L->length - 1);
};//****************��������-end****************

void main() {
	SqList L1 = { { 0,21, 32,46, 40, 80, 69, 90, 94 }, 9 }; 
	SqList L = { { 0,25, 84,21,47,15, 27,68, 35,20 }, 10 };
	SqList L3 = { { 0, 46, 79,56, 38,40, 84 }, 7 };
	SqList L4 = { { 0,5,9,17,21,23,25,30 }, 8 };
	SqList L5 = { { 0,21,25,5,17,9,23,30 }, 8 };
	SqList L6 = { { 0,25,23,30,17,21,5,9 }, 8 };
	SqList L7 = { { 0,21,9,17,30,25,23,5 }, 8 };

	for (int i = 1; i < L.length; i++) {
		printf("%d, ", L.r[i].key);
	}
	printf("(����ǰ)\n");
	//bubble_sort(&L);
	quick_sort(&L);
	for (int i = 1; i <  L.length; i++) {
		printf("%d, ", L.r[i].key);
	}
	printf("(�����)\n");

};