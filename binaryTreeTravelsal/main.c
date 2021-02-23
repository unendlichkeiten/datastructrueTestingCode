#include "binaryTreeTravelsal.h"

int main(int argc, char **argv) {
  BiTree bt;

  // 创建二叉树
  if (!(bt = createBiTree())) {
    printf("create binary tree failed.\n");
    return -1;
  }
  // 先序遍历
  printf("preOrder beginning.\n");
  PreOrder(bt);
  // 中序遍历
  printf("InOorder beginning.\n");
  InOrder(bt);
  // 后序遍历
  printf("PostOrder beginning.\n");
  PostOrder(bt);
  // 层序遍历
  LevelOrder(bt);

  return 0;
}
