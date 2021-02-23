#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 150

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

int main()
{
  char *infix = "1+((2+3)*4)-5";
  char *surfix = (char*)malloc(sizeof(char)*MAX_SIZE);
  int result = 0;

  memset(surfix, '\0', MAX_SIZE);
  Infix2Surfix(infix, surfix);
  printf("surfix : %s\n", surfix);

  CalcSurfix(surfix, &result);
  printf("calc %s is : %d\n", infix, result);

  return 0;
}

// 获取栈顶元素
char GetStackTop(Stack *stak) {
  if (stak->top == -1) {
    return ' ';
  }
  return stak->data[stak->top];
}

// 入栈操作
bool Push2Stack(Stack *stak, char data) {
  if (stak->top == MAX_SIZE-1){
    printf("stack full\n");
    return false;
  }
  stak->data[++stak->top] = data;
  return true;
}

// 出栈操作
bool Pop4Stack(Stack *stak, char *data) {
  if (stak->top == -1) {
    printf("stack empty\n");
    return false;
  }
  *data = stak->data[stak->top--];
  return true;
}

// 校验操作符是否有效
bool validateOp(char op) {
  if (op != '*' && op != '/' && op == '+' && op == '-') {
    printf("invalid op\n");
    return false;
  }
  return true;
}

// 操作符权值
bool opWeight(char op, char *wOp) {
  if (!validateOp(op)) {
    return false;
  };

  if (op == '*' || op == '/') {
    *wOp = 1;
  } else {
    *wOp = -1;
  }

  return true;

}

// 判断操作符优先级
int PriorityJudge(char op1, char op2) {
  int wOp1 = 0;
  int wOp2 = 0;

  opWeight(op1, &wOp1);
  opWeight(op2, &wOp2);

  return wOp1 - wOp2;
}

// 中缀表达式转换为后缀表达式
bool Infix2Surfix(char *infix, char *surfix) {

  Stack  stackExp; // 表达式输出栈
  Stack  stackOp;  // 操作符存储栈

  // 初始化栈
  stackExp.top = -1;
  stackOp.top = -1;
  char tmp = ' ';
  int i = 0;

  while (infix[i] != '\0') {
    if (isdigit(infix[i])) {
      // 数字直接输出
      Push2Stack(&stackExp, infix[i]);
    } else if (infix[i] == '(') {
      // 左括号压入操作符栈中
      Push2Stack(&stackOp, infix[i]);
    } else if (infix[i] == ')') {
      // 右括号从操作符栈中弹出运算符，并压入表达式栈
      Pop4Stack(&stackOp, &tmp);
      while (tmp != '(') {
        Push2Stack(&stackExp, tmp);
        Pop4Stack(&stackOp, &tmp);
      }
    } else if (infix[i] == '+'
               || infix[i] == '-'
               ||infix[i] == '*'
               ||infix[i] == '/') {
       OP:
       tmp = GetStackTop(&stackOp);
       // 操作数优先级大于栈顶元素或栈为空
       if (stackOp.top == -1 || tmp == '('
           || PriorityJudge(infix[i], tmp) > 0) {
         Push2Stack(&stackOp, infix[i]);
       } else {
           Pop4Stack(&stackOp, &tmp);
           Push2Stack(&stackExp, tmp);
           goto OP;
       }
    } else if (infix[i] == ' '){
      // do nothing
    } else {
      printf("invalid expression \n");
      return false;
    }
    i++;
  }

  // 将存储操作符的堆栈内容压入表达式堆栈中
  while (Pop4Stack(&stackOp, &tmp)) {
    Push2Stack(&stackExp, tmp);
  }

  i = stackExp.top;
  while (Pop4Stack(&stackExp, &tmp)) {
    surfix[i--] = tmp;
  }

  return true;
}

// 中缀表达式数值入栈
bool Push2StackN(StackN *stak, int data) {
  if (stak->top == MAX_SIZE-1){
    printf("stack full\n");
    return false;
  }
  stak->data[++stak->top] = data;
  return true;
}

// 中缀表达式数值出栈
bool Pop4StackN(StackN *stak, int *data) {
  if (stak->top == -1) {
    printf("stack empty\n");
    return false;
  }
  *data = stak->data[stak->top--];
  return true;
}

// 结果计算
int Calc(char operandA, char operandB, char op) {
  switch (op) {
  case '+':
    return operandA + operandB;
  case '-':
    return operandA - operandB;
  case '*':
    return operandA * operandB;
  case '/':
    return operandA / operandB;
  }
}

// 中缀表达式求值
bool CalcSurfix(char *surfix, int *data) {
  StackN stack;
  stack.top = -1;
  int i = 0;

  int operandA = 0;
  int operandB = 0;

  while (surfix[i] != '\0') {
    if (isdigit(surfix[i])) {
      // 数字直接入栈
      Push2StackN(&stack, surfix[i]-'0');
    } else if (validateOp(surfix[i])){
      Pop4StackN(&stack, &operandB);
      Pop4StackN(&stack, &operandA);
      Push2StackN(&stack, Calc(operandA, operandB, surfix[i]));
    } else {
      printf("invalid surfix \n");
      return false;
    }
    i++;
  }

  *data = stack.data[0];
  return true;
}
