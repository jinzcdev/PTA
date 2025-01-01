// https://pintia.cn/problem-sets/994805342720868352/exam/problems/type/7?problemSetProblemId=994805399578853376
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct node {
	double price, stock, totalPrice;
} Node[maxn];

bool cmp(node a, node b){
    return a.price > b.price;
}

int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; i++){
        scanf("%lf", &Node[i].stock);
	}
    for(int i = 0; i < n; i++){
        scanf("%lf", &Node[i].totalPrice);
        Node[i].price = Node[i].totalPrice / Node[i].stock;
    }
    sort(Node, Node + n, cmp);
    double total = 0.0;
    for(int i = 0; d > 0 && i < n; i++){
        if (Node[i].stock >= d){
            total += Node[i].price * d;
            Node[i].stock -= d;
            Node[i].totalPrice = Node[i].price * Node[i].stock;
            d = 0;
        } else {
            total += Node[i].totalPrice;
            d -= Node[i].stock;
            Node[i].stock = Node[i].totalPrice = 0;
        }
    }
    printf("%.2f", total);
	return 0;
}