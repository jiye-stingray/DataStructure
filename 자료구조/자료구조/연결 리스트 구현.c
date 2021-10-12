#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//with 강권 쌤

typedef int element;
// 노드 타입을 구조체로 정의한다.
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//  노드 삽입
ListNode* insert_node(ListNode* head, int value)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode)); //(1)
	new_node->data = value;

	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	pre = head;

	//탐색
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

// 노드 삭제
ListNode* node_delete(ListNode* head, int value)
{
	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	pre = head;

	//탐색
	while (pre != NULL) {
		if (pre->data < value)
			break;
		pre = pre->link;
	}

	ListNode* removed;
	if (head == NULL) return NULL;
	else if (pre == NULL)//첫 노드 삭제
	{

		removed = head; // (1)
		head = removed->link; // (2)
		free(removed);
	}
	//마지막 노드 삭제
	else if (pre->link == NULL)
	{
		free(pre);
	}
	//중간 노드 삭제
	else {
		removed = pre->link;

		pre->link = removed->link; // (2)

		free(removed);
	}

	return head; // (4)

}
// 리스트 출력
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
// 메인
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