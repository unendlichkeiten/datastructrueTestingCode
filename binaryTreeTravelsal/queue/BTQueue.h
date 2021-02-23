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

// ����У��
bool validQueue(BTQueue *queue);
// ���г�ʼ��
bool InitLQueue(BTQueue *queue);
// �пն���
bool IsEmptyLQueue(BTQueue *queue);
// ���
bool EnLQueue(BTQueue *queue, struct BiTNode *btNode);
// ����
bool DelQueue(BTQueue *queue, struct BiTNode **btNode);

#endif // BTQUEUE_H_INCLUDED
