#include <bits/stdc++.h>
using namespace std;

int father[30001]; 
int dis[30001];     //distance:i-->root
int cnts[30001];    //第i列的战舰数量

int find(int x) {
    if(father[x] == x) return x;
    else {  //不是集合的祖宗，有传递的dis
        int pre = father[x];    //当前的父节点
        int forefa = find(father[x]);   //祖宗
        //不直接压缩，而是记录权值后再压缩
        dis[x] += dis[pre]; //因为find()是递归函数，先find上面的再find下面的
        father[pre] = forefa;//压缩
        return forefa;
    }
}

void merge(int x, int y) {
    father[find(x)] = find(y);
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        father[i] = i;
        cnts[i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        int fx = find(x), fy = find(y);
        if(ch == 'M') {
            if(fx != fy) {
                merge(x, y);
                dis[fx] = cnts[fy];   //x的祖宗到根节点的距离等于第find(y)列的元素数（追加）
                cnts[fy] += cnts[fx]; //第find(y)列的元素数增加
            }
        } else {
            if(fx == fy) {
                cout << max(abs(dis[x] - dis[y]) - 1, 0)<< endl;
            } else cout << -1 << endl;
        }
    }
    return 0;
}