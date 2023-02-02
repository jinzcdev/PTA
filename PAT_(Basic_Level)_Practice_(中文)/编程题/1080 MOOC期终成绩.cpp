// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805261493977088
#include <bits/stdc++.h>
using namespace std;
struct student {
    string id;
    int pgm, mid, final, g;
};
bool cmp(student &a, student &b) {
    return a.g != b.g ? a.g > b.g : a.id < b.id;
}
vector<student> v, ans;
map<string, int> idToInt;
int main() {
    int p, m, n, score, cnt = 0;
    scanf("%d%d%d", &p, &m, &n);
    string id;
    while (p--) {
        cin >> id >> score;
        if (score >= 200) {
            v.push_back({id, score, -1, -1, 0});
            idToInt[id] = cnt++;
        }
    }
    while (m--) {
        cin >> id >> score;
        if (idToInt.find(id) != idToInt.end()) {
            v[idToInt[id]].mid = score;
        }
    }
    while (n--) {
        cin >> id >> score;
        if (idToInt.find(id) != idToInt.end()) {
            int num = idToInt[id];
            v[num].g = v[num].final = score;
            if (v[num].mid > v[num].final) {
                v[num].g = round(v[num].mid * 0.4 + v[num].final * 0.6);
            }
        }
    }
    for (auto it : v) {
        if (it.g >= 60) ans.push_back(it);
    }
    sort(ans.begin(), ans.end(), cmp);
    for (auto it : ans) {
        printf("%s %d %d %d %d\n", it.id.c_str(), it.pgm, it.mid, it.final, it.g);
    }
    return 0;
}