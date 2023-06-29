#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    long long int registration;
    int score, final_rank, location, loacl_rank;
};
bool cmp(node a, node b) {
    return a.score != b.score ? a.score > b.score : a.registration < b.registration;
}
int main() {
    int n, k;
    scanf("%d", &n);
    vector<node> data;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        vector<node> local_data;
        for (int j = 0; j < k; j++){
            node temp;
            scanf("%lld %d", &temp.registration, &temp.score);
            temp.location = i;
            local_data.push_back(temp);
        }
        sort(local_data.begin(), local_data.end(), cmp);
        local_data[0].loacl_rank = 1;
        for (int j = 1; j < k; j++) {
            local_data[j].loacl_rank = local_data[j].score == local_data[j-1].score ? local_data[j-1].loacl_rank : j + 1;
        }
        data.insert(data.end(), local_data.begin(), local_data.end());
    }
    sort(data.begin(), data.end(), cmp);
    data[0].final_rank = 1;
    for (int j = 1; j < data.size(); j++) {
        data[j].final_rank = data[j].score == data[j-1].score ? data[j-1].final_rank : j + 1;
    }
    printf("%d\n", data.size());
    for (auto it : data) {
        printf("%013lld %d %d %d\n", it.registration, it.final_rank, it.location, it.loacl_rank);
    }
    return 0;
}