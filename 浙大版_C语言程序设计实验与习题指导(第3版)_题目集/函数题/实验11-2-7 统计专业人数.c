// https://pintia.cn/problem-sets/13/problems/606
int countcs( struct ListNode *head ) {
    int cnt = 0;
    struct ListNode *p = head;
    while (p != NULL) {
        if (p->code[1] == '0' && p->code[2] == '2') {
            cnt++;
        }
        p = p->next;
    }
    return cnt;
}