#include "binaryTreeTravelsal.h"

#define NONE  0
#define LEFT  -1
#define RIGHT 1

// ���ʽڵ�
void Visit(BiTNode btNode) {
    printf("btNode value is: %d", btNode->data);
}// Visit

// ���������
BiTree createBiTree(){
  TElemType data;
  BiTree bt, t;
  BTQueue queue;

  // ��ʼ������
  if (!InitLQueue(&queue)) {
    printf("init queue failed.\n");
    return NULL;
  }

  // �������ڵ�
  scanf("%d", &data);
  if (data == NONE) {
    return NULL;
  }
  if (!(bt = (struct BiTNode*)malloc(sizeof(struct BiTNode)))) {
    printf("malloc root nodes failed.\n");
    return NULL;
  }
  bt->data = data;
  bt->lchild = bt->rchild = NULL;

  // �����ڵ�������
  if (!EnLQueue(&queue, bt)) {
    printf("enqueue failed.\n");
    return NULL;
  }

  while(!IsEmptyLQueue(&queue)) {
    if (!DelQueue(&queue, &t)) {
      printf("delQueue failed.\n");
      continue;
    }

    // �������ӽڵ�
    scanf("%d", &data);
    if (data == NONE) {
      t->lchild = NULL;
    } else {
      t->lchild = (BiTNode)malloc(sizeof(struct BiTNode));
      t->lchild->data = data;
      t->lchild->lchild = t->lchild->rchild = NULL;
      if (!EnLQueue(&queue, t->lchild)) {
        printf("enqueue lchild failed.\n");
        continue;
      }
      EnLQueue(&queue, t);
    }

    //�������ӽڵ�
    scanf("%d", &data);
    if (data == NONE) {
      t->rchild = NULL;
    } else {
      t->rchild = (BiTNode)malloc(sizeof(struct BiTNode));
      t->rchild->data = data;
      t->rchild->lchild = t->rchild->rchild = NULL;
      if (!EnLQueue(&queue, t->rchild)) {
        printf("enqueue rchild failed.\n");
        continue;
      }
      EnLQueue(&queue, t);
    }
  }

  return bt;
}// createBiTree

// ǰ�����
void PreOrder(BiTree bt){
  BTStack btStack = CreateBTStack();
  InitStack(btStack);

  BiTNode btNode = bt;
  while (btNode || IsEmptyStack(btStack)) {
    if (btNode) {
      Visit(btNode);
      Push2Stack(btStack, btNode);
      btNode = btNode->lchild;
    } else {
      btNode = Pop4Stack(btStack, btNode);
      btNode = btNode->rchild;
    }
  }
}// PreOrder

// �������
void InOrder(BiTree bt){
  BTStack btStack = CreateBTStack();
  InitStack(btStack);

  BiTNode btNode = bt;
  while (btNode || IsEmptyStack(btStack)) {
    if (btNode) {
      Push2Stack(btStack, btNode);
      btNode = btNode->lchild;
    } else {
      btNode = Pop4Stack(btStack, btNode);
      Visit(btNode);
      btNode = btNode->rchild;
    }
  }
}// InOrder

// �������
void PostOrder(BiTree bt){
  BTStack btStack = CreateBTStack();
  InitStack(btStack);

  BiTNode btNode = bt, pre = NULL;
  while (btNode || IsEmptyStack(btStack)) {
    if (btNode) {
      Push2Stack(btStack, btNode);
      btNode = btNode->lchild;
    } else {
      btNode = GetTopElem(btStack, btNode);
      if (!btNode->rchild || btNode->rchild == pre) {
        Pop4Stack(btStack, btNode);
        Visit(btNode);
        pre = btNode;
        btNode = NULL;
      } else {
        btNode = btNode->rchild;
        Push2Stack(btStack, btNode);
        btNode = btNode->lchild;
      }
    }
  }
}// PostOrder

// �������
void LevelOrder(BiTree bt){
  BiTNode root = bt, btNode = NULL;
  BTQueue queue;
  InitLQueue(&queue);

  if (root == NULL) {
    return ;
  }
  EnLQueue(&queue, root);

  while (IsEmptyLQueue(&queue)) {
    DelQueue(&queue, &btNode);
    Visit(btNode);
    if (btNode->lchild) {
      EnLQueue(&queue, btNode->lchild);
    }
    if (btNode->rchild) {
      EnLQueue(&queue, btNode->rchild);
    }
  }
}// LevelOrder
