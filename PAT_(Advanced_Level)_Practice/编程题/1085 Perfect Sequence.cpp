// https://pintia.cn/problem-sets/994805342720868352/problems/994805381845336064
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn], n, p;

int binarySearch(int i, long long x) {
    if (a[n - 1] <= x) return n;
    int l = i + 1, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int j = binarySearch(i, (long long)a[i] * p);
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
    return 0;
}