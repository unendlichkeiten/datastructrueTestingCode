#ifndef BTSTACK_H_INCLUDED
#define BTSTACK_H_INCLUDED

#include "../binaryTreeTravelsal.h"

typedef struct BTStackNode{
    struct BiTNode *data;
    struct BTStackNode *next;
} BTStackNode, *BTStack;

// ��ջУ��
bool validStack(BTStack stack);
// �����������ڵ�ջ
BTStack CreateBTStack();
// ��ʼ����ջ
bool InitStack(BTStack stack);
// �п�
bool IsEmptyStack(BTStack stack);
// ��ջ
bool Push2Stack(BTStack stack, struct BiTNode *btNode);
// ��ջ
bool Pop4Stack(BTStack stack, struct BiTNode **btNode);
// ȡջ��Ԫ��
bool GetTopElem(BTStack stack, struct BiTNode **btNode);

#endif // BTSTACK_H_INCLUDED
