#include<bits/stdc++.h>
#define MaxSize 10
typedef struct {
	char data[MaxSize]; // 静态数组存放栈中元素 
	int top; // 栈顶指针 
}SqStack;
// 初始化栈 
void InitStack(SqStack &S) {}
// 判断栈是否为空 
bool StackEmpty(SqStack S) {}
// 入栈
bool push(SqStack &S, char x) {}
// 弹栈
bool pop(SqStack &S, char &x) {}

bool bracketCheck(char str[], int length) {
	SqStack S;
	InitStack(S);
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			push(S, str[i]);
		} else {
			if (StackEmpty(S)) { // 扫描到左括号且栈空 
				return false;
			}
			
			char topElem;
			pop(S, topElem); // 栈顶元素出栈 
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
