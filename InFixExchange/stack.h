#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// 表达式存储栈定义
typedef struct NodeExp {
  char data[MAX_SIZE];
  int  top;
} Stack;

// 表达式求值栈定义
typedef struct {
  int data[MAX_SIZE];
  int top;
} StackN;

// 获取栈顶元素
char GetStackTop(Stack *stak);
// 入栈操作
bool Push2Stack(Stack *stak, char data);
// 出栈操作
bool Pop4Stack(Stack *stak, char *data);
// 校验操作符是否有效
bool validateOp(char op);
// 操作符权值
bool opWeight(char op, char *wOp);
// 判断操作符优先级
int PriorityJudge(char op1, char op2);

// 中缀表达式数值入栈
bool Push2StackN(StackN *stak, int data);
// 中缀表达式数值出栈
bool Pop4StackN(StackN *stak, int *data);
// 结果计算
int Calc(char operandA, char operandB, char op);

// 中缀表达式转换为后缀表达式
bool Infix2Surfix(char *infix, char *surfix);
// 中缀表达式转换为前缀表达式
bool Infix2Prefix(char *infix, char *prefix);
// 后缀表达式计算
bool CalcSurfix(char *surfix, int *data);
// 前缀表达式计算
bool CalcPrefix(char *prefix, int *data);

#endif // STACK_H_INCLUDED
