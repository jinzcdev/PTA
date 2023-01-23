// https://pintia.cn/problem-sets/14/problems/784
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    vector<int> v;
    scanf("%d", &a);
    if (a == 0)  {
        printf("0");
        return 0;
    }
    while (a != 0) {
        v.push_back(a % 16);
        a /= 16;
    }
    for (int i = v.size() - 1; i >= 0; i--) printf("%d", v[i]);
    return 0;
}
