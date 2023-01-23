// https://pintia.cn/problem-sets/434/problems/966235055998885888
ElementType Find(List L, int m) {
    if (!L || m <= 0) return ERROR;
    int len = 0, cnt = 0, pos;
    for (PtrToNode p = L->Next; p != NULL; p = p->Next) len++;
    if (m > len) return ERROR;
    pos = len - m + 1;
    PtrToNode p = L;
    while (L->Next != NULL && cnt++ != pos) p = p->Next;
    return p->Data;
}