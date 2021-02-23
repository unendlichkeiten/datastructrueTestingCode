#include "BTStack.h"

// ��ջУ��
bool validStack(BTStack stack) {
  return stack != NULL ? true : false;
}// validStack

// �����������ڵ�ջ
BTStack CreateBTStack() {
  return (BTStack)malloc(sizeof(BTStackNode));
}// CreateBTStack

// ��ʼ����ջ
bool InitStack(BTStack stack){
  if (!validStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  stack->next = NULL;
}// InitStack

// �п�
bool IsEmptyStack(BTStack stack) {
  if (!validStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  return stack->next == NULL ? true : false;
}// IsEmptyStack

// ��ջ
bool Push2Stack(BTStack stack, struct BiTNode *btNode) {
  if (!validStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  // ջ��Ԫ�س�ʼ��
  BTStackNode *stackNode = NULL;
  if (!(stackNode = (BTStackNode*)malloc(sizeof(BTStackNode)))) {
    return false;
  }
  stackNode->data = btNode;
  stackNode->next = NULL;

  // ��ջ����
  stackNode->next = stack->next;
  stack->next = stackNode;

  return true;
}// Push2Stack

// ��ջ
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

// ȡջ��Ԫ��
bool GetTopElem(BTStack stack, struct BiTNode **btNode) {
  if (!validStack(stack) || IsEmptyStack(stack)){
    printf("stack invalid\n");
    return false;
  }

  *btNode = stack->next->data;
  return true;
}// GetTopElem
