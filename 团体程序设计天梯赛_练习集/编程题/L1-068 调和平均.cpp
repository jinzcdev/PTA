// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1336215880692482051
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    double a, sum = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a);
        sum += 1.0 / a;
    }
    printf("%.2f", n / sum);
    return 0;
}