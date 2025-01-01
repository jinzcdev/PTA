// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805302786899968
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int change(int x, bool asc){
    int d[4] = {0}, i = 0, sum = 0;
    while (x != 0){
        d[i++] = x % 10;
        x /= 10;
    }
    if (asc)
        sort(d, d + 4);
    else
        sort(d, d + 4, cmp);
    for (int i = 0; i < 4; i++){
        sum = sum * 10 + d[i];
    }
    return sum;
}

int main(){
    int n, s1, s2;
    scanf("%d", &n);
    do {
        s1 = change(n, false);
        s2 = change(n, true);
        n = s1 - s2;
        printf("%04d - %04d = %04d\n", s1, s2, n);
    } while (n != 6174 && n != 0000);
    return 0;
}