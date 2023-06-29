#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int n, k = 0;
    char a[50], b[50];
    double y = 0.0, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);
        int flag = 0;
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] != b[i]) flag = 1;
        }
        if (flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
        } else {
            y += temp;
            k ++;
        }
    }
    if (k == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (k == 1) {
        printf("The average of 1 number is %.2lf\n", y);
    } else {
        printf("The average of %d numbers is %.2f\n", k, y / k);
    }
    return 0;
}