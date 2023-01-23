// https://pintia.cn/problem-sets/994805342720868352/problems/994805389634158592
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int tsize, n, key;
    scanf("%d%d", &tsize, &n);
    while (!isprime(tsize)) tsize++;
    vector<int> hash(tsize);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        int pos, flag = 0;
        for (int j = 0; j < tsize; j++) {
            pos = (key + j * j) % tsize;
            if (hash[pos] == 0) {
                hash[pos] = flag = 1;
                break;
            }
        }
        if (i != 0) printf(" ");
        if (flag) printf("%d", pos);
        else printf("-");
    }
    return 0;
}