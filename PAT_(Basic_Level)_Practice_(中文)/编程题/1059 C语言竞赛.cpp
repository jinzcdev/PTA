// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805269828059136
#include <cstdio>
const int maxn = 10010;
int rank[maxn];
bool vis[maxn] = {false};
bool isPrime(int x){
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}
int main(){
    int n, k, id;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &id);
        rank[id] = i;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &id);
        if (rank[id] == 0) printf("%04d: Are you kidding?\n", id);
        else if (vis[id]) printf("%04d: Checked\n", id);
        else {
            vis[id] = true;
            if (rank[id] == 1) printf("%04d: Mystery Award\n", id);
            else if (isPrime(rank[id])) printf("%04d: Minion\n", id);
            else printf("%04d: Chocolate\n", id);
        }
    }
    return 0;
}