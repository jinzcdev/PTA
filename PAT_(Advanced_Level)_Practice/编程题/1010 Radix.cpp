// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805507225665536
#include <algorithm>
#include <string.h>
#include <cctype>
#include <cmath>
#include <iostream>
using namespace std;

char FindMaxElement(char ch[])
{   /* 寻找字符数组中最大的元素 */
    return *max_element(ch, ch+strlen(ch));
}

int charToint(char c)
{   /* 把字符转为数字 */
    return isdigit(c) ? c - '0' : c - 'a' + 10;
}

long long transfer(char ch[], long long radix)
{   /* 转换成十进制 */
    long long sum = 0;
    for (int i = strlen(ch)-1; i >= 0; i--)
        sum += charToint(ch[i]) * pow(radix, strlen(ch)-1-i);
    return sum;
}

long long check(char ch[], long long num)
{   /* 采用二分法进行寻找 */
    long long low = charToint(FindMaxElement(ch))+1, mid; /* 这里下界是ch中最大的字符数值+1 */
    long long high = num > low ? num : low;
    while (low <= high)
    {
        mid = (low+high) / 2;
        long long aws = transfer(ch, mid);
        if (aws < 0 || aws > num)
            high = mid - 1;
        else if (aws == num)
            return mid;
        else
            low = mid + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    char N1[11], N2[11];
    int tag;
    long long r, radix;
    cin >> N1 >> N2 >> tag >> radix;
    r = tag == 1 ? check(N2, transfer(N1, radix)) : check(N1, transfer(N2, radix));
    if (r == -1)
        cout << "Impossible";
    else
        cout << r;
    return 0;
}