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
	printf("data�� �Է��ϼ���\n");
	while (1) //data �Է�
	{
		node* newnode = (node*)malloc(sizeof(node));
		int n;
		scanf("%d", &n);
		newnode->data = n;
		newnode->link = NULL;
		if (newnode->data < 0) //����
			return;

		//if ��尡 NULL
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
	while (1)		// �����ϴ� �Լ�
	{
		int d;
		node* p = head;
		node* tmp = p;
		printf("������ node ��ȣ�� �Է����ּ���\n");
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
	//���
	node* temp = head;
	temp = head;
	for (int i = 0; i < cnt; i++)
	{
		
	}
	printf("%d\n", tail->link->data);

	while (1)
	{
		int i = 0;
		printf("%d��° data: ", i + 1);
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
		printf("�����͸� �Է��ϰ� ������ 1, �����ϰ� ������ 2, ����Ʈ�� ����ϰ� ������ 3, �׸��ΰ� ������ -1�� �Է��ϼ���\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: insert_node(); break;
		case 2: free_node(); break;
		case 3: print_node(); break;
		case -1: return;
		default:
			printf("�ٽ� �Է��� �ּ���\n");
			break;
		}
	}

	return;
	
}