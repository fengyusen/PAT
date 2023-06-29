#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct man {
    int id, virtue, talent, flag;
};
bool cmp (man a, man b) {
    return a.flag != b.flag ? (a.flag > b.flag) : 
          (((a.virtue + a.talent) != (b.virtue + b.talent)) ? ((a.virtue + a.talent) > (b.virtue + b.talent)) : 
           ((a.virtue != b.virtue) ? (a.virtue > b.virtue) : (a.id < b.id)));
} 
int main() {
    int n, L, H;
    scanf("%d %d %d", &n, &L, &H);
    vector<man> v;
    while (n--) {
        man tmp;
        scanf("%d %d %d", &tmp.id, &tmp.virtue, &tmp.talent);
        if (tmp.virtue < L || tmp.talent < L) continue;
        else if (tmp.virtue >= H && tmp.talent >= H) tmp.flag = 3;
        else if (tmp.virtue >= H && tmp.talent < H) tmp.flag = 2;
        else if (tmp.virtue < H && tmp.talent < H && tmp.virtue >= tmp.talent) tmp.flag = 1;
        else tmp.flag = 0;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", v.size());
    for (auto &node : v) {
        printf("%d %d %d\n", node.id, node.virtue, node.talent);
    }
    return 0;
}