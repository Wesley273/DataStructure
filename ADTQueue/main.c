#include "queue.h"
#include "fatal.h"
#include <stdlib.h>
#include "queue.c"

void main()
{
    Queue myQueue;
    myQueue = CreateQueue(6);
    printf("下面将六个0~9的随机数入队：\n");
    for (int i = 0; i < 6; i++)
    {
        int randNum;
        randNum = rand() % 10;
        Enqueue(randNum, myQueue);
        printf("第%d个入队的数为：%d\n", i + 1, randNum);
    }
    printf("注意：这时再进行入队操作将返回队列已满提示并退出程序\n");
    //Enqueue(3, myQueue);
    printf("下面将六个数出队：\n");
    for (int i = 0; i < 6; i++)
    {
        printf("第%d个出队的数为：%d\n", i + 1, FrontAndDequeue(myQueue));
    }
    printf("判断这时队列是否为空（1代表是，0代表否）：%d\n", IsEmpty(myQueue));
    return (0);
}