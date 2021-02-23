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
    TElemType data;  // �ڵ�ֵ
    BiTNode lchild;  // ������
    BiTNode rchild;  // ������
};

// ���ʽڵ�
void Visit(BiTNode btNode);
// ���������
BiTree createBiTree();
// ǰ�����
void PreOrder(BiTree bt);
// �������
void InOrder(BiTree bt);
// �������
void PostOrder(BiTree bt);
// �������
void LevelOrder(BiTree bt);

#endif // BINARYTREETRAVELSAL_H_INCLUDED
