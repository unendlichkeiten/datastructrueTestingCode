#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} *LinkStack;

// ÅÐ¶Ï¿ÕÕ»
bool EmptyStack(LinkStack linkStack)
{
    return linkStack->next == NULL ? true : false;
}

// ÅÐ¶ÏÂúÕ»£¨Á´Ê½½á¹¹ÂÔ£©

// ÈëÕ»
bool PushStack(LinkStack linkStack, ElemType data)
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

// ³öÕ»
bool PopStack(LinkStack linkStack, ElemType *data)
{
    if (linkStack == NULL || linkStack->next == NULL)
    {
        return false;
    }

    struct LinkNode *tmpNode = linkStack->next;
    *data = tmpNode->data;
    linkStack->next = tmpNode->next;

    return true;
}

int main()
{
    LinkStack stack = (LinkStack)malloc(sizeof(struct LinkNode));
    stack->next = NULL;

    int i = 0;
    bool result = false;

    for (i = 0; i < 10; i++)
    {
        result = PushStack(stack, i*i);
        if (result == false)
        {
            printf("push stack error %d\n", i);
            continue;
        }
    }

    LinkStack tmpNode = stack->next;
    while(tmpNode != NULL)
    {
        printf("data is %d \n", tmpNode->data);
        tmpNode = tmpNode->next;
    }

    ElemType data = 0X7FFFFFFF;
    for (i = 0; i < 11; i++)
    {
        result = PopStack(stack, &data);
        if (result == false)
        {
            printf("pop %d failed \n", i);
            continue;
        }
        printf("data %d value is %d \n", i, data);
    }

    return 0;
}
