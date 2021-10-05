#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
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

	while (1) //data 입력
	{
		node* newnode = (node*)malloc(sizeof(node));
		int n;
		scanf("%d", &n);
		newnode->data = n;
		newnode->link = NULL;
		if (newnode->data < 0) break; //음수

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

	while (1)		// 삭제하는 함수
	{
		int d;
		node * p = head;
		node* tmp = p;
		printf("삭제할 node 번호를 입력해주세요\n");
		scanf("%d", &d);
		if (d <= 0) break;
		for (int i = 1; i <= cnt; i++)
		{
			if (i == d) {
				tmp->link = p->link;
				free(p); 
				cnt--;  break;
			}
			tmp = p;
			p = p->link;
		}
	}
	

	node* temp = head;
	for (int i = 0; i < cnt; i++)
	{
		printf("%d번째 data: ", i + 1);
		printf("%d\n", temp->data);
		temp = temp->link;
	}

}