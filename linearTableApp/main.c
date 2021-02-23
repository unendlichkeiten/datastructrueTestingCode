#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 20
typedef int ElemType;
typedef struct {
  ElemType data[MAXSIZE];
  int      len;
}SqList;

bool ShiftLeft(SqList *SQ, int left, int right);

int main()
{
  int i = 0, length = 0;
  int shiftLength = 0;
  bool result = false;
  SqList Sq;

  printf("please input shift length : ");
  scanf("%d", &shiftLength);
  printf("\n");

  // init Sq
  printf("sqList element value : ");
  for (i = 0; i < MAXSIZE; ) {
    Sq.data[i] = i;
    printf("%d ", Sq.data[i]);
    Sq.len = ++i;
  }
  printf("\n");

  // shift table
  result = ShiftLeft(&Sq, 0, Sq.len-1);
  if (result == false) {
    printf("[%s][%d][%s]:shifleft failed \n", __FILE__, __LINE__,__func__);
  }

  result = ShiftLeft(&Sq, Sq.len-shiftLength, Sq.len-1);
  if (result == false) {
    printf("[%s][%d][%s]:shifleft failed \n", __FILE__, __LINE__,__func__);
    return -1;
  }

  result = ShiftLeft(&Sq, 0, Sq.len-shiftLength-1);
  if (result == false) {
    printf("[%s][%d][%s]:shifleft failed \n", __FILE__, __LINE__,__func__);
    return -1;
  }

  for (i = 0; i < MAXSIZE; i++ ) {
    printf("%d ", Sq.data[i]);
  }
  printf("\n");
}

bool ShiftLeft(SqList *SQ, int left, int right) {
  int tmpData = 0;
  if (left > right || left < 0 || right > SQ->len-1) {
    printf("left %d or right %d invalid \n", left, right);
    return false;
  }
  // reverse table
  while (left < right) {
    tmpData = SQ->data[left];
    SQ->data[left] = SQ->data[right];
    SQ->data[right] = tmpData;

    left++;
    right--;
  }
  return true;
}
