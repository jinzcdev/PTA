// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=343
void StringCount( char *s ) {
    int cnt[6] = {0};
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') cnt[0]++;
        else if (s[i] >= 'a' && s[i] <= 'z') cnt[1]++;
        else if (s[i] == ' ') cnt[2]++;
        else if (s[i] >= '0' && s[i] <= '9') cnt[3]++;
        else cnt[4]++;
    }
    for (int i = 0; i < 5; i++) {
        if (i != 0) printf(" ");
        printf("%d", cnt[i]);
    }
}