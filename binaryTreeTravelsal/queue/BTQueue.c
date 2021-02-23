#include "BTQueue.h"

// 队列校验
bool validQueue(BTQueue *queue) {
  return queue != NULL ? true : false;
}// validQueue

// 初始化队列
bool InitLQueue(BTQueue *queue) {
    if (!validQueue(queue)) {
        return false;
    }

    queue->rear = (BTQueueNode*)malloc(sizeof(BTQueueNode));
    queue->front = queue->rear;
    queue->front->next = NULL;

    return true;
}// InitLQueue

// 判空队列
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

// 入队
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

// 出队(特别注意只有一个节点的情况)
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
    // 如果原队列只有一个节点，则 rear = front
    if (queue->rear == DelNode) {
        queue->rear = queue->front;
    }
    free(DelNode);

    return true;
}// DelQueue
