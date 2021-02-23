#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 静态数组实现
#define MAX_SIZE 10
#define EMPTY    0
#define SQ_1     1
#define SQ_2     2

typedef int ElemType;
typedef struct {
    ElemType data[MAX_SIZE];
    int front;
    int rear;
} SqQueue;

typedef struct{
    SqQueue *sq1;
    SqQueue *sq2;
    // 1:表示元素在sq1中，2:表示元素在sq2中，0:表示空栈
    int     exist;
} Stack;

// 队列初始化
bool InitQueue(SqQueue *queue);
// 判断空队
bool IsEmptyQueue(SqQueue *queue);
// 判断满队
bool IsFullQueue(SqQueue *queue);
// 计算队列长度(考研喜欢玩这个东西)
int QueueLen(SqQueue *queue);
// 入队
bool EnQueue(SqQueue *queue, ElemType data);
// 出队
bool DelQueue(SqQueue *queue, ElemType *data);
// 队列实现入栈操作
bool StackPush(Stack *stack, ElemType data);
// 队列实现出栈操作
bool StackPop(Stack *stack, ElemType *data);

int main()
{
    int i = 0;
    Stack stack;
    ElemType data = -1;
    bool result = false;

    // 初始化
    SqQueue sq1, sq2;
    if (!(InitQueue(&sq1) && InitQueue(&sq2))) {
      return -1;
    }
    stack.sq1 = &sq1;
    stack.sq2 = &sq2;
    stack.exist = EMPTY;


    // 入栈
    for (i = 0; i < MAX_SIZE; i++) {
      if (!(result = StackPush(&stack, i*i+i))) {
        printf("StackPush failed \n");
        continue;
      }

      if (stack.exist == SQ_1) {
        printf("push data is %d exist %d\n", stack.sq1->data[stack.sq1->rear-1], stack.exist);
      } else if (stack.exist == SQ_2) {
        printf("push data is %d exist %d\n", stack.sq2->data[stack.sq2->rear-1], stack.exist);
      }
    }

    // 出栈
    result = false;
    for (i = 0; i < MAX_SIZE; i++) {
      if (!(result = StackPop(&stack, &data))) {
        printf("StackPush failed \n");
        continue;
      }

      if (stack.exist == SQ_1) {
        printf("pop data is %d exist %d\n", data, stack.exist);
      } else if (stack.exist == SQ_2) {
        printf("pop data is %d exist %d\n", data, stack.exist);
      }
    }

    printf("stack exist is %d\n", stack.exist);


}

// 队列初始化
bool InitQueue(SqQueue *queue){
    if (queue == NULL) {
        return false;
    }
    queue->rear = queue->front = 0;
    return true;
}
// 判断空队
bool IsEmptyQueue(SqQueue *queue){
    if (queue == NULL) {
        return false;
    }

    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}
// 判断满队
bool IsFullQueue(SqQueue *queue){
    if (queue == NULL) {
        return false;
    }

    if ((queue->rear+1)%MAX_SIZE == queue->front) {
        return true;
    }
    return false;
}
// 计算队列长度(考研喜欢玩这个东西)
int QueueLen(SqQueue *queue){
    if (queue == NULL) {
        return -1;
    }
    return (queue->rear-queue->front+MAX_SIZE)%MAX_SIZE;
}
// 入队
bool EnQueue(SqQueue *queue, ElemType data) {
    if (IsFullQueue(queue)) {
        return false;
    }

    queue->data[queue->rear] = data;
    queue->rear = (queue->rear+1)%MAX_SIZE;
    return true;
}
// 出队
bool DelQueue(SqQueue *queue, ElemType *data) {
    if (IsEmptyQueue(queue)) {
        return false;
    }

    *data = queue->data[queue->front];
    queue->front = (queue->front+1)%MAX_SIZE;

    return true;
}
// 队列实现入栈操作
bool StackPush(Stack *stack, ElemType data){
    if (stack == NULL) {
        return false;
    }

    if (stack->exist == SQ_2) {
        return EnQueue(stack->sq2, data);
    } else {
        if (stack->exist == EMPTY) {
          stack->exist = SQ_1;
        }
        return EnQueue(stack->sq1, data);
    }
}
// 队列实现出栈操作
bool StackPop(Stack *stack, ElemType *data) {
    if (stack == NULL) {
        return false;
    }

    int lenSq1 = (stack->sq1->rear - stack->sq1->front + MAX_SIZE)%MAX_SIZE;
    int lenSq2 = (stack->sq2->rear - stack->sq2->front + MAX_SIZE)%MAX_SIZE;
    if (stack->exist == SQ_1) {
        while(lenSq1>1) {
            DelQueue(stack->sq1, data);
            EnQueue(stack->sq2, *data);
            lenSq1--;
        }

        if (IsEmptyQueue(stack->sq2)) {
            stack->exist = EMPTY;
        } else {
            stack->exist = SQ_2;
        }

        return DelQueue(stack->sq1, data);
    } else if (stack->exist == SQ_2) {
        while(lenSq2>1) {
            DelQueue(stack->sq2, data);
            EnQueue(stack->sq1, *data);
            lenSq2--;
        }

        if (IsEmptyQueue(stack->sq1)) {
            stack->exist = EMPTY;
        } else {
            stack->exist = SQ_1;
        }

        return DelQueue(stack->sq2, data);
    }
}
