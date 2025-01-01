// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805425780670464
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
    int address, data, next;
    bool flag;
} L[maxn];

bool cmp(node a, node b){
    if (!a.flag || !b.flag){
        return a.flag > b.flag;
    }else{
        return a.data < b.data;
    }
}

int main(){
    for (int i = 0; i < maxn; i++){
        L[i].flag = false;
    }
    int n, begin;
    scanf("%d%d", &n, &begin);
    for (int i = 0; i < n; i++){
        int address;
        scanf("%d", &address);
        scanf("%d%d", &L[address].data, &L[address].next);
        L[address].address = address;
    }
    int cnt = 0;
    for (int p = begin; p != -1; p = L[p].next){
        L[p].flag = true;
        cnt++;
    }

    if (cnt == 0){
        printf("0 -1");
    }else{
        sort(L, L + maxn, cmp);
        printf("%d %05d\n", cnt, L[0].address);
        bool flag = false;
        for (int i = 0; i < cnt; i++){
            if (!flag){
                printf("%05d %d ", L[i].address, L[i].data);
                flag = true;
            }else{
                printf("%05d\n%05d %d ", L[i].address, L[i].address, L[i].data);
            }
        }
        printf("-1");
    }
    return 0;
}
