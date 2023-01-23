// https://pintia.cn/problem-sets/15/problems/724
List Reverse(List L) {
    if (!L || L->Next == NULL) return L;
    List nextNode = L->Next;
    List head = Reverse(nextNode);
    L->Next = NULL;
    nextNode->Next = L;
    return head;
}
// List Reverse( List L ) {
//     if (L == NULL || L->Next == NULL) return L;
//     List head = Reverse(L->Next);
//     head->Next->Next = head;
//     head -> Next = NULL;
//     return head;
// }

// List Reverse( List L ) {
//     if (L == NULL || L->Next == NULL) return L;
//     List head = (List)malloc(sizeof(struct Node));
//     head->Next = L;
//     List last = L, p = last->Next;
//     while (p != NULL) {
//         last->Next = p->Next;
//         p->Next = head->Next;
//         head->Next = p;
//         p = last->Next;
//     }
//     return head->Next;
// }