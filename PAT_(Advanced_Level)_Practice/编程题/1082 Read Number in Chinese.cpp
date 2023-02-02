// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805385053978624
/*
#include <cstdio>
#include <cstring>
char num[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main() {
    char str[15];
    scanf("%s", str);
    int len = strlen(str), left = 0, right = len - 1;
    if (str[0] == '-') {
        left++;
        printf("Fu");  // 如果为负数,输出"Fu"
    }
    while (left + 4 <= right) right -= 4;
    while (left < len) {
        bool flag = false, isPrint = false;
        while (left <= right) {
            if (left > 0 && str[left] == '0') flag = true;
            else {
                if (flag == true) {
                    printf(" ling");
                    flag = false;
                }
                if (left > 0) printf(" ");
                printf("%s", num[str[left] - '0']);
                isPrint = true;
                if (left != right) printf(" %s", wei[right - left - 1]);
            }
            left++;
        }
        if (isPrint == true && right != len - 1) {
            printf(" %s", wei[(len - 1 - right) / 4 + 2]);
        }
        right += 4;
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
char num[10][5] = {"ling", "yi",  "er", "san", "si",
                   "wu",   "liu", "qi", "ba",  "jiu"};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main() {
    char a[15];
    scanf("%s", a);
    int len = strlen(a), left = 0, right = len - 1, cnt = 0;
    if (a[left] == '0') {
        printf("ling");
        return 0;
    }
    if (a[left] == '-') {
        printf("Fu ");
        left++;
    }
    while (left + 4 <= right) right -= 4;
    while (left < len) {
        bool hasZero = false, flag = false;
        while (left <= right) {
            if (a[left] == '0') hasZero = true;
            else {
                if (hasZero) {
                    printf(" ling");
                    hasZero = false;
                }
                if (cnt++ > 0) printf(" ");
                printf("%s", num[a[left] - '0']);
                if (right != left) printf(" %s", wei[right - left - 1]);
                flag = true;
            }
            left++;
            if (!flag && right != len - 1 && left == right && a[left + 1] != '0') printf(" ling");
        }
        if (flag && len - right - 1 != 0) 
            printf(" %s", len - right - 1 == 4 ? "Wan" : "Yi");
        right += 4;
    }
    return 0;
}