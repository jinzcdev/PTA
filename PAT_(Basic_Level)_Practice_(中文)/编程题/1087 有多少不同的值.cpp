// https://pintia.cn/problem-sets/994805260223102976/problems/1038429191091781632
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cnt = 0, vis[30010] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp = i / 2 + i / 3 + i / 5;
        if (!vis[tmp]) {
            vis[tmp] = 1;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}