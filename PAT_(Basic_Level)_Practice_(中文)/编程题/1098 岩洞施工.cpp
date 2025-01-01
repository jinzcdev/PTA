// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1478633798962888704
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
    int n, x;
    vector<int> v1, v2;
    scanf("%d", &n);
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.insert(x);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        b.insert(x);
    }
    for (auto it : a) v1.push_back(it);
    for (auto it : b) v2.push_back(it);
    if (v1[0] > v2[v2.size() - 1]) {
        printf("Yes %d", v1[0] - v2[v2.size() - 1]);
    } else {
        printf("No %d", v2[v2.size() - 1] - v1[0] + 1);
    }
    return 0;
}