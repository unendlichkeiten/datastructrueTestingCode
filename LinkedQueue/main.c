#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
} QNode, *Position;

typedef struct {
    Position front;
    Position rear;
} LinkedQueue;

// 队列初始化
bool InitLQueue(LinkedQueue *queue);
// 判空队列
bool IsEmptyLQueue(LinkedQueue *queue);
// 入队
bool EnLQueue(LinkedQueue *queue, ElemType data);
// 出队(特别注意只有一个节点的情况)
bool DelQueue(LinkedQueue *queue, ElemType *data);

int main()
{
  ElemType    data = -1;
  LinkedQueue queue;
  bool result = false;
  int  i = 0;

  // 初始化
  if (result = InitLQueue(&queue)) {
    printf("InitLQueue success \n");
  }

  // 判空
  if (result = IsEmptyLQueue(&queue)) {
    printf("Empty queue\n");
  }

  // 入队
  result = false;
  for (i = 0; i < MAX_SIZE; i++) {
    if (result = EnLQueue(&queue, i*i+i)) {
      printf("add data is %d\n", queue.rear->data);
    } else {
      printf("EnLQueue failed %d\n", i);
    }
  }

  // 判空
  if (!(result = IsEmptyLQueue(&queue))) {
    printf("none Empty queue\n");
  }

  // 出队
  result = false;
  for (i = 0; i < MAX_SIZE; i++) {
    if (result = DelQueue(&queue, &data)) {
      printf("del data is %d\n", data);
    } else {
      printf("DelQueue failed %d\n", i);
    }
  }

  // 判空
  if (result = IsEmptyLQueue(&queue)) {
    printf("Empty queue\n");
  }

  return 0;
}

// 队列初始化
bool InitLQueue(LinkedQueue *queue) {
    if (queue == NULL) {
        return false;
    }

    queue->rear = (QNode*)malloc(sizeof(QNode));
    queue->front = queue->rear;
    queue->front->next = NULL;

    return true;
}
// 判空队列
bool IsEmptyLQueue(LinkedQueue *queue) {
    if (queue == NULL) {
        return false;
    }

    if (queue->rear == queue->front) {
        return true;
    }
    return false;
}
// 入队
bool EnLQueue(LinkedQueue *queue, ElemType data){
    if (queue == NULL) {
        return false;
    }

    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = data;
    newNode->next = NULL;

    queue->rear->next = newNode;
    queue->rear = newNode;
    return true;
}
// 出队(特别注意只有一个节点的情况)
bool DelQueue(LinkedQueue *queue, ElemType *data){
    if (queue == NULL) {
        return false;
    }

    if (queue->rear == queue->front) {
        return false;
    }

    QNode *DelNode = queue->front->next;
    *data = DelNode->data;
    queue->front->next = DelNode->next;
    // 如果原队列只有一个节点，则 rear = front
    if (queue->rear == DelNode) {
        queue->rear = queue->front;
    }
    free(DelNode);
    return true;
}
