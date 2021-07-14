#include<bits/stdc++.h>
typedef struct {
	char *ch;
	int length;
}SString;
// 朴素匹配
int Index(SString S, SString T) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			++i; ++j; // 继续比较后继字符
		} else {
			i = i - j + 2; j = 1;	
		}
	}
	if (j > T.length)
		return i - T.length;
	else return 0;
}
// KMP算法
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
	get_next(T, next); // 求字符串的next数组 
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i; ++j; // 比较后继字符 
		} else {
			j = next[j]; // 模式串向右移动 
		}
	}
	if (j > T.length)
		return i - T.length; // 匹配成功 
	else
		return 0;
} 
