// https://pintia.cn/problem-sets/17/problems/263
#include <cstdio>
#include <cstring>
const int maxn = 25;
char N[maxn];
int hashTable[10] = {0}, ans[maxn];

int main(){
    scanf("%s", N);
    int cnt = 0, len = strlen(N), k = 0;
    for(int i = len - 1; i >= 0; i--){
        hashTable[N[i] - '0']++;
        int temp = (N[i] - '0') * 2 + k;
        ans[cnt++] = temp % 10;
        k = temp / 10;
    }
    if (k != 0) ans[cnt++] = k;
    bool flag = true;
    for(int i = 0; i < cnt; i++){
        if (--hashTable[ans[i]] < 0) {
            flag = false;
            break;
        }
    }
    if (flag) printf("Yes\n");
    else printf("No\n");
    for(int i = cnt - 1; i >= 0; i--){
        printf("%d", ans[i]);
    }
    return 0;
}