#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)



typedef struct listnode {
	int data;
	struct listnode* link;
}node;
node* top = NULL;

void push() {
	int data;
	printf("����Ÿ �Է�");
	scanf("%d", &data);
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;

	newnode->link = top;
	top = newnode;
}

void pop() {
	if (top == NULL)
		printf("data�� ����");
	top = top->link;
}

int main() {
	push();
	push();
	push();
	push();
	push();

	pop();

	for (int i = 0; top != NULL; i++)
	{
		printf("%d\n", top->data);
		top = top->link;
	}
	
}