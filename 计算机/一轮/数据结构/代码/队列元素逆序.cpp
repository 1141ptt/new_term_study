void Inverser(Stack &S, Queue &Q) {
	while (!QueueEmpty(Q)) {
		x = DeQueue(Q); // ����Ԫ�����γ��� 
		Push(S, x); // ������ջ 
	}
	while (!StackEmpty(S)) {
		Pop(S, x); // ջ��Ԫ�����γ�ջ 
		EnQueue(Q, x); // ������� 
	}
}
