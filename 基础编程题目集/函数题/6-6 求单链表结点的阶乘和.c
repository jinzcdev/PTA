// https://pintia.cn/problem-sets/14/exam/problems/type/6?problemSetProblemId=738
int FactorialSum( List L ) {
    List p = L;
    int ans = 0, i;
    while (p != NULL) {
        int temp = 1;
        for ( i = 1; i <= p->Data; i++) {
            temp *= i;
        }
        ans += temp;
        p = p->Next;
    }
    return ans;
}