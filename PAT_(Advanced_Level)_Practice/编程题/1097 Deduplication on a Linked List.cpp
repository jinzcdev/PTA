// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805369774129152
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
    int address, data, next;
    int order, flag;
} L[maxn];
int mp[maxn] = {-1};

bool cmp(node a, node b){
    if (a.flag != b.flag)
        return a.flag > b.flag;
    else
        return a.order < b.order;
}

int main(){
    for (int i = 0; i < maxn; i++){
        L[i].flag = -1;
        mp[i] = -1;
        L[i].order = maxn;
    }
    int begin, n;
    scanf("%d%d", &begin, &n);
    for (int i = 0; i < n; i++){
        int address;
        scanf("%d", &address);
        scanf("%d%d", &L[address].data, &L[address].next);
        L[address].address = address;
    }

    int cnt = 0, num = 0;
    for (int p = begin; p != -1; p = L[p].next){
        int data = L[p].data >= 0 ? L[p].data : -L[p].data;
        if (mp[data] == -1){
            mp[data] = 1;
            L[p].flag = 1;
        }else if(mp[data] == 1 || mp[data] == 0){
            mp[data] = 0;
            L[p].flag = 0;
            num++;
        }
        L[p].order = cnt++;
    }

    sort(L, L + maxn, cmp);
    for (int i = 0; i < cnt; i++){
        if (i == cnt - num - 1 || i == cnt - 1){
            printf("%05d %d -1\n", L[i].address, L[i].data);
        }else{
            printf("%05d %d %05d\n", L[i].address, L[i].data, L[i + 1].address);
        }
    }
    
    return 0;
}

