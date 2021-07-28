#include <stdio.h>
#include <malloc.h>
typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BiTree;

// 二叉排序树查找算法
BSTNode *BST_Search(BiTree T, int key) {
    while (T != NULL && key != T->key) { // 若树空或等于根节点值，则结束循环
        if (key < T->key) // 小于，在左子树查找
            T = T->lchild;
        else T = T->rchild; // 大于，在右子树查找
    }
}

// 二叉排序树插入
int BST_Insert(BiTree &T, int k) {
    if (T == NULL) { // 原树空，新插入的记录为根节点
        T = (BiTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if (k == T->key) // 树中存在相同关键字的结点，插入失败
        return 0;
    else if (k < T->key) // 插入到T的左子树
        return BST_Insert(T->lchild, k);
    else // 插入到T的右子树
        return BST_Insert(T->rchild, k);
}

// 二叉排序树的构造
void Create_BST(BiTree &T, int str[], int n) {
    T = NULL; // 初始时T为空树
    int i = 0;
    while (i < n) { // 依次将每个关键字插入到二叉排序树中
        BST_Insert(T, str[i]);
        i++;
    }   
}
