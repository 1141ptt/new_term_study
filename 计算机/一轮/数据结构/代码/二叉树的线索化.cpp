#include <stdio.h>
struct ElemType {
	int value;
}; 
typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 左、右线索标志
}ThreadNode, *ThreadTree;

// 指向当前访问结点的前驱
ThreadNode *pre = NULL;

// 中序遍历二叉树。一边遍历一边线索化
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}
void visit(ThreadNode *q) {
    if (q->lchild == NULL) { // 左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}
// 中序线索化二叉树T
void CreateInThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) { // 非空二叉树才能线索化
        InThread(T); // 中序线索化二叉树
        if (pre->rchild == NULL) {
            pre->rtag = 1; // 处理遍历的最后一个结点
        }
    }
}

// 先序遍历二叉树，一边遍历一边线索化
void PreThread(ThreadTree T) {
    if (T != NULL) {
        visit(T); // 先处理根节点
        if (T->ltag == 0) // lchild不是前驱线索
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}
void visit(ThreadNode *q) {
    if (q->lchild == NULL) { // 左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}
// 先序线索化二叉树T
void CreatePreThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) { // 非空二叉树才能线索化
        PreThread(T); // 先序线索化二叉树
        if (pre->rchild == NULL) {
            pre->rtag = 1; // 处理遍历的最后一个结点
        }
    }
}

// 后序遍历二叉树，一边遍历一边线索化
void PostThread(ThreadTree T) {
    if (T != NULL) {
        PreThread(T->lchild); // 后序遍历左子树
        PreThread(T->rchild); // 后序遍历右子树
        visit(T); // 访问根节点
    }
}
void visit(ThreadNode *q) {
    if (q->lchild == NULL) { // 左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}
// 后序线索化二叉树T
void CreatePostThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) { // 非空二叉树才能线索化
        PostThread(T); // 后序线索化二叉树
        if (pre->rchild == NULL) {
            pre->rtag = 1; // 处理遍历的最后一个结点
        }
    }
}
