#include "BTQueue.h"

// ����У��
bool validQueue(BTQueue *queue) {
  return queue != NULL ? true : false;
}// validQueue

// ��ʼ������
bool InitLQueue(BTQueue *queue) {
    if (!validQueue(queue)) {
        return false;
    }

    queue->rear = (BTQueueNode*)malloc(sizeof(BTQueueNode));
    queue->front = queue->rear;
    queue->front->next = NULL;

    return true;
}// InitLQueue

// �пն���
bool IsEmptyLQueue(BTQueue *queue) {
    if (!validQueue(queue)) {
        printf("invalid queue\n");
        return false;
    }

    if (queue->rear == queue->front) {
        return true;
    }

    return false;
}// IsEmptyLQueue

// ���
bool EnLQueue(BTQueue *queue, struct BiTNode *btNode){
    if (!validQueue(queue)) {
        printf("invalid queue\n");
        return false;
    }

    BTQueueNode *newNode = (BTQueueNode *)malloc(sizeof(BTQueueNode));
    newNode->data = btNode;
    newNode->next = NULL;

    queue->rear->next = newNode;
    queue->rear = newNode;

    return true;
}// EnLQueue

// ����(�ر�ע��ֻ��һ���ڵ�����)
bool DelQueue(BTQueue *queue, struct BiTNode **btNode){
    if (queue == NULL) {
        return false;
    }

    if (queue->rear == queue->front) {
        return false;
    }

    BTQueueNode *DelNode = queue->front->next;
    *btNode = DelNode->data;
    queue->front->next = DelNode->next;
    // ���ԭ����ֻ��һ���ڵ㣬�� rear = front
    if (queue->rear == DelNode) {
        queue->rear = queue->front;
    }
    free(DelNode);

    return true;
}// DelQueue
