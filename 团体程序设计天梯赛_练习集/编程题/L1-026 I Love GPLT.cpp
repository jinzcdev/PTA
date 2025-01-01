// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805108934557696
#include <cstdio>
#include <cstring>

void print(){
    char *str = "I Love GPLT";
    int len = strlen(str);
    for(int i = 0;i < len;i++){
        printf("%c\n",str[i]);
    }
}

int main(){
    print();
    return 0;
}