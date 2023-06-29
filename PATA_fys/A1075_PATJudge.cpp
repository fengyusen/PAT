#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, total_score = 0, pefect_num = 0, problems[6];
    bool isshown = false;
};
bool cmp (node a, node b) {
    if (a.isshown != b.isshown) {
        return a.isshown == true;
    } else if (a.total_score != b.total_score) {
        return a.total_score > b.total_score;
    } else if (a.pefect_num != b.pefect_num) {
        return a.pefect_num > b.pefect_num; 
    } else {
        return a.id < b.id;
    }
}
int main() {
    int n, k, m, problem_score[6];
    scanf("%d %d %d", &n, &k, &m);
    vector<node> data(n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            data[i].problems[j] = -1;
        }
        data[i].pefect_num = 0;
        data[i].total_score = 0;
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &problem_score[i]);
    }
    for (int i = 0; i < m; i++) {
        int uid, pid, score;
        scanf("%d %d %d", &uid, &pid, &score);
        data[uid-1].id = uid;
        if (score >= 0) {
            data[uid-1].isshown = true;
            data[uid-1].problems[pid] = max(score, data[uid-1].problems[pid]);
        } else {
            data[uid-1].problems[pid] = max(0, data[uid-1].problems[pid]);
        }
    }
    for (int i = 0; i < n; i++) {
        int total_score = 0, perfect_num = 0; 
        for (int j = 1; j <= k; j++) {
            total_score += data[i].problems[j] > 0 ? data[i].problems[j] : 0;
            if (data[i].problems[j] == problem_score[j]) {
                perfect_num++;
            }
        }
        data[i].pefect_num = perfect_num;
        data[i].total_score = total_score;
    }
    sort(data.begin(), data.end(), cmp);
    int ans = data[0].total_score, rank = 1;
    for (int i = 0; i < n; i++) {
        if (data[i].isshown == false) break;
        if (i) printf("\n");
        rank = data[i].total_score == ans ? rank : i + 1;
        printf("%d %05d %d", rank, data[i].id, data[i].total_score);
        ans = data[i].total_score;
        for (int j = 1; j <= k; j++) {
            if (data[i].problems[j] > -1) {
                printf(" %d", data[i].problems[j]);
            } else {
                printf(" -");
            }
        }
    }
    return 0;
}