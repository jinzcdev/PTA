// https://pintia.cn/problem-sets/13/exam/problems/607
struct ListNode *reverse( struct ListNode *head ) {
    if (head == NULL) return NULL;
    struct ListNode *h = (struct ListNode*)malloc(sizeof(struct ListNode)), *p = head->next;
    h->next = head;
    while (p != NULL) {
        head->next = p->next;
        p->next = h->next;
        h->next = p;
        p = head->next;
    }
    return h->next;
}