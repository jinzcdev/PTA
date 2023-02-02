// https://pintia.cn/problem-sets/13/exam/problems/605
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode *l = (struct ListNode*)malloc(sizeof(struct ListNode));
    l->next = NULL;
    struct ListNode *r = l, *p = list1, *q = list2;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
        } else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    if (p != NULL) r->next = p;
    if (q != NULL) r->next = q;
    
    return l->next;
}