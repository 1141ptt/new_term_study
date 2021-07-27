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

// 中序线索二叉树找中序后继
// 找到以P为根的子树中第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p) {
    // 循环找到最左下结点
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
// 在中序线索二叉树中找到结点p的后继节点
ThreadNode *Nextnode(ThreadNode *p) {
    // 右子树最左下节点
    if (p->rtag == 0)
        return Firstnode(p->rchild);
    else return p->rchild; // rtag==1直接返回后继线索
}
// 对中序线索二叉树进行中序遍历
void Inorder(ThreadNode *T) {
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
        visit(p);
}

// 中序线索二叉树找中序前驱
// 找到以P为根的子树中最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p) {
    // 循环找到最右下结点
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}
// 在中序线索二叉树中找到结点p的前驱节点
ThreadNode *Prenode(ThreadNode *p) {
    // 右子树最右下节点
    if (p->ltag == 0)
        return Lastnode(p->lchild);
    else return p->lchild; // ltag==1直接返回前驱线索
}
// 对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode *T) {
    for (ThreadNode *p = Lastnode(T); p != NULL; p = Prenode(p))
        visit(p);
}
