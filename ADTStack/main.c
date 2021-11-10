#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>
#include "stackar.c"

void main()
{
	int m = 0;
	Stack myStack = CreateStack(6);
	printf("下面将六个0~9的随机数入栈\n");
	for (int i = 0; i <= 5; i++)
	{
		Push(rand() % 10, myStack);
		printf("第%d个数入栈后，栈顶为：%d\n", i + 1, Top(myStack));
	}
	printf("注意：这时再进行入栈操作将返回栈满提示并退出程序\n");
	//Push(3, myStack);
	printf("下面将六个数出栈\n");
	for (int i = 0; i <= 5; i++)
	{
		m = TopAndPop(myStack);
		printf("第%d个出栈的数为：%d\n", i + 1, m);
	}
	printf("判断这时栈是否为空（1代表是，0代表否）：%d\n", IsEmpty(myStack));
}