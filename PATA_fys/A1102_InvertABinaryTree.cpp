#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, root;
vector<int> lchild(10, -1), rchild(10, -1), parent(10, -1);
vector<int> in;
map<int, int> level;
void inOrder(int root, int index) {
    if (root == -1) return;
    level[index] = root;
    inOrder(lchild[root], 2 * index);
    in.push_back(root);
    inOrder(rchild[root], 2 * index + 1);
}
int main() {
    scanf("%d", &n);getchar();
    for (int i = 0; i < n; i++) {
        char a, b;
        scanf("%c %c", &a, &b);getchar();
        if (isdigit(a)) {
            lchild[i] = a - '0';
            parent[lchild[i]] = i;
        }
        if (isdigit(b)) {
            rchild[i] = b - '0';
            parent[rchild[i]] = i;
        }
        swap(lchild[i], rchild[i]);
    }
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) root = i;
    }
    inOrder(root, 1);
    auto it = level.begin();
    printf("%d", it->second);
    while(++it != level.end()) printf(" %d", it->second);
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", in[i]);
    }
    return 0;
}