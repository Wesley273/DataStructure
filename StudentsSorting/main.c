#include <stdio.h>
#include <stdlib.h>
#include "SortStudents.h"
#include "SortStudents.c"
void main()
{
    int count;
    printf("������һ���ж��ٸ�ѧ����\n");
    scanf("%d", &count);
    students student[200];
    getIndex(count, student);
    useShellSort(count, student);
    showIndex(count, student);
    system("PAUSE");
}