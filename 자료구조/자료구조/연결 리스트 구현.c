#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//with ���� ��

typedef int element;
// ��� Ÿ���� ����ü�� �����Ѵ�.
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//  ��� ����
ListNode* insert_node(ListNode* head, int value)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode)); //(1)
	new_node->data = value;

	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	pre = head;

	//Ž��
	while (pre != NULL) {
		if (pre->data < value)
			break;
		pre = pre->link;
	}

	if (head == NULL)
	{
		new_node->link = NULL;
		head = new_node;
	}
	else if (pre == NULL)
	{

		new_node->link = head;
		head = new_node;
	}
	else {

		new_node->link = pre->link;
		pre->link = new_node;
	}

	return head;
}

// ��� ����
ListNode* node_delete(ListNode* head, int value)
{
	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	pre = head;

	//Ž��
	while (pre != NULL) {
		if (pre->data < value)
			break;
		pre = pre->link;
	}

	ListNode* removed;
	if (head == NULL) return NULL;
	else if (pre == NULL)//ù ��� ����
	{

		removed = head; // (1)
		head = removed->link; // (2)
		free(removed);
	}
	//������ ��� ����
	else if (pre->link == NULL)
	{
		free(pre);
	}
	//�߰� ��� ����
	else {
		removed = pre->link;

		pre->link = removed->link; // (2)

		free(removed);
	}

	return head; // (4)

}
// ����Ʈ ���
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
// ����
int main(void)
{
	ListNode* head = NULL;

	head = insert_node(head, 10);
	head = insert_node(head, 20);
	head = insert_node(head, 5);
	head = insert_node(head, 2);

	print_list(head);

	head = node_delete(head, 5);
	print_list(head);

	head = node_delete(head, 2);
	print_list(head);


	head = node_delete(head, 20);
	print_list(head);

	return 0;
}