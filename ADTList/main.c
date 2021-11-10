#include <stdio.h>
#include "fatal.h"
#include "list.h"
#include "list.c"
int main()
{
	int position, value;
	List myList;
	myList = getList();
	showList(myList);
	printf("检验该表是否为空\n");
	printf("%d\n", IsEmpty(myList));
	printf("请问要找的节点是第几个节点？\n");
	scanf_s("%d", &position);
	getElement(position, myList);
	printf("请问要删除的节点是第几个节点？\n");
	scanf_s("%d", &position);
	deleteElement(position, myList);
	showList(myList);
	printf("请问要在第几个节点之后插入一个结点？\n");
	scanf_s("%d", &position);
	printf("请问要插入的节点的值为多少？\n");
	scanf_s("%d", &value);
	insertElement(position, value, myList);
	showList(myList);
	getchar();
}