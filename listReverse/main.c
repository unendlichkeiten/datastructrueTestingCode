#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} *LinkList;

bool ReverseLinkList(LinkList Sq)
{
    // 异常处理
    if (Sq == NULL)
    {
        return false;
    }

    LinkList tmpSq = Sq->next;
    LinkList tmpNode = NULL;
    LinkList tmpList = (LinkList)malloc(sizeof(struct LinkNode));
    if (tmpList == NULL)
    {
        return false;
    }
    tmpList->next = NULL;

    while (tmpSq != NULL)
    {
        tmpNode = tmpSq;
        tmpSq = tmpSq->next;

        // 头插法插入新链表中
        tmpNode->next = tmpList->next;
        tmpList->next = tmpNode;
    }

    Sq->next = tmpList->next;
    free(tmpList);

    return true;
}

bool ReverseLinkList2(LinkList Sq)
{
    if (Sq == NULL)
    {
        return false;
    }

    LinkList newList = NULL;
    LinkList curNode = Sq->next;
    LinkList tmpNode = NULL;

    while ( curNode != NULL )
    {
        tmpNode = curNode;
        curNode = curNode->next;
        tmpNode->next = newList;
        newList = tmpNode;
    }

    Sq->next = newList;
    return true;
}

bool PushStack(LinkList linkStack, ElemType data)
{
    if (linkStack == NULL)
    {
        return false;
    }
    struct LinkNode *newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
    if (newNode == NULL)
    {
        return false;
    }
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = linkStack->next;
    linkStack->next = newNode;

    return true;
}

LinkList reverse(LinkList Sq, LinkList *tail)
{
    LinkList reversedSq = Sq;

    if(Sq->next == NULL)
    {
        *tail = Sq;
    }
    else
    {
        reversedSq = reverse(Sq->next, tail);
        (*tail)->next = Sq;
        *tail = Sq;
    }

    return reversedSq;
}

bool ReverseLinkList3(LinkList Sq)
{
    if (Sq == NULL)
    {
        return false;
    }

    LinkList *tail = (LinkList*)malloc(sizeof(LinkList*));
    Sq->next = reverse(Sq->next, tail);
    (*tail)->next = NULL;

    return true;
}

int main()
{
    LinkList SqList = (LinkList)malloc(sizeof(struct LinkNode));
    if (SqList == NULL)
    {
        printf("malloc error \n");
        return -1;
    }
    SqList->next = NULL;

    int i = 0;
    bool result = false;
    for (i = 0; i < 10; i++)
    {
        result = PushStack(SqList, i*i);
        if (result == false)
        {
            printf("push error %d \n", i);
            continue;
        }
    }

    // travel list
    struct LinkNode *tmpNode = SqList->next;
    while(tmpNode != NULL)
    {
        printf("list value is %d \n", tmpNode->data);
        tmpNode = tmpNode->next;
    }

    result = ReverseLinkList3(SqList);
    if (result == false)
    {
        printf("reverse linkList error \n");
        return -1;
    }

    tmpNode = SqList->next;
    while(tmpNode)
    {
        printf("list value is %d \n", tmpNode->data);
        tmpNode = tmpNode->next;
    }
    return 0;
}
