#include <stdio.h>

#define CARDSNUM 54

int main() {
    int k;
    scanf("%d", &k);
    int order[CARDSNUM], oldorder[CARDSNUM], neworder[CARDSNUM];
    for (int i = 0; i < CARDSNUM; i++) {
        scanf("%d", &order[i]);
        order[i]--;
        oldorder[i] = i;
    }
    while (k--)
    {
        for (int i = 0; i < CARDSNUM; i++) {
            neworder[order[i]] = oldorder[i];
        }
        for (int i = 0; i < CARDSNUM; i++) {
            oldorder[i] = neworder[i];
        }
    }
    for(int i = 0; i < CARDSNUM; i++) {
        if (i) printf(" ");
        if (oldorder[i] / 13 == 0) {
            printf("S%d", oldorder[i] % 13 + 1);
        } else if (oldorder[i] / 13 == 1) {
            printf("H%d", oldorder[i] % 13 + 1);
        } else if (oldorder[i] / 13 == 2) {
            printf("C%d", oldorder[i] % 13 + 1);
        } else if (oldorder[i] / 13 == 3) {
            printf("D%d", oldorder[i] % 13 + 1);
        }  else if (oldorder[i] / 13 == 4) {
            printf("J%d", oldorder[i] % 13 + 1);
        }
    }
    return 0;
}