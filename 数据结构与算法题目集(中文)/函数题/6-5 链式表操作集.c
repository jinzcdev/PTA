// https://pintia.cn/problem-sets/15/problems/728
Position Find(List L, ElementType X) {
    if (!L) return ERROR;
    else if (L->Data == X) return L;
    else return Find(L->Next, X);
}

List Insert(List L, ElementType X, Position P) {
    List p = (List)malloc(sizeof(struct LNode)), q = p;
    p->Next = L;
    while (p != NULL && p->Next != P) p = p->Next;
    if (p == NULL) {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    } else {
        Position Node = (Position)malloc(sizeof(struct LNode));
        Node->Data = X;
        Node->Next = P;
        p->Next = Node;
    }
    Position head = q->Next;
    free(q);
    return head;
}

List Delete(List L, Position P) {
    if (L == P) {
        L = L->Next;
        free(P);
        return L;
    }
    List p = L;
    while (p != NULL && p->Next != P) p = p->Next;
    if (!p) {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    Position temp = p->Next;
    p->Next = temp->Next;
    free(temp);
    return L;
}