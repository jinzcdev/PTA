// https://pintia.cn/problem-sets/994805046380707840/problems/994805102173339648
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double a, b;
    while (n--) {
        scanf("%lf%lf", &a, &b);
        double avg = (a - 100.0) * 0.9 * 2;
        double fab = fabs(b - avg);
        if (fab < avg * 0.1) printf("You are wan mei!\n");
        else if (b <= (avg * 0.9)) printf("You are tai shou le!\n");
        else printf("You are tai pang le!\n");
    }
    return 0;
}