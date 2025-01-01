// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805454989803520
#include <cstdio>
#include <cstring>
const int maxn = 1010;

struct node{
    char name[20],pwd[20];
    bool isChanged;
}user[maxn];

void checkPwd(node& t, int& cnt){
    int len = strlen(t.pwd);
    for (int i = 0; i < len; i++){
        if(t.pwd[i] == '1'){
            t.pwd[i] = '@';
            t.isChanged = true;
        }else if(t.pwd[i] == '0'){
            t.pwd[i] = '%';
            t.isChanged = true;
        }else if(t.pwd[i] == 'l'){
            t.pwd[i] = 'L';
            t.isChanged = true;
        }else if(t.pwd[i] == 'O'){
            t.pwd[i] = 'o';
            t.isChanged = true;
        }
    }
    if(t.isChanged) cnt++;
}

int main(){
    int n,cnt = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%s %s",user[i].name,user[i].pwd);
        checkPwd(user[i],cnt);
    }
    if(cnt == 0)
        if(n == 1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified",n);
    else{
        printf("%d\n",cnt);
        for (int i = 0; i < n; i++){
            if(user[i].isChanged)
                printf("%s %s\n",user[i].name,user[i].pwd);
        }
    }
    return 0;
}