// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1038429286185074688
#include <cmath>
#include <iostream>
using namespace std;
int m;
string judge(double x) {
    if (m == x) return "Ping";
    else if (m > x) return "Gai";
    else return "Cong";
}
int main() {
    int x, y, jia = 0, yi = 0;
    scanf("%d%d%d", &m, &x, &y);
    bool flag = false;
    for (jia = 99; jia >= 10; jia--) {
        yi = (jia % 10) * 10 + jia / 10;
        if (y * abs(jia - yi) == x * yi) {
            flag = true;
            break;
        }
    }
    if (!flag) printf("No Solution\n");
    else {
        double bing = yi * 1. / y;
        printf("%d %s %s %s", jia, judge(jia).c_str(), judge(yi).c_str(), judge(bing).c_str());
    }
    return 0;
}