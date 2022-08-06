/* 3、设给定一组数据A，其数据元素为整型，用单链表存储，
请编写程序，将单链表A拆成B和C两个链表，使A值大于0的元素存入链表表B，
值小于0的元素存入链表C，要求表B和C不另外设置存储空间而利用表A的空间。
建议用函数实现。
 */
#include <stdio.h>

typedef int NodeType;

typedef struct _node
{
    NodeType data;
    struct _node *next;
} Linklist;

void display(Linklist *head)
{
    Linklist *p;
    for (p = head->next; p; p = p->next)
        printf("%d%c", p->data, (p->next ? ',' : 'n'));
}

// 记着一块就行。。。
void split(Linklist *a, Linklist *b, Linklist *c)
{
    Linklist *bp = b, *cp = c, *p;
    for (p = a->next; p; p = p->next)
    {
        if (p->data < 0)
        {
            bp->next = p;
            bp = p;
        }
        else if (p->data > 0)
        {
            cp->next = p;
            cp = p;
        }
    }
    bp->next = NULL;
    cp->next = NULL;
}

int main()
{
    Linklist *a = (Linklist *)malloc(sizeof(Linklist)),
             *b = (Linklist *)malloc(sizeof(Linklist)),
             *c = (Linklist *)malloc(sizeof(Linklist)),
             *ap = a;
    a->next = NULL;
    b->next = NULL;
    c->next = NULL;
    int i;
    for (i = 0; i < 50; i++)
    {
        int data = rand() % 100 - 50;
        Linklist *q = (Linklist *)malloc(sizeof(Linklist));
        q->data = data;
        q->next = NULL;
        ap->next = q;
        ap = q;
    }
    display(a);
    split(a, b, c);
    display(b);
    display(c);
    return 0;
}