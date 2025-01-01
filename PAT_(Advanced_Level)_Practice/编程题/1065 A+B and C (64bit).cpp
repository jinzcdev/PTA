// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805406352654336
#include <cstdio>
int main(){
    int n;
    long long a, b, c, sum;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &a, &b, &c);
        sum = a + b;
        if (a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i);
        } else if (a < 0 && b < 0 && sum >= 0) {
            printf("Case #%d: false\n", i);            
        } else if (a + b > c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);            
        }
    }
    return 0;
}