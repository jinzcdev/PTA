// https://pintia.cn/problem-sets/434/exam/problems/6178
bool isValidBST(BinTree T, int low, int high) {
    if (T == NULL) return true;
    if (T->Data <= low || T->Data >= high) return false;
    return isValidBST(T->Left, low, T->Data) && isValidBST(T->Right, T->Data, high);
}
bool IsBST(BinTree T) {
    return isValidBST(T, -1, 0x7FFFFFFF);
}