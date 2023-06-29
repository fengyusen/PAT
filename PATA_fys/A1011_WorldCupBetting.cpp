//#include <bits/stdc++.h>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

char s[3] = {'W', 'T', 'L'};

int main()
{
    double profit = 1.0;
    for(int i = 0; i < 3; i++) {
        double max_odd = 0, odd = 0;
        int max_index = 0;
        for(int j = 0; j < 3; j++) {
            cin>>odd;
            if(odd > max_odd) {
                max_odd = odd;
                max_index = j;
            }
        }
        if (i != 0) printf(" ");
        printf("%c", s[max_index]);
        profit *= max_odd;
    }
    profit = (profit * 0.65 - 1) * 2;
    printf(" %.2f", profit);
    return 0;
}
