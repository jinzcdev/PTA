// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805478658260992
#include <cstdio>
#include <cstring>
const int maxn = 25;
int hashTable[10] = {0};

int main(){
    char n[maxn];
    int ans[maxn];
    scanf("%s", n);
    int len = strlen(n), cnt = 0, k = 0, temp;
    for (int i = len - 1; i >= 0; i--){
        hashTable[n[i] - '0']++;
        temp = (n[i] - '0') * 2;
        ans[cnt++] = temp % 10 + k;     // 计算个数(加上上一位计算的进位值)
        k = temp / 10;                  // 计算进位
    }
    if (k != 0){
        ans[cnt++] = k;
    }
    bool flag = true;
    int s = cnt - 1;
    while (ans[s] == 0){
        s--;
    }
    for (int i = s; i >= 0; i--){
        if (--hashTable[ans[i]] < 0) {
            flag = false;
            break;
        }
    }
    if (!flag){
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    for (int i = s; i >= 0; i--){
        printf("%d", ans[i]);       
    }
    return 0;
}