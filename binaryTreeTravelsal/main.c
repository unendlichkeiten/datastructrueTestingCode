#include "binaryTreeTravelsal.h"

int main(int argc, char **argv) {
  BiTree bt;
  
  // 创建二叉树
  bt = createBiTree();
  // 先序遍历
  PreOrder(bt);
  // 中序遍历
  InOrder(bt);
  // 后序遍历
  PostOrder(bt);
  // 层序遍历
  LevelOrder(bt);

  return 0;
}