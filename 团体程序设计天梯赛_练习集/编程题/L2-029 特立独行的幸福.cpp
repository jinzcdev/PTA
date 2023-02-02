// https://pintia.cn/problem-sets/994805046380707840/exam/problems/1111914599412858886
// 10 40

// 19 8
// 23 6
// 28 3
// 31 4
// 32 3
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int getsum(int number) {
    int sum = 0;
    while (number != 0) {
        int t = number % 10;
        sum += t * t;
        number /= 10;
    }
    return sum;
}
int main() {
    int a, b, happy[N] = {0};
    scanf("%d%d", &a, &b);
    bool hash[N] = {false};
    vector<int> ans;
    map<int, bool> mp;
    for (int i = a; i <= b; i++) {
        if (hash[i]) continue;
        bool vis[N] = {false}, flag = true;
        vector<int> v;
        int temp = i, cnt = 0;
        while (temp != 1) {
            if (vis[temp]) break;
            cnt++;
            vis[temp] = true;
            v.push_back(temp);
            temp = getsum(temp);
        }
        if (temp == 1) {
            bool flag = true;
            for (auto it : v) {
                hash[it] = true;
                if (mp[it]) {
                    mp.erase(it);
                }
            }
            mp[i] = true;
            // ans.push_back(i);
            happy[i] = cnt;
            if (isprime(i)) happy[i] *= 2;
        }
    }
    for (auto it : mp) {
        if (it.second == true)
        ans.push_back(it.first);
    }
    if (ans.size() == 0) printf("SAD\n");
    for (auto it : ans) {
        printf("%d %d\n", it, happy[it]);
    }
    return 0;
}