// https://pintia.cn/problem-sets/13/exam/problems/609
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
struct ListNode *deletem(struct ListNode *L, int m) {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = L;
    for (struct ListNode *p = head; p->next != NULL;) {
        struct ListNode *q = p->next;
        if (q->data == m) {
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return head->next;
}