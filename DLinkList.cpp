#include <iostream>

using namespace std;

typedef struct DLNode {
    int data;
    DLNode* prev;
    DLNode* next;
}* DLinkList;

DLNode* GetElem(DLinkList L, int i)
{
    DLNode* p = L;
    int j = 0;
    while (j < i && p != nullptr) {
        p = p->next;
        j++;
    }
    return p;
}

bool ListInsert(DLinkList& L, int i, int e)
{
    if (i < 1)
        return false;

    DLNode* p = GetElem(L, i - 1);
    DLNode* s = new DLNode;
    s->data = e;
    s->next = p->next;
    s->prev = p;
    p->next->prev = s;
    p->next = s;
    return true;
}

bool ListDelete(DLinkList& L, int i, int& e)
{
    DLNode* p = GetElem(L, i);
    if (p == nullptr)
        return false;

    p->next->prev = p->prev;
    p->prev->next = p->next;
    delete p;
    return true;
}