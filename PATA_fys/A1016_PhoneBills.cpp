#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct record {
    string name;
    int minutes, time[4], flag;// 1 online, off line;
};
bool cmp_record(record a, record b) {
    return a.name != b.name ? a.name < b.name : a.minutes < b.minutes;
}
double billFromZero(record call, int* rate) {
    double total = rate[call.time[2]] * call.time[3] + rate[24] * 60 * call.time[1];
    for (int i = 0; i < call.time[2]; i++) {
        total += rate[i] * 60;
    }
    return total / 100.0;
}
int main() {
    int rate[25] = {0}, n;
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    scanf("%d", &n);
    vector<record> records(n);
    for (int i = 0; i < n; i++) {
        cin >> records[i].name;
        scanf("%d:%d:%d:%d", &records[i].time[0], &records[i].time[1], &records[i].time[2], &records[i].time[3]);
        string temp;
        cin >> temp;
        if (temp == "on-line") {
            records[i].flag = 1;
        } else if (temp == "off-line") {
            records[i].flag = 2;
        }
        records[i].minutes = records[i].time[1] * 24 * 60 + records[i].time[2] * 60 + records[i].time[3];
    }
    sort(records.begin(), records.end(), cmp_record);
    map<string, vector<record>> custom;
    for (int i = 0; i < n; i++) {
        if (records[i].name == records[i-1].name && records[i-1].flag == 1 && records[i].flag == 2) {
            custom[records[i-1].name].push_back(records[i-1]);
            custom[records[i].name].push_back(records[i]);
            
        }
    }
    for (auto it : custom) {
        vector<record> temp = it.second;
        cout << it.first;
        printf(" %02d\n", temp[0].time[0]);
        double total = 0.0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i], rate) - billFromZero(temp[i-1], rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i-1].time[1], temp[i-1].time[2], temp[i-1].time[3], temp[i].time[1], temp[i].time[2], temp[i].time[3], temp[i].minutes - temp[i-1].minutes, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}