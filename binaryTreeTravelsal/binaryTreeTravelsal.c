#include "binaryTreeTravelsal.h"

#define NONE  0
#define LEFT  -1
#define RIGHT 1

// 访问节点
void Visit(struct BiTNode *btNode) {
    printf("btNode value is: %d\n", btNode->data);
}// Visit

// 构造二叉树
BiTree createBiTree(){
  TElemType data;
  BiTree bt, t;
  BTQueue queue;

  // 初始化队列
  if (!InitLQueue(&queue)) {
    printf("init queue failed.\n");
    return NULL;
  }

  // 创建根节点
  printf("please input rootNode value : ");
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

  // 将根节点插入队列
  if (!EnLQueue(&queue, bt)) {
    printf("enqueue failed.\n");
    return NULL;
  }

  while(!IsEmptyLQueue(&queue)) {
  if (!DelQueue(&queue, &t)) {
    printf("delQueue failed.\n");
    continue;
  }

  // 插入左子节点
  printf("please input subNode value : ");
  scanf("%d", &data);
  if (data == NONE) {
    t->lchild = NULL;
  } else {
    t->lchild = (struct BiTNode *)malloc(sizeof(struct BiTNode));
    t->lchild->data = data;
    t->lchild->lchild = t->lchild->rchild = NULL;
    if (!EnLQueue(&queue, t->lchild)) {
      printf("enqueue lchild failed.\n");
      continue;
    }
  }

  //插入右子节点
  printf("please input subNode value : ");
  scanf("%d", &data);
  if (data == NONE) {
    t->rchild = NULL;
  } else {
    t->rchild = (struct BiTNode *)malloc(sizeof(struct BiTNode));
    t->rchild->data = data;
    t->rchild->lchild = t->rchild->rchild = NULL;
    if (!EnLQueue(&queue, t->rchild)) {
      printf("enqueue rchild failed.\n");
      continue;
    }
  }
}

  return bt;
}// createBiTree

// 前序遍历
void PreOrder(BiTree bt){
  BTStack btStack = CreateBTStack();
  InitStack(btStack);

  struct BiTNode *btNode = bt;
  while (btNode || !IsEmptyStack(btStack)) {
    if (btNode) {
      Visit(btNode);
      Push2Stack(btStack, btNode);
      btNode = btNode->lchild;
    } else {
      Pop4Stack(btStack, &btNode);
      btNode = btNode->rchild;
    }
  }
}// PreOrder

// 中序遍历
void InOrder(BiTree bt){
  BTStack btStack = CreateBTStack();
  InitStack(btStack);

  struct BiTNode *btNode = bt;
  while (btNode || !IsEmptyStack(btStack)) {
    if (btNode) {
      Push2Stack(btStack, btNode);
      btNode = btNode->lchild;
    } else {
      Pop4Stack(btStack, &btNode);
      Visit(btNode);
      btNode = btNode->rchild;
    }
  }
}// InOrder

// 后序遍历
void PostOrder(BiTree bt){
  BTStack btStack = CreateBTStack();
  InitStack(btStack);

  struct BiTNode *btNode = bt, *pre = NULL;
  while (btNode || !IsEmptyStack(btStack)) {
    if (btNode) {
      Push2Stack(btStack, btNode);
      btNode = btNode->lchild;
    } else {
      GetTopElem(btStack, &btNode);
      if (!btNode->rchild || btNode->rchild == pre) {
        Pop4Stack(btStack, &btNode);
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

// 层序遍历
void LevelOrder(BiTree bt){
  struct BiTNode *root = bt, *btNode = NULL;
  BTQueue queue;
  InitLQueue(&queue);

  if (root == NULL) {
    return ;
  }
  EnLQueue(&queue, root);

  while (!IsEmptyLQueue(&queue)) {
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
