// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805476473028608
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100;
int maxStep;

bool isPali(char *number){
    int len = strlen(number), mid = len / 2;
    for (int i = 0; i < mid; i++){
        if (number[i] != number[len - 1 - i]) return false;
    }
    return true;
}

void findPali(char *number, int step){
    bool isP = isPali(number);
    if (isP || step == maxStep) {
        printf("%s\n%d", number, step);
        return;
    }
    char sum[maxn];
    int k = 0, len = strlen(number), cnt = 0;
    for (int i = 0; i < len; i++){
        int temp = (number[i] - '0') + (number[len - 1 - i] - '0') + k;
        sum[cnt++] = temp % 10 + '0';
        k = temp / 10;
    }
    if (k != 0) sum[cnt++] = k + '0';
    sum[cnt] = '\0';
    reverse(sum, sum + cnt);
    findPali(sum, ++step);
}

int main(){
    char number[maxn];
    scanf("%s %d", number, &maxStep);
    findPali(number, 0);
    return 0;
}