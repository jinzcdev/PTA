// https://pintia.cn/problem-sets/434/problems/6222
bool Delete(HashTable H, ElementType Key) {
    Index pos = Hash(Key, H->TableSize);
    List L = H->Heads + pos;
    PtrToLNode p = L;
    while (p->Next != NULL) {
        if (strcmp(p->Next->Data, Key) == 0) break;
        p = p->Next;
    }
    if (p->Next == NULL) return false;
    PtrToLNode q = p->Next;
    p->Next = q->Next;
    free(q);
    printf("%s is deleted from list Heads[%d]\n", Key, pos);
    return true;
}