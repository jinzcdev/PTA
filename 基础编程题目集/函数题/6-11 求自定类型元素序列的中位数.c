// https://pintia.cn/problem-sets/14/exam/problems/743
ElementType Median( ElementType A[], int N ){
    if (N == 1) return A[0];
    ShellSort(A, N);
    return A[N / 2];
}

void ShellSort(int arr[], int n)
{
    int i, j, k;
    int temp, gap;
    
    for (gap = n / 2; gap > 0; gap /= 2) //步长的选取
    {
        for (i = 0; i < gap; i++)        //直接插入排序原理
        {
            for (j = i + gap; j < n; j += gap)    //每次加上步长，即按列排序。
                if (arr[j] < arr[j - gap])
                {
                    temp = arr[j];
                    k = j - gap;
                    while (k >= 0 && arr[k] > temp) //记录后移，查找插入位置
                    {
                        arr[k + gap] = arr[k];
                        k -= gap;
                    }
                    arr[k + gap] = temp;  //找到位置插入
                }
        }
    }
}