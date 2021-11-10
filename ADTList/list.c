#include "list.h"
#include <stdlib.h>
#include "fatal.h"

/* Place in the interface file */
struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L)
{
    if (L != NULL)
        DeleteList(L);
    L = malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("Out of memory!");
    L->Next = NULL;
    return L;
}

/* START: fig3_8.txt */
/* Return true if L is empty */

int IsEmpty(List L)
{
    return L->Next == NULL;
}
/* END */

/* START: fig3_9.txt */
/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}
/* END */

/* START: fig3_10.txt */
/* Return Position of X in L; NULL if not found */

Position
Find(ElementType X, List L)
{
    Position P;

    /* 1*/ P = L->Next;
    /* 2*/ while (P != NULL && P->Element != X)
        /* 3*/ P = P->Next;

    /* 4*/ return P;
}
/* END */

/* START: fig3_11.txt */
/* Delete from a list */
/* Cell pointed to by P->Next is wiped out */
/* Assume that the position is legal */
/* Assume use of a header node */

void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L)) /* Assumption of header use */
    {                  /* X is found; delete it */
        TmpCell = P->Next;
        P->Next = TmpCell->Next; /* Bypass deleted cell */
        free(TmpCell);
    }
}
/* END */

/* START: fig3_12.txt */
/* If X is not found, then Next field of returned value is NULL */
/* Assumes a header */

Position
FindPrevious(ElementType X, List L)
{
    Position P;

    /* 1*/ P = L;
    /* 2*/ while (P->Next != NULL && P->Next->Element != X)
        /* 3*/ P = P->Next;

    /* 4*/ return P;
}
/* END */

/* START: fig3_13.txt */
/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    /* 1*/ TmpCell = malloc(sizeof(struct Node));
    /* 2*/ if (TmpCell == NULL)
        /* 3*/ FatalError("Out of space!!!");

    /* 4*/ TmpCell->Element = X;
    /* 5*/ TmpCell->Next = P->Next;
    /* 6*/ P->Next = TmpCell;
}
/* END */

#if 0
/* START: fig3_14.txt */
        /* Incorrect DeleteList algorithm */

        void
        DeleteList( List L )
        {
            Position P;

/* 1*/      P = L->Next;  /* Header assumed */
/* 2*/      L->Next = NULL;
/* 3*/      while( P != NULL )
            {
/* 4*/          free( P );
/* 5*/          P = P->Next;
            }
        }
/* END */
#endif

/* START: fig3_15.txt */
/* Correct DeleteList algorithm */

void DeleteList(List L)
{
    Position P, Tmp;

    /* 1*/ P = L->Next; /* Header assumed */
    /* 2*/ L->Next = NULL;
    /* 3*/ while (P != NULL)
    {
        /* 4*/ Tmp = P->Next;
        /* 5*/ free(P);
        /* 6*/ P = Tmp;
    }
}
/* END */

Position
Header(List L)
{
    return L;
}

Position
First(List L)
{
    return L->Next;
}

Position
Advance(Position P)
{
    return P->Next;
}

ElementType
Retrieve(Position P)
{
    return P->Element;
}

/*my functions*/
List getList()
{
    struct Node *headNode, *oneNode;
    int nodeCounts = 0;
    headNode = (struct Node *)malloc(sizeof(struct Node));
    oneNode = (struct Node *)malloc(sizeof(struct Node));
    headNode->Element = 0;
    headNode->Next = oneNode;
    printf("请输入要创建的结点数\n");
    scanf_s("%d", &nodeCounts);
    if (nodeCounts != 0)
    {
        for (int i = 0; i < nodeCounts; i++)
        {
            struct Node *nextNode;
            nextNode = (struct Node *)malloc(sizeof(struct Node));
            printf("请输入第%d个结点的值\n", i + 1);
            scanf_s("%d", &oneNode->Element);
            oneNode->Next = nextNode;
            if (i == (nodeCounts - 1))
            {
                oneNode->Next = NULL;
            }
            oneNode = nextNode;
        }
    }
    else
    {
        headNode->Next = NULL;
    }
    return (headNode);
}

void showList(struct Node *p)
{
    if (!IsEmpty(p))
    {
        p = p->Next;
    }
    printf("现在的链表如下：");
    for (;;)
    {
        if (!(p->Next))
        {
            printf("%d\n", p->Element);
            break;
        }
        printf("%d -> ", p->Element);
        p = p->Next;
    }
}
void getElement(int m, struct Node *p)
{
    p = p->Next;
    for (int i = 1; i < m; i++)
    {
        p = p->Next;
    }
    printf("第%d个结点处的值为：%d\n", m, p->Element);
}
void deleteElement(int m, struct Node *p)
{
    for (int i = 1; i < m; i++)
    {
        p = p->Next;
    }
    p->Next = (p->Next)->Next;
}
void insertElement(int position, int value, struct Node *p)
{
    struct Node *oneNode;
    oneNode = (struct Node *)malloc(sizeof(struct Node));
    oneNode->Element = value;
    for (int i = 0; i < position; i++)
    {
        p = p->Next;
    }
    oneNode->Next = p->Next;
    p->Next = oneNode;
}
