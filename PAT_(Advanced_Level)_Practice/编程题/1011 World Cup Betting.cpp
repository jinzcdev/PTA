// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805504927186944
#include <bits/stdc++.h>
using namespace std;
int main() {
    double w, t, l, ans = 1.0;
    for (int i = 0; i < 3; i++) {
        scanf("%lf%lf%lf", &w, &t, &l);
        if (w > t && w > l) printf("W ");
        else if (t > w && t > l) printf("T ");
        else printf("L ");
        ans *= max(w, t > l ? t : l);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}