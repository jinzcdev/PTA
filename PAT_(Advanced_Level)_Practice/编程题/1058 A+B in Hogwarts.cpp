// https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232
#include <cstdio>
int a[3] = {0}, b[3] = {0};
int d[3] = {10, 17, 29};
int main(){
    scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
    scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
    int ans[3], k;
    ans[2] = (a[2] + b[2]) % 29;
    k = (a[2] + b[2]) / 29;
    ans[1] = (a[1] + b[1] + k) % 17;
    k = (a[1] + b[1] + k) / 17;
    ans[0] = a[0] + b[0] + k;
    printf("%d.%d.%d", ans[0], ans[1], ans[2]);
    return 0;
}