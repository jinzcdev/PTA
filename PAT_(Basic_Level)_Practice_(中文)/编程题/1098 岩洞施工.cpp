// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1478633798962888704
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int main() {
    int n, a, MIN = 9999, MAX = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        MIN = min(a, MIN);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        MAX = max(a, MAX);
    }
    if (MIN > MAX) printf("Yes %d", MIN - MAX);
    else printf("No %d", MAX - MIN + 1);
    return 0;
}