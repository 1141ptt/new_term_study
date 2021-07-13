#include<iostream>
#include<stack> 
using namespace std;

// һ���л�ȡ��Сֵ���ܵ�����ջ����ȡ��Сֵ��ʱ�临�Ӷ�ΪO(1) 
class GetMinStack
{
	private:
	stack<int> m_BasicStack; //��ջ
	stack<int> m_MinNumStack; //��Сֵջ
	
	public:	
	void push(int value) {//��ջ
		if(m_BasicStack.empty()) //���ջ��������
			m_MinNumStack.push(value);        
		else if(value<=m_MinNumStack.top())  //�����ջ��ֵ�ȵ�ǰ����Сֵ��ҪС
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
	
	cout<<"��ջ��С����Ϊ��"<<test.getMin()<<endl; 
}
