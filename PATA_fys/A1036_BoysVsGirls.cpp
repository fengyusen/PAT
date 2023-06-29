#include <stdio.h>
#include <algorithm>

//using namespace std;

struct info {
    char name[15];
    char id[15];
    int grade;
} F, M, tmp;


int main() {
    F.grade = -1;
    M.grade = 101;
    int n, i = 0;
    scanf("%d", &n);
    struct info sinfo[100];
    char gender;
    while (i++ < n) {
        scanf("%s %c %s %d", tmp.name, &gender, tmp.id, &tmp.grade);
        if (gender == 'F' && tmp.grade > F.grade) F = tmp;
        else if (gender == 'M' && tmp.grade < M.grade) M = tmp;
    }

    bool flag = true;
    if (F.grade == -1) printf("Absent\n");
    else printf("%s %s\n", F.name, F.id);
    if(M.grade == 101) printf("Absent\n");
    else printf("%s %s\n", M.name, M.id);
    if (F.grade == -1 || M.grade == 101) printf("NA\n");
    else printf("%d", F.grade - M.grade);
    return 0;
}