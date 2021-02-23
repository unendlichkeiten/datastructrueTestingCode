#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode {
  // Ϊ�˲������㣬ͷ�ڵ��data���ڼ�¼����ĳ���
  ElemType     data;
  struct LNode *next;
}LNode, *LinkList;

int main() {
}

bool CircularLinkedList(LinkList L) {

  if (!L || !L->next || !L->next->next) {
    return false;
  }

  LinkList slow = L->next;
  LinkList fast = L->next;
  while (slow != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }

  return false;
}



