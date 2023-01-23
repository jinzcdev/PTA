// https://pintia.cn/problem-sets/15/problems/825
#include <bits/stdc++.h>
using namespace std;
int pop(queue<int> &q) {
    int temp = q.front();
    q.pop();
    return temp;
}
int main() {
    int n, a, cnt = 0;
    scanf("%d", &n);
    queue<int> qa, qb;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % 2 != 0) qa.push(a);
        else qb.push(a);
    }
    while (!qa.empty() || !qb.empty()) {
        if (qa.size() >= 2) {
            ans.push_back(pop(qa));
            ans.push_back(pop(qa));
        } else if (qa.size() == 1) {
            ans.push_back(pop(qa));
        }
        if (qb.size() != 0) ans.push_back(pop(qb));
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}