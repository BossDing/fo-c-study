#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW 0
#define ASSIST_STACK_SIZE 100 //辅助栈大小
#define ASSIST_QUEUE_SIZE 100 //辅助队列大小
#define FALSE 0
#define TRUE 1
typedef int Boolean;
typedef char ElemType;
typedef int Status;

typedef struct {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode,*BiTree;
typedef struct {
	BiTNode data[ASSIST_QUEUE_SIZE];
	int front, rear;
} AssistQueue;
typedef struct {
	BiTNode **base;
	BiTNode **top;
	int size;
} AssistStack;
/*
注意二叉树序列中节点为空在数组用#表示；如序列：AB#D##C##;

			A
		  /   \
		 B     C
	   /  \   /  \
	  #   D   #   #

      (#表示空节点)
	  若序列不对会去掉不对的节点
*/
BiTree ArrayToBiTree(BiTree T, ElemType elem[],int length);
/* 由命令行输入序列，节点为空用#表示 ；如序列：AB#D##C##;

			A
		  /   \
		 B     C
	   /  \   /  \
	  #   D   #   #

      (#表示空节点)
*/
BiTree CreateBiTree(BiTree T);
/* 先序遍历(递归) */
void PreOrder(BiTree T);
/* 先序遍历（非递归） */
void PreOrder2(BiTree T);
/* 中序遍历(递归) */
void InOrder(BiTree T);
/* 中序遍历(非递归) */
void InOrder2(BiTree T);
/* 后序遍历(递归) */
void PostOrder(BiTree T);
/* 后序遍历(非递归) */
void PostOrder2(BiTree T);
/* 层次遍历 */
void LeverOrder(BiTree T);
/* 访问T节点的值 */
void Visit(BiTree T);