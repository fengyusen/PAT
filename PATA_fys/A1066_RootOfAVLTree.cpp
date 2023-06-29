#include <iostream>
using namespace std;
struct node {
    int val;
    node *left, *right;
};
int getHeight(node* root) {
    if (root == nullptr) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node* rotateLeft(node* root) {
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
node* rotateRight(node* root) {
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
node* rotateLeftRight(node* root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
node* rotateRightLeft(node* root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
node* insert(node* root, int val) {
    if (root == nullptr) {
        root = new node();
        root->val = val;
        root->left = root->right = nullptr;
    } else if (val < root->val) {
        root->left = insert(root->left, val);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
        }
    } else if (val > root->val) {
        root->right = insert(root->right, val);
        if (getHeight(root->left) - getHeight(root->right) == -2) {
            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
        }
    }
    return root;
}
int main() {
    int n, val;
    cin >> n;
    node* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }
    cout << root->val;
    return 0;
}