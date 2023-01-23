// https://pintia.cn/problem-sets/13/problems/602
struct stud_node *createlist() {
    struct stud_node *L = (struct stud_node *)malloc(sizeof(struct stud_node)), *r = L;
    L->next = NULL;
    int n;
    while (scanf("%d", &n) && n != 0) {
        struct stud_node *p = (struct stud_node *)malloc(sizeof(struct stud_node));
        scanf("%s%d", p->name, &p->score);
        p->num = n;
        r->next = p;
        r = r->next;
    }
    r->next = NULL;
    return L->next;
}
struct stud_node *deletelist(struct stud_node *head, int min_score) {
    struct stud_node *L = (struct stud_node *)malloc(sizeof(struct stud_node)), *p = L;
    L->next = head;
    while (p->next != NULL) {
        struct stud_node *q = p->next;
        if (q->score < min_score) {
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return L->next;
}