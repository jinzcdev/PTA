// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805277163896832
#include <iostream>
#include <map>
using namespace std;
int main() {
    int n, team, score;
    map<int, int> mp;
    cin >> n;
    while (n--) {
        scanf("%d-%*d %d", &team, &score);
        mp[team] += score;
    }
    int ans, max = -1;
    for (auto it : mp) {
        if (it.second > max) {
            max = it.second;
            ans = it.first;
        }
    }
    printf("%d %d", ans, mp[ans]);
    return 0;
}