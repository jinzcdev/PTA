// https://pintia.cn/problem-sets/16/exam/problems/701
void Level_order(Tree T, void (*visit)(Tree ThisNode)) {
    if (T == NULL) return;
    Tree q[1000];
    int left = 0, right = 1;
    q[left] = T;
    while (left < right) {
        Tree now = q[left++];
        visit(now);
        if (now->Left != NULL) q[right++] = now->Left;
        if (now->Right != NULL) q[right++] = now->Right;
    }
}