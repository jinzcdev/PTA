// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805519074574336

#include<cstdio>
#include<cstring>
char num[10][10] = {
    "zero","one","two","three","four","five","six","seven","eight","nine"
};
char s[111];
int digit[10];
int main() {
    gets(s);
    int len = strlen(s);
    int sum = 0, numLen = 0;
    for(int i = 0; i < len; i++) {
        sum += (s[i] - '0');
    }
    if(sum == 0) {
        printf("%s", num[0]);
    } else {
        while(sum != 0) {
            digit[numLen++] = sum % 10;
            sum /= 10;
        }
        for(int i = numLen - 1; i >= 0; i--) {
            printf("%s", num[digit[i]]);
            if(i != 0) printf(" ");
        }
    }
    return 0;
}