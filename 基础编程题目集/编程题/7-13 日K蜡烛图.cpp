// https://pintia.cn/problem-sets/14/problems/793
#include <bits/stdc++.h>
using namespace std;
int main() {
    double open, high, low, close;
    scanf("%lf%lf%lf%lf", &open, &high, &low, &close);
    if (close == open) printf("R-Cross");
    else printf("%s", close < open ? "BW-Solid" : "R-Hollow");
    bool ls = (low < open && low < close), us = (high > open && high > close);
    if (ls || us) {
        printf(" with ");
        if (ls && us) printf("Lower Shadow and Upper Shadow");
        else printf("%s", ls ? "Lower Shadow" : "Upper Shadow");
    }
    return 0;
}