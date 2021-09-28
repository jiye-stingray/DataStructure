#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)
typedef struct listnode {
	int data;
	struct listnode* link;
}node;

int main() {
	node* head = NULL;
	node* tail = NULL;

	/*newnode->data = 10;
	newnode->link = NULL;*/
	int cnt = 0;
	printf("data를 입력하세요\n");
	while (1)
	{
		node* newnode = (node*)malloc(sizeof(node));
		int n;
		scanf("%d", &n);
		newnode->data = n;
		newnode->link = NULL;
		if (newnode->data < 0) break;
		//if 헤드가 NULL
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else {
			tail->link = newnode;
		}
		tail = newnode;
		cnt++;
	}

	node* temp = head;
	for (int i = 0; i < cnt; i++)
	{
		printf("%d번째 data: ", i + 1);
		printf("%d\n", temp->data);
		temp = temp->link;
	}
	
}