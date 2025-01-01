// https://pintia.cn/problem-sets/14/exam/problems/type/7?problemSetProblemId=797
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, u, d;
    scanf("%d%d%d", &n, &u, &d);
    int i = 0, sumdis = 0;
    for ( ; sumdis < n; i++) {
        if (i % 2 == 0) sumdis += u;
        else sumdis -= d;
    }
    printf("%d", i);
    return 0;
}