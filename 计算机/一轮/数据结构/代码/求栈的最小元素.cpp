#include<iostream>
#include<stack> 
using namespace std;

// 一个有获取最小值功能的特殊栈，获取最小值的时间复杂度为O(1) 
class GetMinStack
{
	private:
	stack<int> m_BasicStack; //主栈
	stack<int> m_MinNumStack; //最小值栈
	
	public:	
	void push(int value) {//入栈
		if(m_BasicStack.empty()) //如果栈中无数据
			m_MinNumStack.push(value);        
		else if(value<=m_MinNumStack.top())  //如果入栈的值比当前的最小值还要小
		    m_MinNumStack.push(value);
		
		m_BasicStack.push(value); 
	} 
	
	int pop() {
		if(m_MinNumStack.empty())
			return -1; 
		
		int temp=m_BasicStack.top();
		m_BasicStack.pop();
		if(temp==m_MinNumStack.top())
		    m_MinNumStack.pop();
		
		return temp;  
	}
	
	int getMin() {
		if(m_MinNumStack.empty()) {
			return -1;  
		}
		return m_MinNumStack.top();
	}
};

int main()
{
	GetMinStack test;
	test.push(5);
	test.push(8);
	test.push(4);
	test.push(10);
	
	cout<<"该栈最小的数为："<<test.getMin()<<endl; 
}
