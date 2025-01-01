// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805294251491328
#include <cstdio>
int main(){
    int n;
    char sb;
    scanf("%d %c", &n, &sb);
    // 根据规则进行累加, 直到达到满足沙漏形状的最大数量
    int sum = 1, k = 3;
    while (sum <= n - k * 2){
        sum += k * 2;
        k = k + 2;
    }
    int rest = n - sum; // 计算剩余的符号数
    k = k - 2;          // 沙漏第一行符号数

    int space = 0, cnt = k;
    while (cnt != 1){
        for (int i = 0; i < space; i++){
            printf(" ");
        }
        for (int i = 0; i < cnt; i++){
            printf("%c", sb);
        }
        printf("\n");
        cnt = cnt - 2;
        space++;
    }
    while (cnt != k + 2){
        for (int i = 0; i < space; i++){
            printf(" ");
        }
        for (int i = 0; i < cnt; i++){
            printf("%c", sb);
        }
        printf("\n");
        cnt = cnt + 2;
        space--;
    }
    printf("%d", rest);
    return 0;
}