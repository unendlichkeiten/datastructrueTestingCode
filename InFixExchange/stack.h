#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// ���ʽ�洢ջ����
typedef struct NodeExp {
  char data[MAX_SIZE];
  int  top;
} Stack;

// ���ʽ��ֵջ����
typedef struct {
  int data[MAX_SIZE];
  int top;
} StackN;

// ��ȡջ��Ԫ��
char GetStackTop(Stack *stak);
// ��ջ����
bool Push2Stack(Stack *stak, char data);
// ��ջ����
bool Pop4Stack(Stack *stak, char *data);
// У��������Ƿ���Ч
bool validateOp(char op);
// ������Ȩֵ
bool opWeight(char op, char *wOp);
// �жϲ��������ȼ�
int PriorityJudge(char op1, char op2);

// ��׺���ʽ��ֵ��ջ
bool Push2StackN(StackN *stak, int data);
// ��׺���ʽ��ֵ��ջ
bool Pop4StackN(StackN *stak, int *data);
// �������
int Calc(char operandA, char operandB, char op);

// ��׺���ʽת��Ϊ��׺���ʽ
bool Infix2Surfix(char *infix, char *surfix);
// ��׺���ʽת��Ϊǰ׺���ʽ
bool Infix2Prefix(char *infix, char *prefix);
// ��׺���ʽ����
bool CalcSurfix(char *surfix, int *data);
// ǰ׺���ʽ����
bool CalcPrefix(char *prefix, int *data);

#endif // STACK_H_INCLUDED
