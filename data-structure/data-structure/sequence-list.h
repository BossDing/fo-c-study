/*
Status�����������:
0������ʧ�ܣ�
1�������ɹ�.
*/
#define FAIL 0
#define SUCCESS 1 //�����ɹ�
#define OVERFOLW -1 //���� -1 Ϊ OVERFOLW ����
#define DEFAULT_CAPACITY 10			//Ĭ�ϳ�ʼ������С
#define CAPACITY_INCREAM_MULTPLE 1.5	//Ĭ�����ݱ���

#define DEFAULT_ELEM_LENGTH 10			//Ĭ��Ԫ�ص��ַ����ȣ����ڴ�ӡԪ�أ�
#define ELEM_LEN_INCREAM_MULTPLE 2	//Ĭ��Ԫ���ַ����ȵ��������������ڴ�ӡԪ�أ�
typedef void* ElemType;
typedef int Status;

typedef struct SequenceList{
	ElemType *elem;	//�洢�ռ��ַ
	int length;		//��ǰ����
	int capacity;	//����
} SqList;
/*	��ʼ�����Ա�	*/
Status initSqList(SqList *L);
/*	���Ա�����	*/
Status increamCapacity(SqList *L);
/*	�����Ա�ĩβ����Ԫ��	*/
Status insertSqList(SqList *L, ElemType elem);
/*	�����Ա�ָ��λ�ò���Ԫ��	*/
Status insertSqListI(SqList *L, ElemType elem, int position);
/*	ɾ�����Ա�ĩβ��Ԫ��	*/
Status deleteSqList(SqList *L, ElemType *elem);
/*	ɾ�����Ա�ָ��λ�õ�Ԫ��	*/
Status deleteSqListI(SqList *L, ElemType *elem, int position);
/*	������Ա�	*/
Status clearSqList(SqList *L);
/*	��ӡ���Ա�	*/
Status printSqList(SqList *L);