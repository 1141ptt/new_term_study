#include<bits/stdc++.h>
using namespace std;
struct LinkList {
	int data;
	LinkList *next;
	LinkList(int x) : data(x), next(NULL) {}
}; 
int dc(LinkList L, int n) {
	// L�Ǵ�ͷ����n��Ԫ�ص������ж������Ƿ����
	int i;
	char s[n/2];
	p = L->next; // ����Ĺ���ָ�� 
	for (i = 0; i < n / 2; i++) { // ����ǰһ��Ԫ�ؽ�ջ 
		s[i] = p->data;
		p = p->next;
	} 
	i--; // �ָ�����i 
	if (n % 2 == 1) // n�����������ƹ����Ľڵ� 
		p = p->next;
	while (p != NULL && s[i] == p->data) { // �ж��Ƿ���� 
		i--; // i�䵱ջָ�� 
		p = p->next;
	}
	if (i == -1) return 1;
	else return 0;
}
