#include <cstdio>
using namespace std;
char MARS[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
int main() {
    char mars[6] = {'0'};
    int num;
    printf("#");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &num);
        printf("%c%c", MARS[num / 13], MARS[num % 13]);
    }
    return 0;
}