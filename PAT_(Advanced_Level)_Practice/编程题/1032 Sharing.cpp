// https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920
#include <cstdio>
const int maxn = 100010;
struct node{
    char data;
    int next;
    bool flag;
} L[maxn];

int main(){
    for (int i = 0; i < maxn; i++){
        L[i].flag = false;
    }
    int begin1, begin2, n;
    scanf("%d%d%d", &begin1, &begin2, &n);
    for (int i = 0; i < n; i++){
        int address;
        scanf("%d", &address);
        getchar();
        scanf("%c %d", &L[address].data, &L[address].next);
    }
    for (int p = begin1; p != -1; p = L[p].next){
        L[p].flag = true;
    }
    
    int p = begin2;
    while (p != -1){
        if (L[p].flag == true)
            break;
        p = L[p].next;
    }
    if (p != -1)
        printf("%05d", p);
    else
        printf("-1");
    return 0;
}