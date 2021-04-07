#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include <stdio.h>

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL������ */
struct AVLNode{
    int Data; /* ������� */
    AVLTree Left;     /* ָ�������� */
    AVLTree Right;    /* ָ�������� */
    int Height;       /* ���� */
};

#endif // AVLTREE_H_INCLUDED
