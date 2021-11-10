#include "SortStudents.h"
struct StudentCard
{
    char Name[100];
    int Grade;
};
void useBubbleSort(int count, students student[])
{
    //下面进行冒泡排序
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (student[j]->Grade < student[j + 1]->Grade)
            {
                students temp;
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
}
void useShellSort(int count, students student[])
{
    //这里使用的增量是Shell建议的序列
    for (int Increment = count / 2; Increment > 0; Increment /= 2)
        for (int i = Increment; i < count; i++)
        {
            int j;
            students temp;
            temp = student[i];
            for (j = i; j >= Increment; j -= Increment)
                if (temp->Grade > student[j - Increment]->Grade)
                    student[j] = student[j - Increment];
                else
                    break;
            student[j] = temp;
        }
}
void getIndex(int count, students student[])
{
    for (int i = 0; i < count; i++)
    {
        //进行初始化
        student[i] = (students)malloc(sizeof(struct StudentCard));
        printf("请输入第%d个学生的姓名\n", i + 1);
        scanf("%s", student[i]->Name);
        printf("请输入第%d个学生的成绩\n", i + 1);
        scanf("%d", &(student[i]->Grade));
    }
}
void showIndex(int count, students student[])
{
    //用于显示输出名次，同分数的同学名次一致
    int rank = 1;
    for (int i = 0; i < count; i++)
    {
        if (!i)
        {
            printf("第%d名：%s，成绩：%d分\n", rank++, student[i]->Name, student[i]->Grade);
        }
        else
        {
            if (student[i]->Grade == student[i - 1]->Grade)
            {
                printf("       %s，成绩：%d分\n", student[i]->Name, student[i]->Grade);
            }
            else
            {
                printf("第%d名：%s，成绩：%d分\n", rank, student[i]->Name, student[i]->Grade);
            }
            rank++;
        }
    }
}