#include <stdio.h>
#include <malloc.h>
#define MAX_VERTEX_NUM 100
bool visited[MAX_VERTEX_NUM]; // 标记访问数组
struct Graph {
    int vexnum;
};
// 链式队列结点
typedef struct LinkNode {
    int data;
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
void EnQueue(LinkQueue &Q, int x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}
bool isEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)  return true;
    else return false;
}
bool DeQueue(LinkQueue &Q, int x) {
    if (Q.front == Q.rear)  return false;
    LinkNode *p = Q.front->next;
    x=p->data;
    Q.front->next = p->next;
    if (Q.rear = p) Q.rear = Q.front;
    free(p);
    return true;
}
void visit(int v) {}
int FirstNeighbor(Graph G, int v) {}
int NextNeighbor(Graph G, int v, int w) {}
void BFSTraverse(Graph G) { // 对图G进行广度优先遍历
    for (int i = 0; i < G.vexnum; ++i) 
        visited[i] = false; // 访问标记数组初始化
    LinkQueue Q;
    InitQueue(Q); // 初始化辅助队列
    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i]) // 每一个连通分量调用一次BFS
            BFS(G, i); // vi未访问过，从vi开始BFS
    }
}
// 广度优先遍历
void BFS(Graph G, int v) { // 从顶点v出发，广度优先遍历G
    visit(v); // 访问初始顶点v
    visited[v] = true; // 对v做已访问标记
    LinkQueue Q;
    EnQueue(Q, v); // 顶点v入队
    while (!isEmpty(Q)) {
        DeQueue(Q, v); // 顶点v出队
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) { // 检测v的所有邻接点
            if (!visited[w]) { // w为v的尚未访问的邻接顶点
                visit(w); // 访问顶点w
                visited[w] = true; // 对w做已访问标记
                EnQueue(Q, w); // 顶点w入队
            }
        }
    }
}

void DFSTraverse(Graph G) {
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false;
    for (int v = 0; v < G.vexnum; ++v)
        if (!visited[v])
            DFS(G, v);
}
void DFS(Graph G, int v) {
    visit(v);
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}
