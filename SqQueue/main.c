#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��̬����ʵ��
#define MAX_SIZE 10
typedef int ElemType;
typedef struct {
    ElemType data[MAX_SIZE];
    int front;
    int rear;
} SqQueue;


// ���г�ʼ��
bool InitQueue(SqQueue *queue);
// �жϿն�
bool IsEmptyQueue(SqQueue *queue);
// �ж�����
bool IsFullQueue(SqQueue *queue);
// ������г���(����ϲ�����������)
int QueueLen(SqQueue *queue);
// ���
bool EnQueue(SqQueue *queue, ElemType data);
// ����
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

    // ���
    int i = 0;
    for (i = 0; i < MAX_SIZE; i++) {
      if (result = EnQueue(&queue, i*i+i)) {
        printf("add data is  %d \n", queue.data[queue.rear-1]);
      } else {
        printf("EnQueue failed %d \n", i);
      }
    }

    // ���г���
    printf("SqQueue length is %d\n", QueueLen(&queue));

    // ��ӡ��ͷ����β
    printf("front %d rear %d\n", queue.front, queue.rear);

    // ����
    if (IsFullQueue(&queue)) {
      printf("Full queue\n");
    }

    // ����
    for (i = 0; i < MAX_SIZE; i++) {
      if (!(result = DelQueue(&queue, &data))) {
        printf("DelQueue failed %d\n", i);
      }
      printf("del data is %03d\n", data);
    }

    // ���г���
    printf("SqQueue length is %d\n", QueueLen(&queue));

    // ��ӡ��ͷ����β
    printf("front %d rear %d\n", queue.front, queue.rear);

    return 0;

}

// ���г�ʼ��
bool InitQueue(SqQueue *queue){
    if (queue == NULL) {
        return false;
    }
    queue->rear = queue->front = 0;
    return true;
}
// �жϿն�
bool IsEmptyQueue(SqQueue *queue){
    if (queue == NULL) {
        return false;
    }

    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}
// �ж�����
bool IsFullQueue(SqQueue *queue){
    if (queue == NULL) {
        return false;
    }

    if ((queue->rear+1)%MAX_SIZE == queue->front) {
        return true;
    }
    return false;
}
// ������г���(����ϲ�����������)
int QueueLen(SqQueue *queue){
    if (queue == NULL) {
        return -1;
    }
    return (queue->rear-queue->front+MAX_SIZE)%MAX_SIZE;
}
// ���
bool EnQueue(SqQueue *queue, ElemType data) {
    if (IsFullQueue(queue)) {
        return false;
    }

    queue->data[queue->rear] = data;
    queue->rear = (queue->rear+1)%MAX_SIZE;
    return true;
}
// ����
bool DelQueue(SqQueue *queue, ElemType *data) {
    if (IsEmptyQueue(queue)) {
        return false;
    }

    *data = queue->data[queue->front];
    queue->front = (queue->front+1)%MAX_SIZE;

    return true;
}

