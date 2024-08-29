#include <iostream>
#include <algorithm>
using namespace std;

int fa[200020];
struct node {
    int a, b, v;
} p[200020];

bool cmp(node x, node y) { return x.v > y.v; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> p[i].a >> p[i].b >> p[i].v;
    }
    sort(p + 1, p + m + 1, cmp);
    for(int i = 1; i <= 2 * n; i++) {   //n个真实节点，n个虚拟节点
        fa[i] = i;                      //自己的自己的祖宗
    }
    for(int i = 1; i <= m; i++) {
        int fx = find(p[i].a);
        int fy = find(p[i].b);
        if(fx != fy) {                  //无冲突
            merge(fx, find(p[i].b + n));    //将fx集合与p[i].b的敌人集合合并
            merge(fy, find(p[i].a + n));    //将fy集合与p[i].a的敌人集合合并
        } else {                        //有冲突，两个有冲突的罪犯在一个集合中
            cout << p[i].v << endl;
            return 0;
        }
    }
    cout << 0;
    return 0;
}