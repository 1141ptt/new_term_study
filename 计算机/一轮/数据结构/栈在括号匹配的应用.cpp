#include<bits/stdc++.h>
#define MaxSize 10
typedef struct {
	char data[MaxSize]; // ��̬������ջ��Ԫ�� 
	int top; // ջ��ָ�� 
}SqStack;
// ��ʼ��ջ 
void InitStack(SqStack &S) {}
// �ж�ջ�Ƿ�Ϊ�� 
bool StackEmpty(SqStack S) {}
// ��ջ
bool push(SqStack &S, char x) {}
// ��ջ
bool pop(SqStack &S, char &x) {}

bool bracketCheck(char str[], int length) {
	SqStack S;
	InitStack(S);
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			push(S, str[i]);
		} else {
			if (StackEmpty(S)) { // ɨ�赽��������ջ�� 
				return false;
			}
			
			char topElem;
			pop(S, topElem); // ջ��Ԫ�س�ջ 
			if (str[i] == ')' && topElem != '(') {
				return false;
			}
			if (str[i] == ']' && topElem != '[') {
				return false;
			}
			if (str[i] == '}' && topElem != '{') {
				return false;
			}
		}
	}
	return StackEmpty(S);
}
