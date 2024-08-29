#include <bits/stdc++.h>
using namespace std;

int father[1000001];    //祖宗
int dis[100001];    //i --> root

int Find(int x) {
    if(father[x] == x) return x;
    else {
        dis[x] += dis[father[x]];           //累加距离
        return father[x] = Find(father[x]); //路径压缩
    }
}

bool Check(int s, int t, int v) {
    int fs = Find(s);
    int ft = Find(t);
    if(fs == ft) {    //有环，判断真假
        return (dis[s] - dis[t]) == v;
    } 
    if(fs < ft) {
        father[fs] = ft;
        dis[fs] = dis[t] + v - dis[s];
        return true;
    } else {
        father[ft] = Find(s);
        dis[ft] = dis[s] + v - dis[t];
        return true;
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        //init
        bool isReal = true;
        memset(dis, 0, sizeof(dis));

        for(int i = 0; i <= n; i++) father[i] = i;  //0是虚拟节点
        
        //core
        int s, t, v;
        for(int i = 1; i <= m; i++) {
            cin >> s >> t >> v;
            if(!isReal) continue;   //某一步是假的，整个都是假的
            if(!Check(s - 1, t, v)) isReal = false;   //假的
        }

        //output
        if(isReal) cout << "true\n";
        else cout << "false\n"; 
    }
    return 0;
}