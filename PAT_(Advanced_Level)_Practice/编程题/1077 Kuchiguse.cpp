// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805390896644096
#include <cstdio>
#include <cstring>
int n, minLen = 256, ans = 0;
char s[100][256];

int main() {
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        //gets(s[i]);
        fgets(s[i],258,stdin);
        int len = strlen(s[i]);
        s[i][--len] = '\0';
        if(len < minLen) minLen = len;
        for(int j = 0; j < len / 2; j++) {
            char temp = s[i][j];
            s[i][j] = s[i][len - j - 1];
            s[i][len - j - 1] = temp;
        }
    }
    for(int i = 0; i < minLen; i++) {
        char c = s[0][i];
        bool same = true;
        for(int j = 1; j < n; j++) {
            if(c != s[j][i]) {
                same = false;
                break;
            }
        }
        if(same) ans++;
        else break;
    }
    if(ans) {
        for(int i = ans - 1; i >= 0; i--) {
            printf("%c", s[0][i]);
        }
    } else {
        printf("nai");
    }
    return 0;
}
