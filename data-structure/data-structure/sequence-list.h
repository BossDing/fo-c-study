/*
Status�����������:
0������ʧ�ܣ�
1�������ɹ�.
*/
#define FALSE 0		//��
#define TRUE 1		//��
#define FAIL_LIMIT -2	//����ʧ�ܣ�����Խ�磩
#define FAIL_EMPTY -1	//����ʧ�ܣ�����Ϊ�գ�
#define FAIL 0		//����ʧ��
#define SUCCESS 1	//�����ɹ�
#define OVERFOLW -1 //���� -1 Ϊ OVERFOLW ����
#define DEFAULT_CAPACITY 10			//Ĭ�ϳ�ʼ������С
#define CAPACITY_INCREAM_MULTPLE 1.5	//Ĭ�����ݱ���

#define DEFAULT_ELEM_LENGTH 10			//Ĭ��Ԫ�ص��ַ����ȣ����ڴ�ӡԪ�أ�
#define ELEM_LEN_INCREAM_MULTPLE 1.5	//Ĭ��Ԫ���ַ����ȵ��������������ڴ�ӡԪ�أ�
typedef int ElemType;	//Ŀǰֻ��֧�̶ֹ����͵�Ԫ�أ���Ϊ�ڴ�ӡʱ��Ҫ������
typedef int Status;

typedef struct SequenceList{
	ElemType *elem;	//�洢�ռ��ַ
	int length;		//��ǰ����
	int capacity;	//����
} *SqList;
/*	�½����Ա�	*/
SqList newSqList();
/*	���Ա�����	*/
void increamSqListCapacity(SqList L);
/*	�ж����Ա��Ƿ�Ϊ��	*/
Status isSqListEmpty(SqList L);
/*	�ж�λ���Ƿ������Ա�Χ��	*/
Status isInSqListLimit(SqList L, int position);
/*	�����Ա�ĩβ����Ԫ��	*/
Status addSqList(SqList L, ElemType elem);
/*	�޸����Ա�ָ��λ��(ʵ��Ϊ����position-1λ��)��Ԫ�ء�==��	*/
Status setSqList(SqList L, ElemType elem, int position);
/*	ɾ�����Ա�ĩβ��Ԫ��	*/
Status removeSqList(SqList L, ElemType *elem);
/*	ɾ�����Ա�ָ��λ��(ʵ��Ϊ����position-1λ��)��Ԫ��	*/
Status removeSqListI(SqList L, ElemType *elem, int position);
/*	��ȡ���Ա�ĩβ��Ԫ��	*/
Status lastSqList(SqList L, ElemType *elem);
/*	��ȡ���Ա�ָ��λ��(ʵ��Ϊ����position-1λ��)��Ԫ��	*/
Status getSqList(SqList L, ElemType *elem, int position);
/*	������Ա�	*/
Status clearSqList(SqList L);
/*	��ӡ���Ա�	*/
Status printSqList(SqList L);