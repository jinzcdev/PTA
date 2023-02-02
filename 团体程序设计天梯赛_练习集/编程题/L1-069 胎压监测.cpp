// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1336215880692482052
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[5] = {0}, high, threshold, MAX = -1;
    vector<int> v;
    for (int i = 1; i <= 4; i++) {
        scanf("%d", &a[i]);
        MAX = max(MAX, a[i]);
    }
    scanf("%d%d", &high, &threshold);
    for (int i = 1; i <= 4; i++) {
        if (abs(a[i] - MAX) > threshold || a[i] < high) {
            v.push_back(i);
        }
    }
    if (v.size() == 0) printf("Normal\n");
    else if (v.size() == 1) printf("Warning: please check #%d!\n", v[0]);
    else printf("Warning: please check all the tires!\n");
    return 0;
}