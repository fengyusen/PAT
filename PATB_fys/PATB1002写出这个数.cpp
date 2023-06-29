#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char pinyin[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char s[100];
    scanf("%s", s);
    int num = strlen(s), sum = 0;
    for (int i = 0; i < num; i++) {
        int x = (int) (s[i]) - 48;
        sum += x;
    }
    int a = sum / 100;
    sum %= 100;
    int b = sum / 10;
    sum %= 10;
    int c = sum;
    if (a != 0) {
        printf("%s %s %s\n", pinyin[a], pinyin[b], pinyin[c]);
    } else if (b != 0) {
        printf("%s %s\n", pinyin[b], pinyin[c]);
    } else {
        printf("%s", pinyin[c]);
    }
    return 0;
}
