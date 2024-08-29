#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map<pair<int,int>, bool> did_visit; //防止题目的神仙条件来两次一样的
int d[10001]; //d是差分数组
int n, p, h, m, a, b;

int main() {
    cin >> n >> p >> h >> m;
    memset(d, 0, 10001);    //d[0]=0
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        if(a > b) swap(a, b);   //防止区间是反的
        if(!did_visit[make_pair(a, b)]) {
            d[a + 1]--; d[b]++;     //区间修改
            did_visit[make_pair(a, b)] = true;  //标记
        } else continue;
    }   
    int ans = h;
    for(int i = 1; i <= n; i++) {
        h += d[i];
        cout << h << endl;  //单值查询
    }
    return 0;
}