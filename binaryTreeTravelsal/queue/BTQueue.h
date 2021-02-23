#ifndef BTQUEUE_H_INCLUDED
#define BTQUEUE_H_INCLUDED

#include "../binaryTreeTravelsal.h"

typedef struct BTQueueNode{
    struct BiTNode *data;
    struct BTQueueNode *next;
} BTQueueNode, *Position;

typedef struct {
  Position front;
  Position rear;
} BTQueue;

// 队列校验
bool validQueue(BTQueue *queue);
// 队列初始化
bool InitLQueue(BTQueue *queue);
// 判空队列
bool IsEmptyLQueue(BTQueue *queue);
// 入队
bool EnLQueue(BTQueue *queue, struct BiTNode *btNode);
// 出队
bool DelQueue(BTQueue *queue, struct BiTNode **btNode);

#endif // BTQUEUE_H_INCLUDED
