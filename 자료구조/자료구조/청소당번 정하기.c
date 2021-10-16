#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct listnode {
	char data[10];
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
		char n[10];
		scanf("%s", &n);
		//->data = n;
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
}	  //���� �Լ�
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
}		//���� �Լ�
void print_node() {
	//���
	node* temp = head;
	temp = head;

	int num;
	printf("��� ° û�Ҵ���� �ñ��ϽŰ���?");
	scanf("%s\n", &num);
	int cnt = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (i == cnt)
			printf("%s", temp->data);
		cnt++;
		temp = temp->link;
	}
	


}	 //����Լ�
int main() {



	while (1)
	{
		int n;
		printf("û�� ����� �Է��ϰ� ������ 1, �����ϰ� ������ 2, û�Ҵ���� ����ϰ� ������ 3, �׸��ΰ� ������ -1�� �Է��ϼ���\n");
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