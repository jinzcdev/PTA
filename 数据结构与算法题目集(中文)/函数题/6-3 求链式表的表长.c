// https://pintia.cn/problem-sets/15/exam/problems/726
int Length( List L ) {
    if (L == NULL) return 0;
    int len = 0;
    List p = L;
    while (p != NULL) {
        len++;
        p = p->Next;
    }
    return len;
}