// https://pintia.cn/problem-sets/15/exam/problems/826
#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, a;
    scanf("%d", &k);
    vector<int> l;
    while (scanf("%d", &a), a >= 0) l.push_back(a);
    if (k <= 0 || k > l.size()) printf("NULL");
    else printf("%d", l[l.size() - k]);
    return 0;
}