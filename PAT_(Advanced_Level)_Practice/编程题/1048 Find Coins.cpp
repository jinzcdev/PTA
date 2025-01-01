// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805432256675840
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];
void twoPointers(int n, int m) {
    int i = 0, j = n - 1;
    while(i < j) {
        if(a[i] + a[j] == m) break;
        else if(a[i] + a[j] < m) i++;
        else j--;
    }
    if(i < j) printf("%d %d\n", a[i], a[j]);
    else printf("No Solution\n");
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    twoPointers(n, m);
    return 0;
}