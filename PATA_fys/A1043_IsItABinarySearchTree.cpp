#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> ins, pre, post;
// bool isMirror;
// struct node {
//     int val;
//     node* left;
//     node* right;
// };
// void insert(node* &root, int val) {
//     if (root == nullptr) {
//         root = new node;
//         root->left = nullptr, root->right = nullptr;
//         root->val = val;
//     } else if (val < root->val) insert(root->left, val);
//     else insert(root->right, val);
// }
// void preOrder(node* root) {
//     if (root == nullptr) return;
//     //printf("%d ", root->val);
//     pre.push_back(root->val);
//     if (!isMirror) {
//         preOrder(root->left);
//         preOrder(root->right);
//     } else {
//         preOrder(root->right);
//         preOrder(root->left);
//     }
// }
// void postOrder(node* root) {
//     if (root == nullptr) return;
//     if (!isMirror) {
//         postOrder(root->left);
//         postOrder(root->right);
//     } else {
//         postOrder(root->right);
//         postOrder(root->left);
//     }
//     post.push_back(root->val);
// }
// int main() {
//     int n;
//     scanf("%d", &n);
//     ins.resize(n);
//     node* root = nullptr;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &ins[i]);
//         insert(root, ins[i]);
//     }
//     bool flag = true;
//     preOrder(root);
//     for (int i = 0; i < n; i++) {
//         if (ins[i] != pre[i]) {
//             flag = false;
//             break;
//         }
//     }
//     if (!flag) {
//         isMirror = true;
//         pre.clear();
//         preOrder(root);
//         flag = true;
//     } 
//     for (int i = 0; i < n; i++) {
//         if (ins[i] != pre[i]) {
//             flag = false;
//             break;
//         }
//     }
//     if (!flag) printf("NO");
//     else {
//         postOrder(root);
//         printf("YES\n%d", post[0]);
//         for (int i = 1; i < n; i++) {
//             printf(" %d", post[i]);
//         }
//     }
//     return 0;
// }