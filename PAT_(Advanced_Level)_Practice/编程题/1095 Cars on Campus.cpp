// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805371602845696
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int time, flag = 0;
};
bool cmp1(node a, node b) {
    if (a.name != b.name)
        return a.name < b.name;
    else
        return a.time < b.time;
}
bool cmp2(node a, node b) { return a.time < b.time; }
int main() {
    int n, k, maxtime = -1, tempindex = 0;
    int hh, mm, ss;
    scanf("%d%d\n", &n, &k);
    vector<node> record(n), car;
    for (int i = 0; i < n; i++) {
        string status;
        cin >> record[i].name;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> status;
        record[i].time = hh * 3600 + mm * 60 + ss;
        record[i].flag = (status == "in" ? 1 : -1);
    }
    sort(record.begin(), record.end(), cmp1);
    map<string, int> mapp;
    for (int i = 0; i < n - 1; i++) {
        if (record[i].name == record[i + 1].name && record[i].flag == 1 &&
            record[i + 1].flag == -1) {
            car.push_back(record[i]);
            car.push_back(record[i + 1]);
            mapp[record[i].name] += (record[i + 1].time - record[i].time);
            if (maxtime < mapp[record[i].name]) {
                maxtime = mapp[record[i].name];
            }
        }
    }
    sort(car.begin(), car.end(), cmp2);
    vector<int> cnt(n);
    for (int i = 0; i < car.size(); i++) {
        if (i == 0)
            cnt[i] += car[i].flag;
        else
            cnt[i] = cnt[i - 1] + car[i].flag;
    }
    for (int i = 0; i < k; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh * 3600 + mm * 60 + ss;
        int j = tempindex;
        for (; j < car.size(); j++) {
            if (car[j].time > time) {
                printf("%d\n", cnt[j - 1]);
                break;
            } else if (j == car.size() - 1) {
                printf("%d\n", cnt[j]);
            }
        }
        tempindex = j;
    }
    for (auto it : mapp) {
        if (it.second == maxtime) printf("%s ", it.first.c_str());
    }
    printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60,
           maxtime % 60);
    return 0;
}