// https://pintia.cn/problem-sets/434/exam/problems/965458856133562368
Position BinarySearch(List L, ElementType X) {
    int left = 1, right = L->Last;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (L->Data[mid] > X) right = mid - 1;
        else if (L->Data[mid] < X) left = mid + 1;
        else return mid;
    }
    return NotFound;
}
