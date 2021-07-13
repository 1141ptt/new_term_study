#include<bits/stdc++.h>
using namespace std;
struct LinkList {
	int data;
	LinkList *next;
	LinkList(int x) : data(x), next(NULL) {}
}; 
int dc(LinkList L, int n) {
	// L是带头结点的n个元素单链表，判断链表是否回文
	int i;
	char s[n/2];
	p = L->next; // 链表的工作指针 
	for (i = 0; i < n / 2; i++) { // 链表前一半元素进栈 
		s[i] = p->data;
		p = p->next;
	} 
	i--; // 恢复最后的i 
	if (n % 2 == 1) // n是奇数，后移过中心节点 
		p = p->next;
	while (p != NULL && s[i] == p->data) { // 判断是否回文 
		i--; // i充当栈指针 
		p = p->next;
	}
	if (i == -1) return 1;
	else return 0;
}
