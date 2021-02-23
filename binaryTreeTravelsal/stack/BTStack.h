#ifndef BTSTACK_H_INCLUDED
#define BTSTACK_H_INCLUDED

#include "../binaryTreeTravelsal.h"

typedef struct BTStackNode{
    BiTNode data;
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
bool Push2Stack(BTStack stack, BiTNode btNode);
// ��ջ
bool Pop4Stack(BTStack stack, BiTNode *btNode);
// ȡջ��Ԫ��
bool GetTopElem(BTStack stack, BiTNode *btNode);

#endif // BTSTACK_H_INCLUDED
