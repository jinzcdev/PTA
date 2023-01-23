// https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928
#include <bits/stdc++.h>
using namespace std;
struct stu {
    string id;
    int score;
};
vector<stu> v, ans;
bool cmp(stu a, stu b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}
int main() {
    int n, m, score, type;
    scanf("%d%d", &n, &m);
    string id, k;
    for (int i = 0; i < n; i++) {
        cin >> id >> score;
        v.push_back({id, score});
    }
    for (int i = 1; i <= m; i++) {
        ans.clear();
        cin >> type >> k;
        printf("Case %d: %d %s\n", i, type, k.c_str());
        if (type == 1) {
            for (auto it : v)
                if (it.id[0] == k[0]) ans.push_back(it);
        } else if (type == 2) {
            int cnt = 0, sum = 0;
            for (auto it : v) {
                if (it.id.substr(1, 3) == k) {
                    cnt++;
                    sum += it.score;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
            else printf("NA\n");
            continue;
        } else {
            unordered_map<string, int> m;
            for (auto it : v) {
                if (it.id.substr(4, 6) == k)
                    m[it.id.substr(1, 3)]++;
            }
            for (auto it : m) ans.push_back({it.first, it.second});
        }
        if (ans.size() == 0) printf("NA\n");
        else {
            sort(ans.begin(), ans.end(), cmp);
            for (auto it : ans) printf("%s %d\n", it.id.c_str(), it.score);
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
struct node {
    string id;
    int score;
};
bool cmp(node &a, node &b) {
    if (a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}
int main() {
    int n, m, t;
    string id, key;
    scanf("%d%d", &n, &m);
    vector<node> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].id >> v[i].score;
    sort(v.begin(), v.end(), cmp);
    for (int i = 1; i <= m; i++) {
        cin >> t >> key;
        printf("Case %d: %d %s\n", i, t, key.c_str());
        vector<node> ans;
        if (t == 1) {
            for (auto it : v)
                if (it.id[0] == key[0]) ans.push_back(it);
        } else if (t == 2) {
            int sum = 0, cnt = 0;
            for (auto it : v) {
                if (it.id.substr(1, 3) == key) {
                    cnt++;
                    sum += it.score;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
            else printf("NA\n");
        } else {
            unordered_map<string, int> mp;
            for (auto it : v)
                if (it.id.substr(4, 6) == key) mp[it.id.substr(1, 3)]++;
            for (auto it : mp) ans.push_back({it.first, it.second});
        }
        if (t != 2 && ans.size() == 0) printf("NA\n");
        else {
            sort(ans.begin(), ans.end(), cmp);
            for (auto it : ans) {
                printf("%s %d\n", it.id.c_str(), it.score);
            }
        }
    }
    return 0;
}
*/