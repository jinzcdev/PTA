// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805343236767744
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int msize, n, m, key;
    scanf("%d%d%d", &msize, &n, &m);
    while (!isPrime(msize)) msize++;
    vector<int> hash(msize), v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        bool isfound = false;
        for (int j = 0; j < msize; j++) {
            int pos = (key + j * j) % msize;
            if (hash[pos] == 0) {
                hash[pos] = key;
                isfound = true;
                break;
            }
        }
        if (!isfound) printf("%d cannot be inserted.\n", key);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &key);
        bool flag = false;
        for (int j = 0; j < msize; j++) {
            cnt++;
            int pos = (key + j * j) % msize;
            if (hash[pos] == key || hash[pos] == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) cnt++;
    }
    printf("%.1lf", cnt * 1.0 / m);
    return 0;
}