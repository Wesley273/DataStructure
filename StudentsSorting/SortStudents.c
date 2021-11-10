#include "SortStudents.h"
struct StudentCard
{
    char Name[100];
    int Grade;
};
void useBubbleSort(int count, students student[])
{
    //�������ð������
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
    //����ʹ�õ�������Shell���������
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
        //���г�ʼ��
        student[i] = (students)malloc(sizeof(struct StudentCard));
        printf("�������%d��ѧ��������\n", i + 1);
        scanf("%s", student[i]->Name);
        printf("�������%d��ѧ���ĳɼ�\n", i + 1);
        scanf("%d", &(student[i]->Grade));
    }
}
void showIndex(int count, students student[])
{
    //������ʾ������Σ�ͬ������ͬѧ����һ��
    int rank = 1;
    for (int i = 0; i < count; i++)
    {
        if (!i)
        {
            printf("��%d����%s���ɼ���%d��\n", rank++, student[i]->Name, student[i]->Grade);
        }
        else
        {
            if (student[i]->Grade == student[i - 1]->Grade)
            {
                printf("       %s���ɼ���%d��\n", student[i]->Name, student[i]->Grade);
            }
            else
            {
                printf("��%d����%s���ɼ���%d��\n", rank, student[i]->Name, student[i]->Grade);
            }
            rank++;
        }
    }
}