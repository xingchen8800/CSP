#include <iostream>
using namespace std;

int a[100001], n, m, p, q;  //输入
int father[100001]; //并查集，father[i]记录i后第一个没染色的馒头

int Find(int x) {
    return father[x] == x ? x : father[x] = Find(father[x]);    //路径压缩，起到更新x后第一个没染色的馒头的作用
}

void Staining(int l, int r, int c) {
    for(int i = Find(l); i <= r; i = Find(i)) {
        a[i] = c;       //染色
        father[i] = i + 1;  //更新i后第一个没染色的馒头的作用
    }
}

int main() {
    cin >> n >> m >> p >> q;

    for(int i = 1; i <= n + 1; i++) father[i] = i;  //自己是自己的祖宗，n+1是虚拟节点
    for(int i = m; i >= 1; i--) {   //从后往前染色，因为馒头的颜色取决于最后一次的染色
        int l = (i * p + q) % n + 1;    //左端点
        int r = (i * q + p) % n + 1;    //右端点
        if(l > r) swap(l, r);           //保证是一个正常区间
        Staining(l, r, i);  //染色
    }

    for(int i = 1; i <= n; i++) cout << a[i] << "\n";
    return 0;
}