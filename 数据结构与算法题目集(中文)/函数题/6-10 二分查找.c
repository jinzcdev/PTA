// https://pintia.cn/problem-sets/15/exam/problems/type/6?problemSetProblemId=923
Position BinarySearch(List L, ElementType X) {
    int left = 1, right = L->Last, mid, ans = -1;
    while(left <= right){
		mid = (right - left) / 2 + left;
		if(L->Data[mid] == X) {
            ans = mid;
            break;
        }
		else if(L->Data[mid] > X) right = mid - 1;
		else left = mid + 1;
	}
    return ans == -1 ? NotFound : ans;
}