#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����������ʽ�洢
typedef int TElemType;
struct BiTNode{
    TElemType data;
    BiTNode lchild;  // ������
    BiTNode rchild;  // ������
};
typedef struct BiTNode  *BiTree;
typedef struct BiTNode  *BiTNode;


// ����������

int main()
{
  BiTree T = (BiTree)malloc(sizeof(struct BiTNode));
  T->lchild = T->rchild = NULL;
  printf("Hello world!\n");
  return 0;
}


