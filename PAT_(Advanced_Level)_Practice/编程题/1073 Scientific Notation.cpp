// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805395707510784
#include <cstdio>
#include <cstring>

int main(){
    char str[10010];
    scanf("%s",str);
    int len = strlen(str);

    if(str[0] == '-') printf("-");
    int exp = 0,pos = 0;
    while(str[pos] != 'E'){
        pos++;
    }
    // 取得指数值
    for (int i = pos + 2; i < len; i++){
        exp = exp * 10 + str[i] - '0';
    }
    if(exp == 0){
        for (int i = 1; i < pos; i++){
            printf("%c",str[i]);
        }
    }

    if(str[pos + 1] == '-'){
        printf("0.");
        for (int i = 0; i < exp - 1; i++)
            printf("0");
        for (int i = 1; i < pos; i++){
            if(i == 2) continue;
            printf("%c",str[i]);
        }
    }else{
        for (int i = 1; i < pos; i++){
            if(str[i] == '.') continue;
            printf("%c",str[i]);
            if(i == exp + 2 && pos - 3 != exp){
                printf(".");
            }
        }
        for (int i = 0; i < exp - (pos - 3); i++){
            printf("0");
        }
    }
    return 0;
}