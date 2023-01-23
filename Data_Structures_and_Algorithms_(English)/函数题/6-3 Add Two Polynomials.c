// https://pintia.cn/problem-sets/16/problems/698
Polynomial Add(Polynomial a, Polynomial b) {
    Polynomial P = (Polynomial)malloc(sizeof(struct Node)), s = P;
    P->Next = NULL;
    a = a->Next;
    b = b->Next;
    while (a != NULL && b != NULL) {
        if (a->Exponent > b->Exponent) {
            s->Next = a;
            a = a->Next;
            s = s->Next;
        } else if (a->Exponent < b->Exponent) {
            s->Next = b;
            b = b->Next;
            s = s->Next;
        } else {
            a->Coefficient += b->Coefficient;
            if (a->Coefficient != 0) {
                s->Next = a;
                s = s->Next;
            }
            a = a->Next;
            b = b->Next;
        }
    }
    if (a != NULL) s->Next = a;
    else s->Next = b;
//     if (P->Next == NULL) {
//         PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
//         p->Coefficient = p->Exponent = 0;
//         p->Next = NULL;
//         P->Next = p;
//     }
    return P;
}