// https://pintia.cn/problem-sets/988034414048743424/exam/problems/988038562512924672
int getLen(List L) {
    PtrToNode p = L->Next;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->Next;
    }
    return len;
}
PtrToNode Suffix( List L1, List L2 ) {
    int len1 = getLen(L1), len2 = getLen(L2);
    int d = len1 > len2 ? len1 - len2 : len2 - len1;
    PtrToNode p, q;
    if (len1 > len2) {
        p = L1->Next;
        q = L2->Next;
    } else {
        p = L2->Next;
        q = L1->Next;
    }
    for (int i = 0; i < d && p != NULL; i++) p = p->Next;
    while (p != q && p != NULL && q != NULL) {
        p = p->Next;
        q = q->Next;
    }
    return p;
}