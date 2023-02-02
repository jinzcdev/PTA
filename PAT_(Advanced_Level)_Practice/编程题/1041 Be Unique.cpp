// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805444361437184
#include <cstdio>
const int maxn = 100010;
int num[maxn], exist[maxn] = {0};

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", num + i);
        exist[num[i]]++;
    }
    int ans = -1;
    for (int i = 0; i < n; i++){
        if (exist[num[i]] == 1){
            ans = num[i];
            break;
        }
    }
    if (ans == -1){
        printf("None");
    } else {
        printf("%d", ans);
    }
    return 0;
}