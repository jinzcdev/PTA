// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805273284165632
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d, k, a = 0, b = 0;
    double e, temp;
    scanf("%d%lf%d", &n, &e, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        int cnt = 0;
        bool mayEmpty = false;
        for (int j = 0; j < k; j++) {
            scanf("%lf", &temp);
            if (temp < e && ++cnt > k / 2) mayEmpty = true;
        }
        if (mayEmpty && k > d) b++;
        else if (mayEmpty) a++;
        
    }
    printf("%.1f%% %.1f%%", a * 100.0 / n, b * 100.0 / n);
    return 0;
}