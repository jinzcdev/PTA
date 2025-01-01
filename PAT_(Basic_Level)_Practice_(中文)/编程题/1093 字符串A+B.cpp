// https://pintia.cn/problem-sets/994805260223102976/exam/problems/type/7?problemSetProblemId=1071785884776722432
#include <cstdio>
#include <cstring>

const int maxn = 1000010;
int map[100] = {0};
char rs[100];
int len = 0;

int main()
{
    char a[maxn], b[maxn];
    fgets(a, maxn, stdin);
    fgets(b, maxn, stdin);
    int lena = strlen(a), lenb = strlen(b);

    for (int i = 0; i < lena - 1; ++i)
    {
        int ascii = a[i];
        if (map[ascii]++ == 0)
            rs[len++] = ascii;
    }

    for (int j = 0; j < lenb - 1; ++j)
    {
        int ascii = b[j];
        if (map[ascii]++ == 0)
            rs[len++] = ascii;
    }

    rs[len] = '\0';
    printf("%s", rs);

    return 0;
}
