// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1071786104348536832
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
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
    int n, m;
    scanf("%d%d", &n, &m);
    string id;
    int score;
    for (int i = 0; i < n; i++) {
        cin >> id >> score;
        v.push_back({id, score});
    }
    int type;
    string k;
    
    for (int i = 1; i <= m; i++) {
        ans.clear();
        cin >> type >> k;
        printf("Case %d: %d %s\n", i, type, k.c_str());
        if (type == 1) {
            for (auto it : v) {
                if (it.id[0] == k[0]) {
                    ans.push_back(it);
                }
            }
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
                if (it.id.substr(4, 6) == k) {
                    m[it.id.substr(1, 3)]++;
                }
            }            
            for (auto it : m) {
                ans.push_back({it.first, it.second});
            }
        }
        if (ans.size() == 0) printf("NA\n");
        else {
            sort(ans.begin(), ans.end(), cmp);
            for (auto it : ans) {
                printf("%s %d\n", it.id.c_str(), it.score);
            }
        }
    }
    return 0;
}