void Inverser(Stack &S, Queue &Q) {
	while (!QueueEmpty(Q)) {
		x = DeQueue(Q); // 队列元素依次出队 
		Push(S, x); // 依次入栈 
	}
	while (!StackEmpty(S)) {
		Pop(S, x); // 栈中元素依次出栈 
		EnQueue(Q, x); // 依次入队 
	}
}
