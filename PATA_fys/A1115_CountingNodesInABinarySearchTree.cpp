#include <iostream>
using namespace std;
struct node {
    int val;
    node *left, *right;
};
node* insert(node* root, int val) {
    if (root == nullptr) {
        root = new node();
        root->val = val;
        root->left = root->right = nullptr;
    } else if (val <= root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}
int num[1000] = {0}, maxdepth = -1;
void dfs(node* root, int depth) {
    if (root == nullptr) return ;
    maxdepth = max(maxdepth, depth);
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
int main() {
    int n, val;
    cin >> n;
    node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }
    dfs(root, 1);
    printf("%d + %d = %d", num[maxdepth], num[maxdepth-1], num[maxdepth] + num[maxdepth-1]);
    return 0;
}