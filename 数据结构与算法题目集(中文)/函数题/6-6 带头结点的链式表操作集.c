// https://pintia.cn/problem-sets/15/problems/729
List MakeEmpty() {
    List L = (List)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}

Position Find(List L, ElementType X) {
    if (!L) return ERROR;
    for (Position p = L->Next; p != NULL; p = p->Next) {
        if (p->Data == X) return p;
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P) {
    if (!L) return false;
    Position pre = L;
    while (pre != NULL && pre->Next != P) pre = pre->Next;
    if (!pre) {
        printf("Wrong Position for Insertion\n");
        return false;
    } else {
        Position q = (Position)malloc(sizeof(struct LNode));
        q->Data = X;
        q->Next = pre->Next;
        pre->Next = q;
    }
    return true;
}

bool Delete(List L, Position P) {
    List pre = L;
    while (pre != NULL && pre->Next != P) pre = pre->Next;
    if (!pre) {
        printf("Wrong Position for Deletion\n");
        return false;
    }
    Position temp = pre->Next;
    pre->Next = temp->Next;
    free(temp);
    return true;
}