#include <bits/stdc++.h>
using namespace std;
int main()
{
    int firstaddr, N, K, temp = 0;
    cin >> firstaddr >> N >> K;
    int node[100005], data[100005], next[100005];
    for (int i = 0; i < N; i++){
        cin >> temp >> data[temp] >> next[temp];
    }
    int count=0;
    while(firstaddr!=-1){
        node[count++]=firstaddr;
        count=next[count];
    }
    for(int i=0;i<count-count%K;i+=K){
        reverse(begin(node)+i,begin(node)+i+K);
    } 
    for (int i = 0; i < count - 1; i++){
        printf("%05d %d %05d\n", node[i], data[node[i]], node[i+1]);
    }
    printf("%05d %d -1\n", node[count-1], data[node[count-1]]);
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int firstaddr, N,num=0, K, temp = 0, kaddr = 0;
//     cin >> firstaddr >> N >> K;
//     int node[100005], data[100005], next[100005];
//     for (int i = 0; i < N; i++){
//         cin >> temp >> data[temp] >> next[temp];
//         node[temp] = next[temp];
//     }
//     temp = firstaddr;
//     while(temp!=-1){
//         num++;
//         temp=next[temp];
//     }
//     temp = firstaddr;
//     int startaddr = temp, endaddr;
//     for (int j = 0; j + K - 1 < num; j = j + K){
//         for (int i = j; i < j + K - 1; i++){
//             node[next[temp]] = temp;
//             temp = next[temp];
//         }
//         if (j == 0){
//             kaddr = temp;
//             endaddr = next[temp];
//         } else{ 
//             node[startaddr] = temp;
//             startaddr = endaddr;
//             endaddr = next[temp];
//         }
//         if (j + 2 * K > num){
//             node[startaddr] = next[temp];
//         }
//         temp = next[temp];
//     }
//     temp = kaddr;
//     for (int i = 0; i < num - 1; i++){
//         printf("%05d %d %05d\n", temp, data[temp], node[temp]);
//         temp = node[temp];
//     }
//     printf("%05d %d -1\n", temp, data[temp]);
//     return 0;
// }