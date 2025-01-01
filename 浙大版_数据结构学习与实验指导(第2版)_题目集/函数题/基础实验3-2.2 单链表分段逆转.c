// https://pintia.cn/problem-sets/988034414048743424/exam/problems/type/6?problemSetProblemId=988038293285015552
int getLen(List L) {
    PtrToNode p = L->Next;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->Next;
    }
    return len;
}
void K_Reverse(List L, int K) {
    PtrToNode p = L, q = p->Next;
    int len = getLen(L);
    while (len >= K) {
        for (int i = 0; i < K - 1; i++) {
            PtrToNode r = q->Next;
            q->Next = r->Next;
            r->Next = p->Next;
            p->Next = r;
        }
        p = q;
        q = p->Next;
        len -= K;
    }
}