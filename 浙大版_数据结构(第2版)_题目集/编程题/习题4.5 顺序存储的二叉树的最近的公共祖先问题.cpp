// https://pintia.cn/problem-sets/434/exam/problems/6180
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int main() {
    int n, a, b, t[N] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
    scanf("%d%d", &a, &b);
    if (t[a] == 0 || t[b] == 0) {
        printf("ERROR: T[%d] is NULL\n", t[a] == 0 ? a : b);
        return 0;
    }
    vector<int> p1, p2;
    for (int i = a; i >= 1; i /= 2) p1.push_back(i);
    for (int i = b; i >= 1; i /= 2) p2.push_back(i);
    reverse(p1.begin(), p1.end());
    reverse(p2.begin(), p2.end());
    int i = 0;
    while (i < min(p1.size(), p2.size()) && p1[i] == p2[i]) i++;
    printf("%d %d\n", p1[i - 1], t[p1[i - 1]]);
    return 0;
}