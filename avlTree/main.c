#include "avlTree.h"

int main(int argc, char* argv[]) {
  AVLTree T = NULL;

  for (int i = 0; i < 15; i++) {
    T = Insert(T, i);
  }

  preOrder(T);

  return 0;
}

void preOrder(AVLTree T) {
  if (NULL != T) {
    printf("data is %d\n", T->Data);
    preOrder(T->Left);
    preOrder(T->Right);
  }
}
