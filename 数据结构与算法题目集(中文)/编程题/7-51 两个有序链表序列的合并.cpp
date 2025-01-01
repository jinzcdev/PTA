// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=2992
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    vector<int> v;
    while (scanf("%d", &x), x != -1) v.push_back(x);
    while (scanf("%d", &x), x != -1) v.push_back(x);
    sort(v.begin(), v.end());
    if (v.size() == 0) printf("NULL");
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    return 0;
}