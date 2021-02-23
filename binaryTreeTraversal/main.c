#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ¶þ²æÊ÷µÄÁ´Ê½´æ´¢
typedef int TElemType;
struct BiTNode{
    TElemType data;
    BiTNode lchild;  // ×ó×ÓÊ÷
    BiTNode rchild;  // ÓÒ×ÓÊ÷
};
typedef struct BiTNode  *BiTree;
typedef struct BiTNode  *BiTNode;


// ¶þ²æÅÅÐòÊ÷

int main()
{
  BiTree T = (BiTree)malloc(sizeof(struct BiTNode));
  T->lchild = T->rchild = NULL;
  printf("Hello world!\n");
  return 0;
}


