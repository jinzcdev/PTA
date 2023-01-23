// https://pintia.cn/problem-sets/15/problems/732
void InorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
}

void PreorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}

void LevelorderTraversal(BinTree BT) {
    if (BT == NULL) return;
    BinTree q[100];
    int front = 0, rear = 0;
    q[rear++] = BT;
    while (front < rear) {
        BinTree now = q[front++];
        printf(" %c", now->Data);
        if (now->Left) q[rear++] = now->Left;
        if (now->Right) q[rear++] = now->Right;
    }
}