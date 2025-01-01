// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=366
struct ListNode *readlist() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* r = head, *p;
    int x;
    while (scanf("%d", &x), x != -1) {
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->data = x;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    p = head->next;
    free(head);
    return p;
}
struct ListNode *deletem( struct ListNode *L, int m ) {
    if (L == NULL) return NULL;
    struct ListNode *p = deletem(L->next, m);
    if (L->data == m) return p;
    else {
        L->next = p;
        return L;
    }
}