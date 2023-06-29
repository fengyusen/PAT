#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct sch {
    int maxNum, nowNum = 0, lastindex;
    vector<int> stuID;
};
struct peo {
    int ge, g1, fin, id, rank;
    vector<int> choice;
};
bool cmp (peo a, peo b) {
    if (a.fin != b.fin) return a.fin > b.fin;
    return a.ge > b.ge;
}
bool isEqual (peo& a, peo& b) {
    return a.ge == b.ge && a.g1 == b.g1;
}
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<sch> schs(m);
    vector<peo> stu(n);
    for (int i = 0; i < m; i++)
        scanf("%d", &schs[i].maxNum);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &stu[i].ge, &stu[i].g1);
        stu[i].id = i;
        stu[i].fin = stu[i].ge + stu[i].g1;
        stu[i].choice.resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d", &stu[i].choice[j]);
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int sid = stu[i].choice[j];
            if (schs[sid].nowNum < schs[sid].maxNum || isEqual(stu[schs[sid].lastindex], stu[i])) {
                schs[sid].stuID.push_back(stu[i].id);
                schs[sid].lastindex = i;
                schs[sid].nowNum++;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        sort(schs[j].stuID.begin(), schs[j].stuID.end());
        for (int i = 0; i < schs[j].stuID.size(); i++) {
            if (i) printf(" ");
            printf("%d", schs[j].stuID[i]);
        }
        printf("\n");
    }
    return 0;
}