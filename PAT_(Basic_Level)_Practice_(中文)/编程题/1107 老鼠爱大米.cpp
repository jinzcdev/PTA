// https://pintia.cn/problem-sets/994805260223102976/exam/problems/1478634461852217344
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> ans, t(m);
    while (n--) {
        for (int i = 0; i < m; i++) scanf("%d", &t[i]);
        ans.push_back(*max_element(t.begin(), t.end()));
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n%d", *max_element(ans.begin(), ans.end()));
    return 0;
}
/* python
n, m = map(int, input().split())
lst = []
while n != 0:
    n -= 1
    a = max(list(map(int, input().split())))
    lst.append(a)
print(*lst)
print(max(lst))
*/