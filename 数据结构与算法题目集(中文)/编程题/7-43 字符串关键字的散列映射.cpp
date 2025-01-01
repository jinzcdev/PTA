// https://pintia.cn/problem-sets/15/exam/problems/type/7?problemSetProblemId=890
#include <bits/stdc++.h>
using namespace std;
int getHash(string s) {
    int sum = 0, i = s.length() < 3 ? 0 : s.length() - 3;
    for (; i < s.length(); i++) sum = sum * 32 + (s[i] - 'A');
    return sum;
}
int main() {
    int n, size;
    unordered_map<string, bool> vis;
    scanf("%d%d", &n, &size);
    vector<int> hash(size, -1);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int key = getHash(s), pos = -1;
        for (int j = 0; j <= size / 2; j++) {
            pos = (key + j * j) % size;
            if (hash[pos] == key && vis[s]) break;
            if (hash[pos] == -1) {
                hash[pos] = key;
                break;
            }
            pos = (key - j * j) % size;
            if (hash[pos] == key && vis[s]) break;
            if (hash[pos] == -1) {
                hash[pos] = key;
                break;
            }
        }
        vis[s] = true;
        printf("%d", pos);
        if (i != n - 1) printf(" ");
    }
    return 0;
}