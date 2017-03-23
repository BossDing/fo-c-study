#define FALSE 0		//��
#define TRUE 1		//��
#define FAIL_NULL  -3	//����ʧ�ܣ�δ��ʼ��LinkList��
#define FAIL_LIMIT -2	//����ʧ�ܣ�����Խ�磩
#define FAIL_EMPTY -1	//����ʧ�ܣ�����Ϊ�գ�
#define FAIL 0		//����ʧ��
#define SUCCESS 1	//�����ɹ�
typedef int ElemType;
typedef int Status;
typedef struct LinkListNode{
	ElemType data;
	struct LinkListNode *next;
} LNode, *LinkList;


/*	�½����Ա���ͷ��㣬ͷ���洢��ֵΪ���Ա��ȣ�	*/
LinkList newLinkList();
/*	�ж����Ա��Ƿ�Ϊ��	*/
Status isLinkListEmpty(LinkList L);
/*	�ж�λ���Ƿ������Ա�Χ��	*/
Status isInLinkListLimit(LinkList L, int position);
/*	�����Ա�ĩβ����Ԫ�أ�β�巨��	*/
Status addLinkList(LinkList L, ElemType elem);
/*	�����Ա�ͷ������Ԫ�أ�ͷ�巨��	*/
Status addLinkListHead(LinkList L, ElemType elem);
/*	�����Ա�ָ��λ�ò���Ԫ��	*/
Status addLinkListI(LinkList L, ElemType elem, int position);
/*	�޸����Ա�ָ��λ�õ�Ԫ��	*/
Status setLinkList(LinkList L, ElemType elem, int position);
/*	ɾ�����Ա�ĩβ��Ԫ��	*/
Status removeLinkList(LinkList L, ElemType *elem);
/*	ɾ�����Ա�ָ��λ�õ�Ԫ��	*/
Status removeLinkListI(LinkList L, ElemType *elem, int position);
/*	��ȡ���Ա�ĩβ��Ԫ��	*/
Status lastLinkList(LinkList L, ElemType *elem);
/*	��ȡ���Ա�ָ��λ��(ʵ��Ϊ����position-1λ��)��Ԫ��	*/
Status getLinkList(LinkList L, ElemType *elem, int position);
/*	������Ա�	*/
Status freeLinkList(LinkList L);
/*	��ӡ���Ա�(ע�⣺����ֻʵ��ElemType=int�Ĵ�ӡ�������������͵�����Ҫ�����޸�print�����Ĵ��롣)	*/
Status printLinkList(LinkList L);