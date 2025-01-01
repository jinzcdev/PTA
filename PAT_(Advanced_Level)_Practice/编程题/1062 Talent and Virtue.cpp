// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805410555346944
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Man{
    char id[10];
    int virtue,talent,sum;
    int type;
}man[100010];

bool cmp(Man a,Man b){
    if(a.type != b.type) return a.type < b.type;
    else if(a.sum != b.sum) return a.sum > b.sum;
    else if(a.virtue != b.virtue) return a.virtue > b.virtue;
    else return strcmp(a.id,b.id) < 0;
}

int main(){
    int n,L,H;
    scanf("%d%d%d",&n,&L,&H);
    int m = n;
    for (int i = 0; i < n; i++){
        scanf("%s %d %d",man[i].id,&man[i].virtue,&man[i].talent);
        man[i].sum = man[i].virtue + man[i].talent;
        if(man[i].virtue < L || man[i].talent < L){
            man[i].type = 5;
            m--;
            continue;
        }
        if(man[i].virtue >= H && man[i].talent >= H) man[i].type = 1;
        else if(man[i].virtue >= H && man[i].talent < H) man[i].type = 2;
        else if(man[i].virtue >= man[i].talent) man[i].type = 3;
        else man[i].type = 4;
    }
    sort(man,man + n,cmp);
    printf("%d\n",m);
    for (int i = 0; i < m; i++){
        printf("%s %d %d\n",man[i].id,man[i].virtue,man[i].talent);
    }
    return 0;
}