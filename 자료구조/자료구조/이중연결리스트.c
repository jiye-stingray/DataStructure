#include <stdio.h>
#include <malloc.h>
#pragma warning (disable:4996)
typedef struct ListNode {
	int data;
	struct listnode* prev;
	struct listnode* next;
}node;
node* head = NULL;
node* tail = NULL;
void insert_node() {
	int d;
	printf("data 입력");
	scanf("%d", &d);
	if (d < 0)
		return;
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = d;
	if (head == NULL) {
		head = newnode;
		tail = newnode;
	}
	else {
		tail->next = newnode;
		newnode->prev = tail;
		tail = tail->next;
	}
	insert_node();
}
void print_node() {
	node* temp = head;
	while (tail != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
void free_node() {
	int num;
	printf("삭제할 노드 번호를 입력하세요");
	scanf("%d", &num);
	num++;
	node* temp = head;
	for (int i = 0; i < num; i++)
	{
		temp = temp->next;
	}
	node* p = temp->prev;
	node* n = temp->next;

	p->next = n;
	n->prev = p;

	free(temp);
	
}
int main() {

	insert_node();
	free_node();

	print_node();
}

