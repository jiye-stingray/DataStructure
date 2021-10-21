#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>

//노드 i의 부모 노드 인텍스 = i / 2
//노드 i의 왼쪽 자식 노드 인텍스 = 2i
//노드 i의 오른쪽 자식 노드 인텍스 = 2i + 1



//노드
typedef struct
{
	int data;
}Node;

int count = 0;
//배열 트리 선언
typedef struct tree
{

	Node array[100];


}Tree;

//노드 추가
void Add_Node(Tree* insert_Tree, int insert_data) {

	count = count + 1;
	insert_Tree->array[count].data = insert_data;

}

//마지막 노드삭제
void Delete_Node(Tree* delete_Tree) {

	delete_Tree->array[count].data = NULL;
	count -= 1;

}

//탐색할 부모 data와 자식 출력
void Child_node(Tree* search_Tree, int p) {

	if (search_Tree->array[p * 2].data == NULL)
	{
		printf("왼쪽 자식은 값이 없습니다.");
	}
	else
	{
		printf("[%d][%d]", p * 2, search_Tree->array[p * 2].data);
	}

	if (search_Tree->array[(p * 2) + 1].data == NULL)
	{
		printf("오른쪽 자식은 값이 없습니다.");
	}
	else
	{
		printf("[%d][%d]", p * 2 + 1, search_Tree->array[(p * 2) + 1].data);
	}
}

//부모 탐색
void P_node(Tree* search_Tree, int c) {

	if (c * 2 <= 0)
	{
		printf("자식순번을 다시 설정해 주세요");
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
	

	//index, data 출력
	for (int i = 1; i <= count; i++)
	{
		printf("[%d][%d].\n", i, tree->array[i].data);
	}

	//자식 출력
	printf("\n자식 출력\n");
	Child_node(tree, 1);

	//부모 탐색
	printf("\n부모 탐색\n");
	P_node(tree, 3);

}