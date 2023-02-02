// https://pintia.cn/problem-sets/12/exam/problems/360
int getindex( char *s ) {
    int ans = -1;
    if (strcmp(s, "Sunday") == 0) return 0;
    if (strcmp(s, "Monday") == 0) return 1;
    if (strcmp(s, "Tuesday") == 0) return 2;
    if (strcmp(s, "Wednesday") == 0) return 3;
    if (strcmp(s, "Thursday") == 0) return 4;
    if (strcmp(s, "Friday") == 0) return 5;
    if (strcmp(s, "Saturday") == 0) return 6;
    return -1;
}