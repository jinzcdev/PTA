// https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152
#include <cstdio>
#include <cstring>
const int maxn = 10010;
bool hashTable[128] = {false};
int main(){
    char s1[maxn], s2[maxn];
    fgets(s1, sizeof(s1) + 2, stdin);
    fgets(s2, sizeof(s1) + 2, stdin);
    int len1 = strlen(s1), len2 = strlen(s2);
    s1[--len1] = '\0';
    s2[--len2] = '\0';
    for (int i = 0; i < len2; i++) {
        hashTable[s2[i]] = true;
    }
    for (int i = 0; i < len1; i++) {
        if (!hashTable[s1[i]]) {
            printf("%c", s1[i]);
        }
    }
    return 0;
}