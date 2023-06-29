#include <iostream>
using namespace std;
int main() {
    int n, num, total_time = 0, curr_floor = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        total_time += 5 + ((num > curr_floor) ? (num - curr_floor) * 6 : (curr_floor - num) * 4);
        curr_floor = num;
    }
    printf("%d", total_time);
    return 0;
}
