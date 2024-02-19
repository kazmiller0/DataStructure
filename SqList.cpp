#include <iostream>
#define MaxSize 50
#define InitSize 10

using namespace std;

struct SqList {
    int data[MaxSize];
    int length;
};

struct SeqList {
    int* data;
    int length;
    int maxSize;
};

void InitList(SqList& L)
{
    for (int i = 0; i < L.length; i++)
        L.data[i] = 0;

    L.length = 0;
}

void InitList(SeqList& L)
{
    L.data = new int[InitSize];
    L.length = 0;
    L.maxSize = InitSize;
}

void IncreaseSize(SeqList& L, int len)
{
    int* p = L.data;
    L.data = new int[MaxSize + len];

    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i];

    L.maxSize += len;
    delete[] p;
}

//  插入线性表 i 位置相当于插入到数组的 i-1 位置
//  插入位置可以是 1 到 length + 1
bool ListInsert(SqList& L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;

    if (L.length >= MaxSize)
        return false;

    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];

    L.data[i - 1] = e;
    L.length++;

    return true;
}

bool ListDelete(SqList& L, int i, int& e)
{
    if (i < 1 || i > L.length)
        return false;

    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];

    L.length--;

    return true;
}

int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i;
    }
    return -1;
}

int GetElem(SqList L, int i) { return L.data[i - 1]; }

bool DeleteMin(SqList& L, int& e)
{
    if (L.length == 0)
        return false;

    e = L.data[0];
    for (int i = 1; i < L.length; i++) {
        if (L.data[i] < e) {
            e = L.data[i];
            L.data[i] = L.data[L.length - 1];
        }
    }
    L.length--;
    return true;
}

void Reverse(SqList& L)
{
    int temp = 0;
    for (int i = 0; i < L.length / 2; ++i) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

void DeleteX(SqList& L, int x)
{
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

//  删除值为 s 到 t 的元素
bool DeleteS2T(SqList& L, int s, int t)
{
    if (s >= t)
        return false;

    if (L.length == 0)
        return false;

    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] < s || L.data[i] > t) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;   
    return true;
}

//  删除重复的元素
bool DeleteDuplicate(SqList& L)
{
}
