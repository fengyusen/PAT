#include <iostream>
#include <cstring>
using namespace std;
struct node {
    char name[12], id[12];
    bool flag = false; 
};
int main() {
    node data[101];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[12], id[12];
        int grade;
        scanf("%s %s %d", name, id, &grade);
        strcpy(data[grade].name, name);
        strcpy(data[grade].id, id);
        data[grade].flag = true;
    }
    int grade1, grade2;
    scanf("%d %d", &grade1, &grade2);
    bool isNone = true;
    for (int i =  grade2 <= 100 ? grade2 : 100; i >= grade1 && i >= 0; i--) {
        if (data[i].flag == true) {
            if (isNone == false) printf("\n");
            printf("%s %s", data[i].name, data[i].id);
            isNone = false;
        }
    }
    if (isNone) printf("NONE");
    return 0;
}
