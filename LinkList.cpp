#include <iostream>

using namespace std;

typedef struct LNode
{
    int data;
    LNode *next;
} *LinkList; // typedef LNode *LinkList, LinkList 是指向 LNode 的指针

bool InitList(LinkList &L)
{
    L = new LNode;
    L->next = nullptr;
    return true;
}

bool InitListNoSentinel(LinkList &L)
{
    L = nullptr;
    return true;
}

bool Empty(LinkList L)
{
    return L->next == nullptr;
}

int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != nullptr)
    {
        //      跳过哨兵节点
        p = p->next;
        len++;
    }
    return len;
}

LNode *GetElem(LinkList L, int i)
{
    LNode *p = L;
    int j = 0;
    while (j < i && p != nullptr)
    {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L;
    while (p != nullptr && p->data != e)
    {
        p = p->next;
    }
    return p;
}

bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    LNode *p = GetElem(L, i - 1);
    if (p == nullptr)
        return false;

    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsertNoSentinel(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    if (i == 1)
    {
        LNode *s = new LNode;
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }

    LNode *p = GetElem(L, i - 1);
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertNextNode(LNode *p, int e)
{
    if (p == nullptr)
        return false;

    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList &L, int i, int &e)
{
    LNode *p = GetElem(L, i - 1);
    if (p == nullptr || p->next == nullptr)
        return false;

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    delete p;
    return true;
}

void ListDeleteX(LinkList &L, int x)
{
    LNode *p = L;
    LNode *q = p->next;
    while (q != nullptr)
    {
        if (q->data == x)
        {
            LNode *t = q;
            q = q->next;
            p->next = q;
            delete t;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
}

void ListDeleteMin(LinkList &L)
{
    LNode *min = L->next;
    LNode *minPrev = L;
    LNode *p = L;
    LNode *q = L->next;
    while (q != nullptr)
    {
        if (q->data < min->data)
        {
            min = q;
            minPrev = p;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    minPrev->next = min->next;
    delete (min);
}

void Reverse(LinkList &L)
{
    LNode *prev = nullptr;
    LNode *curr = L->next;
    LNode *next = L->next->next;

    while (next != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    L->next = curr;
}

LinkList TailInsert(LinkList &L)
{
    int x;
    L = new LNode;
    LNode *r = L;
    LNode *s = nullptr;
    cin >> x;
    while (x != 9999)
    {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = nullptr;
    return L;
}

int main()
{
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 1, 2);
    ListInsert(L, 1, 3);
    ListInsert(L, 1, 4);
    ListInsert(L, 1, 5);
    Reverse(L);
}
