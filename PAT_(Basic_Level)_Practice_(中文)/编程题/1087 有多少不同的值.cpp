// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1038429191091781632
#include <cstdio>
const int maxn = 15000;
int ans[maxn] = {0};

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int x = i / 2 + i / 3 + i / 5;
        ans[x] = ans[x] + 2;
    }
    int cnt = 0;
    for (int i = 0; i < maxn; i++){
        if (ans[i] >= 2)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}