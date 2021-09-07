#include <stdio.h>
#define STACK_SIZE 5
typedef char element;
element stack[STACK_SIZE];
int top = -1;
char push(element item) { //스택 추가
	if (top >= STACK_SIZE - 1) {
		printf("Stack is Full!\n");
		return;
	}
	else stack[++top] = item;
}
char pop() { //스택 제거
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

		//숫자 집어넣기
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

		//문자열 집어넣기
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