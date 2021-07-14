#include<bits/stdc++.h>
typedef struct {
	char *ch;
	int length;
}SString;
// ����ƥ��
int Index(SString S, SString T) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			++i; ++j; // �����ȽϺ���ַ�
		} else {
			i = i - j + 2; j = 1;	
		}
	}
	if (j > T.length)
		return i - T.length;
	else return 0;
}
// KMP�㷨
void get_next(SString T, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			++i; ++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
} 
int Index_KMP(SString S, SString T) {
	int i = 1, j = 1;
	int next[T.length + 1];
	get_next(T, next); // ���ַ�����next���� 
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i; ++j; // �ȽϺ���ַ� 
		} else {
			j = next[j]; // ģʽ�������ƶ� 
		}
	}
	if (j > T.length)
		return i - T.length; // ƥ��ɹ� 
	else
		return 0;
} 
