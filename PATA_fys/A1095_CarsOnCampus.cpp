#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
using namespace std;
struct node {
    char id[9];
    int time, flag = 0;
};
bool cmp (node a, node b) {
    if (strcmp(a.id, b.id) != 0) return strcmp(a.id, b.id) < 0;
    else return a.time < b.time;
}
bool cmp2 (node a, node b) {
    return a.time < b.time;
}
int main() {
    int n, k, hh, mm, ss, maxtime = -1;
    char status[5];
    scanf("%d %d", &n, &k);
    vector<node> record(n), car;
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %s", record[i].id, &hh, &mm, &ss, status);
        record[i].time = (hh * 60 + mm) * 60 + ss;
        record[i].flag = strcmp(status, "in") == 0 ? 1 : -1;
    }
    sort(record.begin(), record.end(), cmp);
    map<string, int> mapp;
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(record[i].id, record[i+1].id) == 0 && record[i].flag == 1 && record[i+1].flag == -1) {
            car.push_back(record[i]);
            car.push_back(record[i+1]);
            mapp[record[i].id] += (record[i+1].time - record[i].time);
            if (maxtime < mapp[record[i].id]) {
                maxtime = mapp[record[i].id];
            }
            //printf("%s %d-%d %d max:%d\n", record[i].id, record[i].time, record[i+1].time, mapp[record[i].id], maxtime);
        }
    }
    sort(car.begin(), car.end(), cmp2);
    vector<int> cnt(n);
    for (int i = 0; i < car.size(); i++) {
        if (i == 0) cnt[i] += car[i].flag;
        else cnt[i] = cnt[i-1] + car[i].flag;
    }
    int tempindex = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int j, temptime = hh * 3600 + mm * 60 + ss;
        for (j = tempindex; j < car.size(); j++) {
            if (car[j].time > temptime) {
                printf("%d\n", cnt[j-1]);
                break;
            } else if (j == car.size() - 1) {
                printf("%d\n", cnt[j]);
            }
        }
        tempindex = j;
    }
    //printf("maxtime:%d\n", maxtime);
    for (map<string, int>::iterator it = mapp.begin(); it != mapp.end(); it++) {
        //printf("***%s %d***\n", it->first.c_str(), it->second);
        if (it->second == maxtime) printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
    return 0;
}