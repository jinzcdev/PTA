// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=1729419732192542723
#include <bits/stdc++.h>
using namespace std;
int N, M, K, num, used[101], ans[101];
vector<int> pro, temp;
vector<vector<int>> equa[101];
string s;
bool cmp(const vector<int> &a, const vector<int> &b) {
    for (int i = 0;; i++)
        if (a[i] != b[i]) return a[i] < b[i];
}
void dfs(int x) {
    if (x == M) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < equa[pro[i]][ans[i]].size(); j++) {
                if (j != 0) cout << " + ";
                cout << setw(2) << setfill('0') << equa[pro[i]][ans[i]][j];
            }
            cout << " -> " << setw(2) << setfill('0') << pro[i] << "\n";
        }
        exit(0);
    }
    for (int i = 0; i < equa[pro[x]].size(); i++) {
        int flag = 1;
        vector<int> A = equa[pro[x]][i];
        for (auto it : A)
            if (used[it] != 1) {
                flag = 0;
                break;
            }
        if (flag == 0) continue;
        for (auto it : A) used[it] = 2;
        ans[x] = i;
        dfs(x + 1);
        for (auto it : A) used[it] = 1;
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        used[num] = 1;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        if (used[num] == 1) equa[num].push_back({num});
        pro.push_back(num);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        temp.clear();
        while (cin >> num >> s) {
            temp.push_back(num);
            if (s == "->") {
                cin >> num;
                equa[num].push_back(temp);
                break;
            }
        }
    }
    for (int i = 0; i < M; i++)
        sort(equa[pro[i]].begin(), equa[pro[i]].end(), cmp);
    dfs(0);
    return 0;
}