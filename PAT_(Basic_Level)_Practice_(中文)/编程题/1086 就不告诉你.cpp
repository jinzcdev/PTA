// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1038429065476579328
#include <cstdio>
const int maxn = 1000000;
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    int rs = a * b;
    if (rs == 0){
        printf("0");
    }else{
        int ans[maxn];
        int len = 0;
        while (rs != 0){
            ans[len++] = rs % 10;
            rs = rs / 10;
        }
        int i = 0;
        while (ans[i] == 0){
            i++;
        }
        for ( ; i < len; i++){
            printf("%d", ans[i]);
        }
    }
    return 0;
}