// https://pintia.cn/problem-sets/13/exam/problems/type/6?problemSetProblemId=608
struct ListNode *readlist() {
    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode)),
                    *r = L;
    L->next = NULL;
    int a;
    while (scanf("%d", &a) && a != -1) {
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->data = a;
        r->next = p;
        r = r->next;
    }
    r->next = NULL;
    return L->next;
}
struct ListNode *getodd(struct ListNode **L) {
    struct ListNode *head1 = (struct ListNode *)malloc(sizeof(struct ListNode)), *r = head1;
    struct ListNode *head2 = (struct ListNode *)malloc(sizeof(struct ListNode)), *p = head2;
    head2->next = *L;
    head1->next = NULL;
    while (p->next != NULL) {
        struct ListNode *q = p->next;
        if (q->data % 2 == 1) {
            r->next = q;
            r = r->next;
            p->next = q->next;
        } else {
            p = p->next;
        }
    }
    r->next = NULL;
    *L = head2->next;
    return head1->next;
}