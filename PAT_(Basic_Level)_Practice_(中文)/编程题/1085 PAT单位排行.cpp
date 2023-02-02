// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805260353126400
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 100010;

map<string,int> mp; 

struct School{
    char name[10];
    float A,B,T;
    int cnt;
    int sum;
} sch[maxn];

bool cmp(School a, School b){
    if(a.sum != b.sum) return a.sum > b.sum;
    else if (a.cnt != b.cnt) return a.cnt < b.cnt;
    else return strcmp(a.name,b.name) < 0;
}

void toLower(char *str){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char id[10],name[10];
    int score,cnt = 0;
    for (int i = 0; i < n; i++){
        scanf("%s%d%s", id, &score, name);
        toLower(name);
        int pos = mp[name];
        if(pos == 0){
            pos = ++cnt;
            strcpy(sch[pos].name,name);
            mp[name] = pos;
        }
        char temp = id[0];
        if(temp == 'A') sch[pos].A += score;
        else if(temp == 'B') sch[pos].B += score;
        else if(temp == 'T') sch[pos].T += score;
        sch[pos].cnt++;        
    }

    for (int i = 1; i <= cnt; i++){
        sch[i].sum = (int)(sch[i].B / 1.5 + sch[i].A + sch[i].T * 1.5);
    }
    
    sort(sch + 1, sch + cnt + 1, cmp);

    printf("%d\n",cnt);
    int k = 1;
    for (int i = 1; i <= cnt; i++){
        if(i > 1 && sch[i].sum == sch[i - 1].sum){
            printf("%d %s %d %d\n", k, sch[i].name, sch[i].sum, sch[i].cnt);
        }else{
            k = i;
            printf("%d %s %d %d\n", k, sch[i].name, sch[i].sum, sch[i].cnt);
        }
    }
    return 0;
}