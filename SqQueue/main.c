#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 静态数组实现
#define MAX_SIZE 10
typedef int ElemType;
typedef struct {
    ElemType data[MAX_SIZE];
    int front;
    int rear;
} SqQueue;


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

int main()
{
    SqQueue  queue;
    ElemType data = -1;
    bool     result = false;

    if (result = InitQueue(&queue)) {
      printf("InitQueue success\n");
    }

    if (result = IsEmptyQueue(&queue)) {
      printf("Empty queue\n");
    }

    // 入队
    int i = 0;
    for (i = 0; i < MAX_SIZE; i++) {
      if (result = EnQueue(&queue, i*i+i)) {
        printf("add data is  %d \n", queue.data[queue.rear-1]);
      } else {
        printf("EnQueue failed %d \n", i);
      }
    }

    // 队列长度
    printf("SqQueue length is %d\n", QueueLen(&queue));

    // 打印对头，队尾
    printf("front %d rear %d\n", queue.front, queue.rear);

    // 判满
    if (IsFullQueue(&queue)) {
      printf("Full queue\n");
    }

    // 出队
    for (i = 0; i < MAX_SIZE; i++) {
      if (!(result = DelQueue(&queue, &data))) {
        printf("DelQueue failed %d\n", i);
      }
      printf("del data is %03d\n", data);
    }

    // 队列长度
    printf("SqQueue length is %d\n", QueueLen(&queue));

    // 打印对头，队尾
    printf("front %d rear %d\n", queue.front, queue.rear);

    return 0;

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

