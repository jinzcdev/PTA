// https://pintia.cn/problem-sets/12/problems/347
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char name[15], phone[25];
    int birthday;
} stu[10];
int cmp(const void* a, const void* b) {
    return ((struct node*)a)->birthday - ((struct node*)b)->birthday;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s%d%s", stu[i].name, &stu[i].birthday, stu[i].phone);
    qsort(stu, n, sizeof(struct node), cmp);
    for (int i = 0; i < n; i++)
        printf("%s %d %s\n", stu[i].name, stu[i].birthday, stu[i].phone);
    return 0;
}