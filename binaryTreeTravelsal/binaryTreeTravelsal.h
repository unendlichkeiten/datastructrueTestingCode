#ifndef BINARYTREETRAVELSAL_H_INCLUDED
#define BINARYTREETRAVELSAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./stack/BTStack.h"
#include "./queue/BTQueue.h"

typedef int TElemType;
typedef struct BiTNode  *BiTree;
typedef struct BiTNode  *BiTNode;
struct BiTNode{
    TElemType data;  // 节点值
    BiTNode lchild;  // 左子树
    BiTNode rchild;  // 右子树
};

// 访问节点
void Visit(BiTNode btNode);
// 构造二叉树
BiTree createBiTree();
// 前序遍历
void PreOrder(BiTree bt);
// 中序遍历
void InOrder(BiTree bt);
// 后序遍历
void PostOrder(BiTree bt);
// 层序遍历
void LevelOrder(BiTree bt);

#endif // BINARYTREETRAVELSAL_H_INCLUDED
