#include "BTStack.h"

// 堆栈校验
bool validStack(BTStack stack) {
  return stack != NULL ? true : false;
}// validStack

// 创建二叉树节点栈
BTStack CreateBTStack() {
  return (BTStack)malloc(sizeof(BTStackNode));
}// CreateBTStack

// 初始化堆栈
bool InitStack(BTStack stack){
  if (!validStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  stack->next = NULL;
}// InitStack

// 判空
bool IsEmptyStack(BTStack stack) {
  if (!validStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  return stack->next == NULL ? true : false;
}// IsEmptyStack

// 入栈
bool Push2Stack(BTStack stack, struct BiTNode *btNode) {
  if (!validStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  // 栈内元素初始化
  BTStackNode *stackNode = NULL;
  if (!(stackNode = (BTStackNode*)malloc(sizeof(BTStackNode)))) {
    return false;
  }
  stackNode->data = btNode;
  stackNode->next = NULL;

  // 入栈操作
  stackNode->next = stack->next;
  stack->next = stackNode;

  return true;
}// Push2Stack

// 出栈
bool Pop4Stack(BTStack stack, struct BiTNode **btNode) {
  if (!validStack(stack) || IsEmptyStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  BTStackNode *delNode = stack->next;
  stack->next = delNode->next;
  *btNode = delNode->data;
  free(delNode);

  return true;
}// Pop4Stack

// 取栈顶元素
bool GetTopElem(BTStack stack, struct BiTNode **btNode) {
  if (!validStack(stack) || IsEmptyStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  *btNode = stack->next->data;
  return true;
}// GetTopElem
