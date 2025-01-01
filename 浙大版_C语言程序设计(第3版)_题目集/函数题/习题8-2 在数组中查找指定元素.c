// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=335
int search( int list[], int n, int x ) {
    for (int i = 0; i < n; i++)
        if (list[i] == x) return i;
    return -1;
}