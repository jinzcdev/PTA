// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805345401028608
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int gp, gm, gf, g;
};
bool cmp(node a, node b) { return a.g != b.g ? a.g > b.g : a.name < b.name; }
int main() {
    int p, m, n;
    scanf("%d%d%d", &p, &m, &n);
    map<string, int> sid;
    vector<node> stu(10010), ans;
    string name;
    int grade, pos = 1;
    for (int i = 0; i < p; i++) {
        cin >> name >> grade;
        if (grade < 200) continue;
        stu[pos] = {name, grade, -1, -1, 0};
        sid[name] = pos++;
    }
    for (int i = 0; i < m; i++) {
        cin >> name >> grade;
        if (sid[name] == 0) continue;
        stu[sid[name]].gm = grade;
    }
    for (int i = 0; i < n; i++) {
        cin >> name >> grade;
        if (sid[name] == 0) continue;
        stu[sid[name]].gf = grade;
    }
    for (int i = 1; i < pos; i++) {
        stu[i].g = stu[i].gf;
        if (stu[i].gm > stu[i].gf) {
            stu[i].g = round(stu[i].gm * 0.4 + stu[i].gf * 0.6);
        }
        if (stu[i].g >= 60) ans.push_back(stu[i]);
    }
    sort(ans.begin(), ans.end(), cmp);
    for (auto it : ans) {
        printf("%s %d %d %d %d\n", it.name.c_str(), it.gp, it.gm, it.gf, it.g);
    }
    return 0;
}