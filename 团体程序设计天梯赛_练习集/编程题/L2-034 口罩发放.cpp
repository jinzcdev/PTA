// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1336215880692482057
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name, id, time;
    int status, day, num;
};
bool cmp(node &a, node &b) {
    return a.time != b.time ? a.time < b.time : a.num < b.num;
}
bool isalldigit(string s) {
    for (int i = 0; i < s.length(); i++)
        if (!isdigit(s[i])) return false;
    return true;
}
int main() {
    int d, p, n, status, hh, mm, t, s, num = 1;
    string name, id, time;
    vector<node> ans;
    unordered_map<string, bool> vis;
    unordered_map<string, int> last;
    scanf("%d%d", &d, &p);
    for (int i = 1; i <= d; i++) {
        scanf("%d%d", &t, &s);
        vector<node> v;
        for (int j = 1; j <= t; j++) {
            cin >> name >> id >> status >> time;
            if (id.length() != 18 || !isalldigit(id)) continue;
            if (status == 1 && !vis[id]) {
                ans.push_back({name, id});
                vis[id] = true;
            }
            v.push_back({name, id, time, status, i, j});
        }
        sort(v.begin(), v.end(), cmp);
        int cnt = 0;
        for (int j = 0; cnt < s && j < v.size(); j++) {
            if (last[v[j].id] == 0 || i - last[v[j].id] >= p + 1) {
                last[v[j].id] = i;
                cnt++;
                cout << v[j].name << " " << v[j].id << endl;
            }
        }
    }
    for (auto it : ans) {
        cout << it.name << " " << it.id << endl;
    }
    return 0;
}
