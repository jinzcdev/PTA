// https://pintia.cn/problem-sets/14/problems/798
#include <bits/stdc++.h>
using namespace std;
vector<double> v(4);
double f(double x) {
    double ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans = ans * x + v[i];
    return ans;
}
int main() {
    double a, b;
    for (int i = 0; i < 4; i++) {
        scanf("%lf", &v[i]);
    }
    scanf("%lf%lf", &a, &b);
    bool flag = false;
    while (b - a >= 0.001) {
        double left = f(a), right = f(b), mid = (a + b) / 2;
        if (f(mid) == 0) {
            flag = true;
            break;
        } else if (f(mid) * f(a) > 0) a = mid;
        else if (f(mid) * f(b) > 0) b = mid;
    }
    printf("%.2f", (a + b) / 2);
    return 0;
}