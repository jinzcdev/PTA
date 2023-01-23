// https://pintia.cn/problem-sets/14/problems/44932
int  Search_Bin(SSTable T, KeyType k){
	int left = 0,right = T.length,mid = 0;
	while(left < right){
		mid = (left + right) / 2;
		if(T.R[mid].key == k) return mid;
		else if(T.R[mid].key > k)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}