#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include <stdio.h>

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL树类型 */
struct AVLNode{
    int Data; /* 结点数据 */
    AVLTree Left;     /* 指向左子树 */
    AVLTree Right;    /* 指向右子树 */
    int Height;       /* 树高 */
};

#endif // AVLTREE_H_INCLUDED
