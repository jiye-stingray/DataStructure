#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>

//��� i�� �θ� ��� ���ؽ� = i / 2
//��� i�� ���� �ڽ� ��� ���ؽ� = 2i
//��� i�� ������ �ڽ� ��� ���ؽ� = 2i + 1



//���
typedef struct
{
	int data;
}Node;

int count = 0;
//�迭 Ʈ�� ����
typedef struct tree
{

	Node array[100];


}Tree;

//��� �߰�
void Add_Node(Tree* insert_Tree, int insert_data) {

	count = count + 1;
	insert_Tree->array[count].data = insert_data;

}

//������ ������
void Delete_Node(Tree* delete_Tree) {

	delete_Tree->array[count].data = NULL;
	count -= 1;

}

//Ž���� �θ� data�� �ڽ� ���
void Child_node(Tree* search_Tree, int p) {

	if (search_Tree->array[p * 2].data == NULL)
	{
		printf("���� �ڽ��� ���� �����ϴ�.");
	}
	else
	{
		printf("[%d][%d]", p * 2, search_Tree->array[p * 2].data);
	}

	if (search_Tree->array[(p * 2) + 1].data == NULL)
	{
		printf("������ �ڽ��� ���� �����ϴ�.");
	}
	else
	{
		printf("[%d][%d]", p * 2 + 1, search_Tree->array[(p * 2) + 1].data);
	}
}

//�θ� Ž��
void P_node(Tree* search_Tree, int c) {

	if (c * 2 <= 0)
	{
		printf("�ڽļ����� �ٽ� ������ �ּ���");
	}
	else
	{
		if (c % 2 == 1) {
			printf("[%d][%d]\n", (c - 1) / 2, search_Tree->array[(c - 1) / 2].data);

		}

		else
		{
			printf("[%d][%d]\n", c / 2, search_Tree->array[c / 2].data);
		}
	}


}
void main() {
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	Add_Node(tree, 10);
	Add_Node(tree, 20);
	Add_Node(tree, 30);
	Add_Node(tree, 40);
	

	//index, data ���
	for (int i = 1; i <= count; i++)
	{
		printf("[%d][%d].\n", i, tree->array[i].data);
	}

	//�ڽ� ���
	printf("\n�ڽ� ���\n");
	Child_node(tree, 1);

	//�θ� Ž��
	printf("\n�θ� Ž��\n");
	P_node(tree, 3);

}