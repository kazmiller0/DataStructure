//
// Created by Krimson Hawk on 2024/2/19.
//

#include <iostream>
#define MaxSize 100

using namespace std;

struct ElemType {
    int value;
};

struct TreeNode {
    ElemType value;
    bool isEmpty;
};

typedef struct BiTNode {
    ElemType data;
    BiTNode* lchild;
    BiTNode* rchild;
    BiTNode* parent;
}* BiTree;

int main()
{
    TreeNode t[MaxSize];
    for (TreeNode& i : t) {
        i.isEmpty = true;
    }

    BiTree root = new BiTNode;
    root->data = { 1 };
    root->lchild = nullptr;
    root->rchild = nullptr;

    BiTNode* p = new BiTNode;
    p->data = { 2 };
    p->lchild = nullptr;
    p->rchild = nullptr;
    root->lchild = p;
}
