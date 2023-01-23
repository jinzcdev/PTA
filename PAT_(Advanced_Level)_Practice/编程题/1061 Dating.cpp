// https://pintia.cn/problem-sets/994805342720868352/problems/994805411985604608
#include <cstdio>
#include <cstring>
char week[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int getMin(int a, int b)
{
    return a >= b ? b : a;
}

int main(){
    char str[4][70];
    for (int i = 0; i < 4; i++)
        scanf("%s", str[i]);
    int i, len1 = getMin(strlen(str[0]), strlen(str[1])),
           len2 = getMin(strlen(str[2]), strlen(str[3]));

    for (i = 0; i < len1; i++){
        if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G'){
            printf("%s ", week[str[0][i] - 'A']);
            break;
        }
    }

    for (i++; i < len1; i++){
        if (str[0][i] == str[1][i]){
            if(str[0][i] >= '0' && str[0][i] <= '9'){
                printf("%02d:",str[0][i] - '0');
                break;
            }else if(str[0][i] >= 'A' && str[0][i] <= 'N'){
                printf("%02d:",str[0][i] - 'A' + 10);
                break;
            }
        }
    }

    for(i = 0; i < len2; i++){
        if(str[2][i] == str[3][i]){
            if((str[2][i] >= 'a' && str[3][i] <= 'z') || (str[2][i] >= 'A' && str[3][i] <= 'Z')){
                printf("%02d",i);
                break;
            }
        }
    }

    return 0;
}