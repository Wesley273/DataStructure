#include <stdio.h>
#include "fatal.h"
#include "tree.h"
#include "queue.h"
#include "tree.c"
#include "queue.c"

int main()
{
	SearchTree root, nodes[5];
	root = (SearchTree)malloc(sizeof(struct TreeNode));
	for (int i = 0; i < 5; i++)
	{
		nodes[i] = (SearchTree)malloc(sizeof(struct TreeNode));
	}
	//下面建立的树满足二叉查找树的规则
	root->Element = 6;
	nodes[0]->Element = 2;
	nodes[1]->Element = 8;
	nodes[2]->Element = 1;
	nodes[3]->Element = 4;
	nodes[4]->Element = 3;
	//下面将结点连接起来
	root->Left = nodes[0];
	root->Right = nodes[1];
	nodes[0]->Left = nodes[2];
	nodes[0]->Right = nodes[3];
	nodes[3]->Left = nodes[4];
	nodes[1]->Left = nodes[1]->Right = NULL;
	nodes[2]->Left = nodes[2]->Right = NULL;
	nodes[3]->Right = NULL;
	nodes[4]->Left = nodes[4]->Right = NULL;
	//下面对树进行层次遍历并输出显示
	traverseTheTree(root, 6);
	system("pause");
}