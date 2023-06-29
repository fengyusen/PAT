#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    int num=0;
    while(n!=1){
        if(n%2==0){
            n/=2;
        }
        else{
            n=(3*n+1)/2;
        }
        num++;
    }
    printf("%d",num);
    return 0;
}
