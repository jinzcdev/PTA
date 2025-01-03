// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=994805290334011392
#include <cstdio>
#include <cctype>

int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool check(char *id) {
    int sum = 0, z;
    for (int i = 0; i < 17; i++) {
        if (!isdigit(id[i])) return false;
        sum += (id[i] - '0') * w[i];
    }
    z = sum % 11;
    return m[z] == id[17];
}

int main() {
    int n;
    scanf("%d", &n);
    bool flag = true;
    char id[18];
    while (n--) {
        scanf("%s", id);
        if (!check(id)) {
            printf("%s\n", id);
            flag = false;
        }
    }
    if (flag) printf("All passed");
    return 0;
}