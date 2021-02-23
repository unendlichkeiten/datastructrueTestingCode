#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 150

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

// ��ȡջ��Ԫ��
char GetStackTop(Stack *stak) {
  if (stak->top == -1) {
    return ' ';
  }
  return stak->data[stak->top];
}

// ��ջ����
bool Push2Stack(Stack *stak, char data) {
  if (stak->top == MAX_SIZE-1){
    printf("stack full\n");
    return false;
  }
  stak->data[++stak->top] = data;
  return true;
}

// ��ջ����
bool Pop4Stack(Stack *stak, char *data) {
  if (stak->top == -1) {
    printf("stack empty\n");
    return false;
  }
  *data = stak->data[stak->top--];
  return true;
}

// У��������Ƿ���Ч
bool validateOp(char op) {
  if (op != '*' && op != '/' && op == '+' && op == '-') {
    printf("invalid op\n");
    return false;
  }
  return true;
}

// ������Ȩֵ
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

// �жϲ��������ȼ�
int PriorityJudge(char op1, char op2) {
  int wOp1 = 0;
  int wOp2 = 0;

  opWeight(op1, &wOp1);
  opWeight(op2, &wOp2);

  return wOp1 - wOp2;
}

// ��׺���ʽת��Ϊ��׺���ʽ
bool Infix2Surfix(char *infix, char *surfix) {

  Stack  stackExp; // ���ʽ���ջ
  Stack  stackOp;  // �������洢ջ

  // ��ʼ��ջ
  stackExp.top = -1;
  stackOp.top = -1;
  char tmp = ' ';
  int i = 0;

  while (infix[i] != '\0') {
    if (isdigit(infix[i])) {
      // ����ֱ�����
      Push2Stack(&stackExp, infix[i]);
    } else if (infix[i] == '(') {
      // ������ѹ�������ջ��
      Push2Stack(&stackOp, infix[i]);
    } else if (infix[i] == ')') {
      // �����ŴӲ�����ջ�е������������ѹ����ʽջ
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
       // ���������ȼ�����ջ��Ԫ�ػ�ջΪ��
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

  // ���洢�������Ķ�ջ����ѹ����ʽ��ջ��
  while (Pop4Stack(&stackOp, &tmp)) {
    Push2Stack(&stackExp, tmp);
  }

  i = stackExp.top;
  while (Pop4Stack(&stackExp, &tmp)) {
    surfix[i--] = tmp;
  }

  return true;
}

// ��׺���ʽ��ֵ��ջ
bool Push2StackN(StackN *stak, int data) {
  if (stak->top == MAX_SIZE-1){
    printf("stack full\n");
    return false;
  }
  stak->data[++stak->top] = data;
  return true;
}

// ��׺���ʽ��ֵ��ջ
bool Pop4StackN(StackN *stak, int *data) {
  if (stak->top == -1) {
    printf("stack empty\n");
    return false;
  }
  *data = stak->data[stak->top--];
  return true;
}

// �������
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

// ��׺���ʽ��ֵ
bool CalcSurfix(char *surfix, int *data) {
  StackN stack;
  stack.top = -1;
  int i = 0;

  int operandA = 0;
  int operandB = 0;

  while (surfix[i] != '\0') {
    if (isdigit(surfix[i])) {
      // ����ֱ����ջ
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
