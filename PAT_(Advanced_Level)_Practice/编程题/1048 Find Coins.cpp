// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805432256675840
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] == m) break;
        else if (a[i] + a[j] < m) i++;
        else j--;
    }
    if (i == j) printf("No Solution");
    else printf("%d %d", a[i], a[j]);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    bool flag = false;
    for (const auto &it : a) {
        if ((m != it * 2 && cnt[m - it] >= 1) || (m == it * 2 && cnt[m - it] >= 2)) {
            printf("%d %d", it, m - it);
            flag = true;
            break;
        }
    }
    if (!flag) printf("No Solution");
    return 0;
}
*/