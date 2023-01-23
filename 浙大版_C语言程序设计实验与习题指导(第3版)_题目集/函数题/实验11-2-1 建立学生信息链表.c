// https://pintia.cn/problem-sets/13/problems/601
void input() {
    struct stud_node *L = (struct stud_node *)malloc(sizeof(struct stud_node));
    L->next = NULL;
    tail = L;
    int num, score;
    char name[20];
    while (scanf("%d", &num) && num != 0) {
        scanf("%s %d", name, &score);
        struct stud_node *stu = (struct stud_node *)malloc(sizeof(struct stud_node));
        stu->num = num;
        strcpy(stu->name, name);
        stu->score = score;
        tail->next = stu;
        tail = tail->next;
    }
    head = L->next;
}