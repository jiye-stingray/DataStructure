#include <stdio.h>
#define STACK_SIZE 5
typedef char element;
element stack[STACK_SIZE];
int top = -1;
char push(element item) { //���� �߰�
	if (top >= STACK_SIZE - 1) {
		printf("Stack is Full!\n");
		return;
	}
	else stack[++top] = item;
}
char pop() { //���� ����
	if (top == -1)
	{
		printf("Stack is Empty!\n");
		return 0;
	}
	else return stack[top--];
}
element peek() {
	if (top == -1) {
		printf("Stack is Empty!\n");
		return 0;
	}
	else return stack[top];
}
	int main() {

		//���� ����ֱ�
		/*for (int i = 1; i <= 4; i++)
		{
			push(i * 10);
		}
		for (int i = 0; i < 2; i++)
		{
			pop();
		}
		for (int i = 5; i <= 7; i++)
		{
			push(i * 10);
		}
	
		for (int i = STACK_SIZE-1; i >= 0; i--) printf("%d : %d\n", i, stack[i]);*/

		//���ڿ� ����ֱ�
		push('H');
		push('E');
		push('L');
		push('L');
		push('O');

		printf("%c\n", pop());
		printf("%c\n", pop());
		printf("%c\n", pop());
		printf("%c\n", pop());
		printf("%c\n", pop());


	
		return 0;
	}