// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805271455449088
#include <cstdio>
int main(){
    int n, num[10], ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", num + i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if (j != i) ans += num[i] * 10 + num[j];
        }
    }
    printf("%d", ans);
    return 0;
}
