// https://pintia.cn/problem-sets/994805260223102976/problems/994805305181847552
#include <cstdio>
#include <cstring>
const int maxn = 1010;

int main(){
    char a[maxn];
    int b, r, ans[maxn];
    scanf("%s %d", a, &b);
    int len = strlen(a), cnt = 0, num = 0;
    for (int i = 0; i < len; i++){
        num = 10 * num + (a[i] - '0');
        ans[cnt++] = num / b;
        num = num % b;
    }
   
    int i = 0;
    while(cnt > 1 && ans[i] == 0)
        i++;
    for ( ; i < cnt; i++){
        printf("%d", ans[i]);
    }
    printf(" %d", num);
    
    return 0;
}