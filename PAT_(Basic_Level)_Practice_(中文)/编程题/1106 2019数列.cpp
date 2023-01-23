// https://pintia.cn/problem-sets/994805260223102976/problems/1478634404943273984
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[] = {2, 0, 1, 9};
    cin >> n;
    vector<int> v;
    for (int i = 0; i < 4; i++) v.push_back(a[i]);
    for (int i = 0; i < 1010; i++) {
        int end = v.size() - 1, sum = 0;
        for (int j = 0; j < 4; j++) sum += v[end - j];
        v.push_back(sum % 10);
    }
    for (int i = 0; i < n; i++) printf("%d", v[i]);
    return 0;
}