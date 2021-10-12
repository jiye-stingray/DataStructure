#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct listnode {
	int data;
	struct listnode* link;
}node;
node* head = NULL;
node* tail = NULL;
int cnt = 0;

void insert_node() {
	printf("data를 입력하세요\n");
	while (1) //data 입력
	{
		node* newnode = (node*)malloc(sizeof(node));
		int n;
		scanf("%d", &n);
		newnode->data = n;
		newnode->link = NULL;
		if (newnode->data < 0) //음수
			return;

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
		tail->link = head;
		cnt++;
	}
}
void free_node() {
	while (1)		// 삭제하는 함수
	{
		int d;
		node* p = head;
		node* tmp = p;
		printf("삭제할 node 번호를 입력해주세요\n");
		scanf("%d", &d);
		if (d <= 0) return;
		for (int i = 1; i <= cnt; i++)
		{
			if (i == d) {
				tmp->link = p->link;
				free(p);
				cnt--;  return;
			}
			tmp = p;
			p = p->link;
		}
	}
}
void print_node() {
	//출력
	node* temp = head;
	temp = head;
	for (int i = 0; i < cnt; i++)
	{
		
	}
	printf("%d\n", tail->link->data);

	while (1)
	{
		int i = 0;
		printf("%d번째 data: ", i + 1);
		printf("%d\n", temp->data);
		i++;
		temp = temp->link;
		if (temp->data == NULL)
			return;
	}
}
int main() {
	

	
	while (1)
	{
		int n;
		printf("데이터를 입력하고 싶으면 1, 삭제하고 싶으면 2, 리스트를 출력하고 싶으면 3, 그만두고 싶으면 -1를 입력하세요\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: insert_node(); break;
		case 2: free_node(); break;
		case 3: print_node(); break;
		case -1: return;
		default:
			printf("다시 입력해 주세요\n");
			break;
		}
	}

	return;
	
}