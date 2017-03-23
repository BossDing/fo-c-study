#define FALSE 0		//��
#define TRUE 1		//��
#define FAIL_NULL  -3	//����ʧ�ܣ�δ��ʼ��LinkList��
#define FAIL_LIMIT -2	//����ʧ�ܣ�����Խ�磩
#define FAIL_EMPTY -1	//����ʧ�ܣ�����Ϊ�գ�
#define FAIL 0		//����ʧ��
#define SUCCESS 1	//�����ɹ�
#define MAXSIZE 1000	//�������󳤶�
typedef int ElemType;
typedef int Status;
//�趨 StaticList[0].curΪ��ǰ��������ָ��ڵ��λ�ã�StaticList[MAXSIZE-1].curΪ��ǰ����ͷ����λ��
typedef struct StaticLinkList {
	ElemType data;
	int cur;
} StaticLinkListNode, StaticLinkList[MAXSIZE];
/* ��ʼ�� */
Status initStaticLinkList(StaticLinkList L);
/* ���䱸�ÿռ� */
int mallocStaticLinkList(StaticLinkList L);
/* �ͷ�ռ�ÿռ�Ϊ���ÿռ� */
void freeStaticLinkList(StaticLinkList L, int position);
/* ���루β�巨�� */
Status addStaticLinkList(StaticLinkList L);
/* �޸� */
Status setStaticLinkList(StaticLinkList L);
/* ��ȡ */
ElemType getStaticLinkList(StaticLinkList L, int position);
/* ɾ�� */
ElemType removeStaticLinkList(StaticLinkList L, int position);

int lengthStaticLinkList(StaticLinkList L);
