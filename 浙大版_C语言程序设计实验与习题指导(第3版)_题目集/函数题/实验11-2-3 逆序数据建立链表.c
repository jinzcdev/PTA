// https://pintia.cn/problem-sets/13/problems/603
struct ListNode *createlist() {
    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = NULL;
    int a;
    while (scanf("%d", &a) && a != -1) {
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->data = a;
        p->next = L->next;
        L->next = p;
    }
    return L->next;
}