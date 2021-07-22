#include <stdio.h>
#include <malloc.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
struct ElemType {
    int value;
};
// 链式队列结点
typedef struct LinkNode {
    BiTNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

// 链式队列基本操作
void InitQueue(LinkQueue Q) {
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)  return true;
    else return false;
}
void EnQueue(LinkQueue &Q, BiTree x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}
bool DeQueue(LinkQueue &Q, BiTree &x) {
    if (Q.front == Q.rear)  return false;
    LinkNode *p = Q.front->next;
    x=p->data;
    Q.front->next = p->next;
    if (Q.rear = p) Q.rear = Q.front;
    free(p);
    return true;
}
void visit(BiTree p) {}
// 层序遍历
void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != NULL) {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(Q,p ->rchild);
        }
    }
    
}
