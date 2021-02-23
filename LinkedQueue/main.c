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

// ���г�ʼ��
bool InitLQueue(LinkedQueue *queue);
// �пն���
bool IsEmptyLQueue(LinkedQueue *queue);
// ���
bool EnLQueue(LinkedQueue *queue, ElemType data);
// ����(�ر�ע��ֻ��һ���ڵ�����)
bool DelQueue(LinkedQueue *queue, ElemType *data);

int main()
{
  ElemType    data = -1;
  LinkedQueue queue;
  bool result = false;
  int  i = 0;

  // ��ʼ��
  if (result = InitLQueue(&queue)) {
    printf("InitLQueue success \n");
  }

  // �п�
  if (result = IsEmptyLQueue(&queue)) {
    printf("Empty queue\n");
  }

  // ���
  result = false;
  for (i = 0; i < MAX_SIZE; i++) {
    if (result = EnLQueue(&queue, i*i+i)) {
      printf("add data is %d\n", queue.rear->data);
    } else {
      printf("EnLQueue failed %d\n", i);
    }
  }

  // �п�
  if (!(result = IsEmptyLQueue(&queue))) {
    printf("none Empty queue\n");
  }

  // ����
  result = false;
  for (i = 0; i < MAX_SIZE; i++) {
    if (result = DelQueue(&queue, &data)) {
      printf("del data is %d\n", data);
    } else {
      printf("DelQueue failed %d\n", i);
    }
  }

  // �п�
  if (result = IsEmptyLQueue(&queue)) {
    printf("Empty queue\n");
  }

  return 0;
}

// ���г�ʼ��
bool InitLQueue(LinkedQueue *queue) {
    if (queue == NULL) {
        return false;
    }

    queue->rear = (QNode*)malloc(sizeof(QNode));
    queue->front = queue->rear;
    queue->front->next = NULL;

    return true;
}
// �пն���
bool IsEmptyLQueue(LinkedQueue *queue) {
    if (queue == NULL) {
        return false;
    }

    if (queue->rear == queue->front) {
        return true;
    }
    return false;
}
// ���
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
// ����(�ر�ע��ֻ��һ���ڵ�����)
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
    // ���ԭ����ֻ��һ���ڵ㣬�� rear = front
    if (queue->rear == DelNode) {
        queue->rear = queue->front;
    }
    free(DelNode);
    return true;
}
