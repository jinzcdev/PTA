// https://pintia.cn/problem-sets/434/exam/problems/5803
List Merge(List L1, List L2) {
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    PtrToNode p = L1->Next, q = L2->Next, s = L;
    while (p != NULL && q != NULL) {
        if (p->Data <= q->Data) {
            s->Next = p;
            p = p->Next;
        } else {
            s->Next = q;
            q = q->Next;
        }
        s = s->Next;
    }
    if (p != NULL) s->Next = p;
    if (q != NULL) s->Next = q;
    L1->Next = L2->Next = NULL;
    return L;
}