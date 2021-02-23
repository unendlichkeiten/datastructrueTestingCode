#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LNode {
  // 为了操作方便，头节点的data用于记录链表的长度
  ElemType     data;
  struct LNode *next;
}LNode, *LinkList;

bool init_link_list(LinkList L);
bool insert_link_list(LinkList L, int pos, ElemType data);
bool update_link_list(LinkList L, int pos, ElemType data);
bool delete_link_list(LinkList L, int pos, ElemType *data);

int main()
{
  LinkList L;
  ElemType data;
  LNode *tmpNode = NULL;
  bool result;

  L = (LinkList)malloc(sizeof(LNode));
  if (NULL == L) {
    return -1;
  }

  // 初始化
  result = init_link_list(L);
  if (result == false) {
    printf("init_link_list failed \n");
    return -1;
  }

  // 插入操作
  int i = 0;
  for (i = 0; i < 10; i++) {
    result = insert_link_list(L, i, i+1);
    if (result == false) {
      printf("insert_link_list %d failed \n", i);
      continue;
    }
  }

  tmpNode = L->next;
  for (i = 0; i < 10; i++) {
    printf("linkList data %d \n", tmpNode->data);
    tmpNode = tmpNode->next;
  }

  // 更新操作
  for(i = 0; i < 11; i++) {
    result = update_link_list(L, i, i*i);
    if (result == false) {
      printf("update_link_list failed %d\n", i);
      continue;
    }
  }
  tmpNode = L->next;
  for (i = 0; i < 10; i++) {
    printf("linkList data %d \n", tmpNode->data);
    tmpNode = tmpNode->next;
  }
  printf("linkList len %d \n", L->data);

  // 删除操作
  for (i = 0; i < 10; i++) {
    result = delete_link_list(L, i, &data);
    if (result == false) {
      printf("delete_link_list node %d failed \n", i);
      continue;
    }
    printf("delete_link_list data %d\n",data);
  }
  printf("link_list length %d\n",L->data);

  return 0;
}

bool init_link_list(LinkList L) {
  if (NULL == L) {
    return false;
  }
  L->data = 0;
  L->next = NULL;
  return true;
} // init_link_list
bool insert_link_list(LinkList L, int pos, ElemType data) {
  // 判断链表是否为空，pos是否合法
  if (L == NULL || pos < 0 || pos > L->data) {
    return false;
  }

  int i = 0;
  LNode *tmpNode = L->next;
  LNode *newNode = NULL, *prior = L;
  // 创建新节点
  newNode = (LNode*)malloc(sizeof(LNode));
  if (newNode == NULL) {
    return false;
  }
  newNode->data = data;
  newNode->next = NULL;
  // 确定插入节点位置
  while (i++ < pos && tmpNode != NULL) {
    prior = tmpNode;
    tmpNode = tmpNode->next;
  }
  prior->next = newNode;
  newNode->next = tmpNode;
  L->data ++ ;

  return true;
}
bool update_link_list(LinkList L, int pos, ElemType data) {
  // 判断链表是否为空，pos是否合法
  if (L == NULL || pos < 0 || pos >= L->data) {
    return false;
  }

  int i = 0;
  LNode *tmpNode = L->next;
  while (i++ < pos) {
    tmpNode = tmpNode->next;
  }
  tmpNode->data = data;

  return true;
}
bool delete_link_list(LinkList L, int pos, ElemType *data) {
  // 判断链表是否为空，pos是否合法
  if (L == NULL || pos < 0 || pos >= L->data) {
    return false;
  }

  int i = 0;
  LNode *tmpNode = L->next;
  LNode *prior = L;
  while (i++ < pos && tmpNode != NULL) {
    prior = tmpNode;
    tmpNode = tmpNode->next;
  }

  *data = tmpNode->data;
  prior->next = tmpNode->next;
  free(tmpNode);
  L->data--;
  return true;
}
