// https://pintia.cn/problem-sets/434/exam/problems/type/6?problemSetProblemId=5726
List Insert(List L, ElementType X) {
    PtrToNode p = L;
    while (p->Next != NULL && p->Next->Data < X) p = p->Next;
    PtrToNode q = (PtrToNode)malloc(sizeof(struct Node));
    q->Data = X;
    q->Next = p->Next;
    p->Next = q;
    return L;
}