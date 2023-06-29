#include <bits/stdc++.h>
using namespace std;

vector<string> hand,eye,mouth;

void  getSet(vector<string> &strs)
{
    strs.push_back("Are you kidding me? @\\/@");
    string S;
    getline(cin,S);
    int i=0;
    while(i<S.length()){
        if(S[i]=='['){
            int j=1;
            while (S[i+j]!=']')j++;
            strs.push_back(S.substr(i+1,j-1));
            i=i+j+1;
        }
        else i++;
    }
} 

int printOK(int a[5])
{
    int lhand=hand.size(),leye=eye.size(),lmouth=mouth.size();
    if(a[0]>0&&a[0]<lhand&&a[1]>0&&a[1]<leye&&a[2]>0&&a[2]<lmouth&&a[3]>0&&a[3]<leye&&a[4]>0&&a[4]<lhand)
    {
        cout<<hand[a[0]]<<"("<<eye[a[1]]<<mouth[a[2]]<<eye[a[3]]<<")"<<hand[a[4]]<<endl;
    }
    else{
        cout<<hand[0]<<endl;
    }
    return 0;
} 

int main()
{
    getSet(hand);
    getSet(eye);
    getSet(mouth);
    int N;
    cin>>N;
    int a[N][5];
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++)
            cin>>a[i][j];
        printOK(a[i]);
    }
    return 0;
}