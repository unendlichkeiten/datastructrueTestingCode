#ifndef BTSTACK_H_INCLUDED
#define BTSTACK_H_INCLUDED

#include "../binaryTreeTravelsal.h"

typedef struct BTStackNode{
    BiTNode data;
    struct BTStackNode *next;
} BTStackNode, *BTStack;

// 堆栈校验
bool validStack(BTStack stack);
// 创建二叉树节点栈
BTStack CreateBTStack();
// 初始化堆栈
bool InitStack(BTStack stack);
// 判空
bool IsEmptyStack(BTStack stack);
// 入栈
bool Push2Stack(BTStack stack, BiTNode btNode);
// 出栈
bool Pop4Stack(BTStack stack, BiTNode *btNode);
// 取栈顶元素
bool GetTopElem(BTStack stack, BiTNode *btNode);

#endif // BTSTACK_H_INCLUDED
