// https://pintia.cn/problem-sets/994805342720868352/problems/994805491530579968
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Customer {
    int arriveTime;
    int procrssTime;
} tempCt;
vector<Customer> customer;
int window[100];
bool cmp(Customer a, Customer b) {
    return a.arriveTime < b.arriveTime;
}
int main(){
    int n, k, h, m, s, pt;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        window[i] = 8 * 3600;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &h, &m, &s, &pt);
        int arriveTime = h * 3600 + m * 60 + s;
        if (arriveTime > 17 * 3600) continue;
        tempCt.arriveTime = arriveTime;
        tempCt.procrssTime = pt * 60;
        customer.push_back(tempCt);
    }
    if (customer.size() == 0) {
        printf("0.0\n");
        return 0;
    }
    sort(customer.begin(), customer.end(), cmp);
    double wt = 0.0;
    for (int i = 0; i < customer.size(); i++) {
        int indexW, minOverTime = 0x7FFFFFFF;
        for (int j = 0; j < k; j++) {
            if (window[j] < minOverTime) {
                indexW = j;
                minOverTime = window[j];
            }
        }
        if (window[indexW] <= customer[i].arriveTime) {
            window[indexW] = customer[i].arriveTime + customer[i].procrssTime;
        } else {
            wt += window[indexW] - customer[i].arriveTime;
            if (customer[i].procrssTime > 3600) window[indexW] += 3600;
            else window[indexW] += customer[i].procrssTime;
        }
    }
    printf("%.1f", wt / customer.size() / 60.0);
    return 0;
}