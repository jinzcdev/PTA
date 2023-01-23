// https://pintia.cn/problem-sets/15/problems/727
ElementType FindKth( List L, int K ) {
    if (K < 1) return ERROR;
    int cnt = 0;
    List p = L;
    while (p != NULL && ++cnt < K) {
        p = p->Next;
    }
    if (cnt != K) return ERROR;
    return p->Data;
}