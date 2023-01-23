// https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
const int maxn = 10010;
struct stu {
    string id;
    int score;
    stu (string _id, int _score) {
        id = _id;
        score = _score;
    }
};
vector<stu> S, ans;

bool cmp1(stu a, stu b) {
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
        // stu student = {id, score};
        S.push_back(stu(id, score));
    }
    int type;
    string k;
    
    for (int i = 1; i <= m; i++) {
        ans.clear();
        cin >> type >> k;
        printf("Case %d: %d %s\n", i, type, k.c_str());
        if (type == 1) {
            for (auto it : S) {
                if (it.id[0] == k[0]) {
                    ans.push_back(it);
                }
            }
        } else if (type == 2) {
            int cnt = 0, sum = 0;
            for (auto it : S) {
                if (it.id.substr(1, 3) == k) {
                    cnt++;
                    sum += it.score;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
            else {
                printf("NA\n");
            }
            continue;
        } else {
            unordered_map<string, int> m;
            for (auto it : S) {
                if (it.id.substr(4, 6) == k) {
                    m[it.id.substr(1, 3)]++;
                }
            }            
            for (auto it : m) {
                ans.push_back(stu(it.first, it.second));
            }
        }
        if (ans.size() == 0) printf("NA\n");
        else {
            sort(ans.begin(), ans.end(), cmp1);
            for (auto it : ans) {
                printf("%s %d\n", it.id.c_str(), it.score);
            }
        }
    }
    return 0;
}