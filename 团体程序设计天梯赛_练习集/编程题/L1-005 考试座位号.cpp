// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805140211482624
#include <bits/stdc++.h>
using namespace std;
struct node {
    string id;
    int pos;
};
int main() {
    int n, m, a, b;
    string id;
    scanf("%d", &n);
    vector<node> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> id >> a >> b;
        v[a].id = id;
        v[a].pos = b;
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &a);
        printf("%s %d\n", v[a].id.c_str(), v[a].pos);
    }
    return 0;
}