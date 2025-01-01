// https://pintia.cn/problem-sets/12/exam/problems/type/6?problemSetProblemId=365
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
    p = head;
    head = head->next;
    free(p);
    return head;
}
struct ListNode *getodd( struct ListNode **L ) {
    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head1->next = NULL;
    struct ListNode *r = head1, *head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head2->next = *L;
    struct ListNode *p = head2, *q = p->next;
    while (q != NULL) {
        if (q->data % 2 == 1) {
            r->next = q;
            r = q;
            p->next = q->next;
            q = p->next;
        } else {
            p = q;
            q = q->next;
        }
    }
    r->next = NULL;
    *L = head2->next;
    return head1->next;
}