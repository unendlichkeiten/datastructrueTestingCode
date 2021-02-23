#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_SIZE 100
#define INCREMENT 20
typedef int ElemType;
typedef struct {
	ElemType *data;
	int      len; // 顺序表长
	int      cap; // 顺序表最大容量
}SqList;

bool init_sq_2(SqList *sq);
bool insert_sq_2(SqList *sq, int pos, ElemType data);
bool update_sq_2(SqList *sq, int pos, ElemType value);
bool delete_sq_2(SqList *sq, int pos, ElemType *value);
int main()
{
    SqList SQ;
    ElemType value;
    bool result = false;

    result = init_sq_2(&SQ);
    if (NULL == result) {
      printf("init_sq_2 failed\n");
    }
    printf("sq len %d, sq cap %d\n", SQ.len, SQ.cap);

    int i = 0;
    for (i = 0; i <= INIT_SIZE; i++) {
      result = insert_sq_2(&SQ, i, i+1);
      if (result == false) {
        printf("insert_sq_2 failed %d\n", i);
        continue;
      }
      printf("insert_sq_2 sq data %d, sq len %d\n", SQ.data[i], SQ.len);
    }
    printf("sq len %d, sq cap %d\n", SQ.len, SQ.cap);

    for (i = 0; i < INCREMENT; i++) {
      result = update_sq_2(&SQ, i, i*i);
      if (result == false) {
        printf("update_sq_2 failed %d\n", i);
        continue;
      }
      printf("update_sq_2 data %d\n", SQ.data[i]);
    }

    // 删除指定元素
    result = delete_sq_2(&SQ, 0, &value);
    if (result == NULL) {
      printf("delete_sq_2 failed");
      return -1;
    }
    printf("delete_sq_2 len %d", SQ.len);
    return 0;
}

bool init_sq_2(SqList *sq) {
    if (NULL == sq) {
        return false;
    }
    sq->data = (ElemType*)malloc(sizeof(ElemType)*INIT_SIZE);
    if (NULL == sq->data) {
        return false;
    }
    sq->len = 0;
    sq->cap = INIT_SIZE;
    return true;
} // init_sq_2
bool insert_sq_2(SqList *sq, int pos, ElemType data) {
    // 判断顺序表是否为空，pos是否合法
    if (NULL == sq || pos < 0 || pos > sq->len) {
        return false;
    }
    // 当前动态数组已经满了，插入新元素需要重新申请一块内存
    int i = 0;
    ElemType *newData = NULL, *tmpData = NULL;
    if (sq->len == sq->cap) {
      tmpData = (ElemType*)malloc(sizeof(ElemType)*(sq->cap+INCREMENT));
      if (tmpData == NULL) {
        return false;
      }

      newData = tmpData;
      for (i = 0; i < sq->len; i++) {
        *tmpData++ = sq->data[i];
      }
      free(sq->data);
      sq->data = newData;
      sq->cap += INCREMENT;
    }

    // 插入新元素到中间位置
    for (i = sq->len; i > pos; i--) {
      sq->data[i] = sq->data[i-1];
    }
    sq->data[pos] = data;
    sq->len++;

    return true;
} // insert_sq_2
bool update_sq_2(SqList *sq, int pos, ElemType value) {
    // 判断顺序表是否为空，pos是否合法
    if (NULL == sq || pos < 0 || pos >= sq->len) {
        return false;
    }
    sq->data[pos] = value;
    return true;
} // update_sq_2
bool delete_sq_2(SqList *sq, int pos, ElemType *value) {
    // 判断顺序表是否为空，pos是否合法
    if (NULL == sq || pos < 0 || pos >= sq->len) {
        return false;
    }

    int i = pos;
    *value = sq->data[pos];
    for (i = pos; i < sq->len; i++) {
      sq->data[i] = sq->data[i+1];
    }
    sq->len--;

    return true;
}
