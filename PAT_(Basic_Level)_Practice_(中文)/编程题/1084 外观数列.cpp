// https://pintia.cn/problem-sets/994805260223102976/problems/994805260583813120
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int d, n;
    cin >> d >> n;
    vector<int> v{d}, tmp;
    while (--n) {
        int now = v[0], cnt = 0;
        tmp.push_back(now);
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == now) cnt++;
            else {
                now = v[i];
                tmp.push_back(cnt);
                tmp.push_back(now);
                cnt = 1;
            }
        }
        tmp.push_back(cnt);
        v = tmp;
        tmp.clear();
    }
    for (auto it : v) printf("%d", it);
    return 0;
}