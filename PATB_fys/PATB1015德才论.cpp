#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct node {
    int num;
    int de;
    int cai;
};

int cmp(struct node a, struct node b) {
    if ((a.de + a.cai) != (b.de + b.cai)) {
        return (a.de + a.cai) > (b.de + b.cai);
    }else if (a.de != b.de) {
        return a.de > b.de;
    } else
        return a.num < b.num;
}

int main() {
    int n, low, high;
    cin >> n >> low >> high;
    vector<node> a, b, c, d;
    node temp;
    int total = n;
    for (int i = 0; i < n; i++) {
        cin >> temp.num >> temp.de >> temp.cai;
        if (temp.de < low || temp.cai < low) {
            total--;
            continue;
        }
        if (temp.de >= high && temp.cai >= high) {
                a.push_back(temp);
            } else if (temp.de >= high && temp.cai < high) {
                b.push_back(temp);
            } else if (temp.de < high && temp.cai < high && temp.de >= temp.cai) {
                c.push_back(temp);
            } else {
                d.push_back(temp);
            }
    }
    
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    sort(c.begin(), c.end(), cmp);
    sort(d.begin(), d.end(), cmp);
    
    printf("%d\n", total);
    vector<node>::iterator itr;
    for(itr = a.begin(); itr != a.end(); itr++)
        printf("%d %d %d\n", itr->num, itr->de, itr->cai);
    
    for(itr = b.begin(); itr != b.end(); itr++)
        printf("%d %d %d\n", itr->num, itr->de, itr->cai);
    
    for(itr = c.begin(); itr != c.end(); itr++)
        printf("%d %d %d\n", itr->num, itr->de, itr->cai);
    
    for(itr = d.begin(); itr != d.end(); itr++)
        printf("%d %d %d\n", itr->num, itr->de, itr->cai);

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// struct student{
//     string sno;
//     int de;
//     int cai;
// };

// int cmp(struct student a,struct student b)
// {
//     if((a.de+a.cai)!=(b.de+b.cai))
//         return a.de+a.cai>b.de+b.cai;
//     else if(a.de!=b.de){
//         return a.de>b.de;
//     }
//     else{
//         return a.sno<b.sno;
//     }
// }   

// int main() {
//     int N,L,H,M;
//     cin>>N>>L>>H;
//     vector<student> A,B,C,D;
//     struct student stu;
//     for(int i=0;i<N;i++)
//     {
//         cin>>stu.sno>>stu.de>>stu.cai;
//         if(stu.de>=H&&stu.cai>=H){
//             A.push_back(stu);
//         }
//         else if(stu.de>=H&&stu.cai<H&&stu.cai>=L){
//             B.push_back(stu);
//         }
//         else if(stu.de<H&&stu.cai<H&&stu.de>=stu.cai&&stu.cai>=L){
//             C.push_back(stu);
//         }
//         else{
//             D.push_back(stu);
//         }
//     } 
//     sort(A.begin(),A.end(),cmp);
//     sort(B.begin(),B.end(),cmp);
//     sort(C.begin(),C.end(),cmp);
//     sort(D.begin(),D.end(),cmp);
//     for(int i=0;i<A.size();i++){
//         stu=A[i];
//         printf("%s %d %d\n",stu.sno,stu.de,stu.cai);
//     } 
//     for(int i=0;i<B.size();i++){
//         stu=B[i];
//         printf("%s %d %d\n",stu.sno,stu.de,stu.cai);
//     } 
//     for(int i=0;i<C.size();i++){
//         stu=C[i];
//         printf("%s %d %d\n",stu.sno,stu.de,stu.cai);
//     } 
//     for(int i=0;i<D.size();i++){
//         stu=D[i];
//         printf("%s %d %d\n",stu.sno,stu.de,stu.cai);
//     } 
//     return 0;
// }