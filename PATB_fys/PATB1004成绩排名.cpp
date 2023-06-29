#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Student
{
    char name[11];
    char id[11];
    int grade;
};

int main()
{
    int n;
    scanf("%d", &n);
    struct Student student[101];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", &(student[i].name), &(student[i].id), &(student[i].grade));
    }
    int smax = 0, smin = 0;
    for (int i = 0; i < n; i++)
    {
        if (student[i].grade > student[smax].grade)
        {
            smax = i;
        }
        if (student[i].grade < student[smin].grade)
        {
            smin = i;
        }
    }
    printf("%s %s\n%s %s\n", student[smax].name, student[smax].id, student[smin].name, student[smin].id);
    return 0;
}