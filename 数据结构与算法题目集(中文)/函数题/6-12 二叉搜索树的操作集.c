// https://pintia.cn/problem-sets/15/exam/problems/927
BinTree Insert(BinTree BST, ElementType X) {
    if (BST == NULL) {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
        return BST;
    }
    if (X < BST->Data)
        BST->Left = Insert(BST->Left, X);
    else
        BST->Right = Insert(BST->Right, X);
    return BST;
}
BinTree Delete(BinTree BST, ElementType X) {
    Position temp;
    if (!BST)
        printf("Not Found\n");
    else if (X < BST->Data)
        BST->Left = Delete(BST->Left, X);
    else if (X > BST->Data)
        BST->Right = Delete(BST->Right, X);
    else {
        if (BST->Left && BST->Right) {
            temp = FindMin(BST->Right);
            BST->Data = temp->Data;
            BST->Right = Delete(BST->Right, BST->Data);
        } else {
            temp = BST;
            if (!BST->Left)
                BST = BST->Right;
            else if (!BST->Right)
                BST = BST->Left;
            free(temp);
        }
    }
    return BST;
}
Position Find(BinTree BST, ElementType X) {
    if (!BST) return NULL;
    Position temp;
    if (X < BST->Data) temp = Find(BST->Left, X);
    else if (X > BST->Data) temp = Find(BST->Right, X);
    else temp = BST;
    return temp;
}

Position FindMin(BinTree BST) {
    if (!BST) return NULL;
    else if (!BST->Left) return BST;
    else FindMin(BST->Left);
}

Position FindMax(BinTree BST) {
    if (!BST) return NULL;
    else if (!BST->Right) return BST;
    else FindMax(BST->Right);
}
