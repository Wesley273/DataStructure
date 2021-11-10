#include <stdio.h>
#include <stdlib.h>
#include "SortStudents.h"
#include "SortStudents.c"
void main()
{
    int count;
    printf("请输入一共有多少个学生：\n");
    scanf("%d", &count);
    students student[200];
    getIndex(count, student);
    useShellSort(count, student);
    showIndex(count, student);
    system("PAUSE");
}