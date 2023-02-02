// https://pintia.cn/problem-sets/994805260223102976/exam/problems/994805302786899968
#include <stdio.h>
#include <stdlib.h>
int cmpR(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main() {
    int num;
    scanf("%d", &num);
    do {
        int nums[4] = {0};
        for (int i = 0; num != 0; i++, num /= 10) nums[i] = num % 10;
        int a = 0, b = 0;  //用来保存两个临时数
        qsort(nums, 4, sizeof(int), cmpR);
        for (int i = 3; i >= 0; i--) a = a * 10 + nums[i];
        for (int j = 0; j < 4; j++) b = b * 10 + nums[j];
        num = a - b;
        printf("%04d - %04d = %04d\n", a, b, num);
    } while (num != 6174 && num != 0000);
    return 0;
}