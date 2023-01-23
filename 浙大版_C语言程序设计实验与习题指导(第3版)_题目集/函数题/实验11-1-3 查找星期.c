// https://pintia.cn/problem-sets/13/problems/590
int getindex(char *s) {
    if (!strcmp(s, "Sunday")) return 0;
    if (!strcmp(s, "Monday")) return 1;
    if (!strcmp(s, "Tuesday")) return 2;
    if (!strcmp(s, "Wednesday")) return 3;
    if (!strcmp(s, "Thursday")) return 4;
    if (!strcmp(s, "Friday")) return 5;
    if (!strcmp(s, "Saturday")) return 6;
    return -1;
}