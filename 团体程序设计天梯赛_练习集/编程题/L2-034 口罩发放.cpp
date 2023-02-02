// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1336215880692482057
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name, id, time;
    int status, num;
};
bool cmp(node &a, node &b) { return tie(a.time, a.num) < tie(b.time, b.num); }
bool isvalid(string s) {
    if (s.length() != 18) return false;
    for (int i = 0; i < s.length(); i++)
        if (!isdigit(s[i])) return false;
    return true;
}
int main() {
    int d, p, status, t, s;
    string name, id, time;
    vector<node> ans;
    unordered_map<string, int> last, vis;
    scanf("%d%d", &d, &p);
    for (int i = 1; i <= d; i++) {
        scanf("%d%d", &t, &s);
        vector<node> a;
        for (int j = 1; j <= t; j++) {
            cin >> name >> id >> status >> time;
            if (!isvalid(id)) continue;
            if (status == 1 && !vis[id]) {
                ans.push_back({name, id});
                vis[id] = 1;
            }
            a.push_back({name, id, time, status, j});
        }
        sort(a.begin(), a.end(), cmp);
        for (int j = 0, cnt = 0; cnt < s && j < a.size(); j++) {
            if (last[a[j].id] == 0 || i - last[a[j].id] >= p + 1) {
                cout << a[j].name << " " << a[j].id << endl;
                last[a[j].id] = i;
                cnt++;
            }
        }
    }
    for (auto it : ans) cout << it.name << " " << it.id << endl;
    return 0;
}
