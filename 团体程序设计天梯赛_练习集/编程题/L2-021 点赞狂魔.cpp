// https://pintia.cn/problem-sets/994805046380707840/problems/994805058485469184
// 5
// bob 11 101 102 103 104 105 106 107 108 108 107 107
// peter 8 1 2 3 4 3 2 5 1
// chris 12 1 2 3 4 5 6 7 8 9 1 2 3
// john 10 8 7 6 5 4 3 2 1 7 5
// jack 9 6 7 8 9 10 11 12 13 14
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
    string name;
    int cnt, num;
};
bool cmp(node &a, node &b) {
    return a.cnt != b.cnt ? a.cnt > b.cnt : a.num < b.num;
}
int main() {
    int n, a;
    scanf("%d", &n);
    vector<node> v(n);
    string str;
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].num;
        unordered_set<int> s;
        for (int j = 0; j < v[i].num; j++) {
            scanf("%d", &a);
            s.insert(a);
        }
        v[i].cnt = s.size();
    }
    sort(v.begin(), v.end(), cmp);
    vector<string> ans;
    for (int i = 0; i < 3; i++) {
        if (i < v.size()) ans.push_back(v[i].name);
        else ans.push_back("-");
    }
    for (int i = 0; i < 3; i++) {
        if (i != 0) printf(" ");
        cout << ans[i];
    }
    return 0;
}