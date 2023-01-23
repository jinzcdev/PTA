// https://pintia.cn/problem-sets/13/problems/604
struct ListNode *createlist() {
    int x;
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode)), *r = L;
    L->next = NULL;
    while (scanf("%d", &x) != EOF) {
        if (x == -1) break;
        struct ListNode *q = (struct ListNode*)malloc(sizeof(struct ListNode));
        q->data = x;
        q->next = NULL;
        r->next = q;
        r = r->next;
    }
    return L->next;
}

struct ListNode *deleteeven( struct ListNode *head ) {
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode)), *r = L, *p = head;
    L->next = NULL;
    while (p != NULL) {
        if (p->data % 2 == 1) {
            r->next = p;
            r = r -> next;
        }
        p = p->next;
    }
    r->next = NULL;
    return L->next;
} 