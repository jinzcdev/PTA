// https://pintia.cn/problem-sets/12/exam/problems/361
int max_len( char *s[], int n ) {
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int len = strlen(s[i]);
        if (len > ans) ans = len;
    }
    return ans;
}