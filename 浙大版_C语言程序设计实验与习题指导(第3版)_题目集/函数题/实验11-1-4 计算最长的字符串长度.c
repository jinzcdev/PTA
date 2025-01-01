// https://pintia.cn/problem-sets/13/exam/problems/type/6?problemSetProblemId=591
int max_len( char *s[], int n ) {
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (s[i][j] != '\0') j++;
        if (j > ans) ans = j;
    }
    return ans;
}