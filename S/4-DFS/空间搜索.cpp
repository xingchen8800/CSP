#include <iostream>
using namespace std;

int n, x, y;
int ans = 114514;
int vis[210];   //标记数组
int s[210];     //数据

void dfs(int now, int step) {   //在第now层，走了step步
    if(now == y) {  //到达
        ans = min(ans, step); return;
    } else if(step >= ans) return;   //剪枝

    if(now + s[now] <= n && vis[now + s[now]] == 0) { //往上走
        vis[now + s[now]] = 1;  //标记
        dfs(now + s[now], step + 1);
        vis[now + s[now]] = 0;  //回溯
    }
    if(now - s[now] >= 1 && vis[now - s[now]] == 0) { //往下走
        vis[now - s[now]] = 1;  //标记
        dfs(now - s[now], step + 1);
        vis[now - s[now]] = 0;  //回溯
    }
}

int main() {
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) cin >> s[i];
    
    vis[x] = 1; //1层走过了
    dfs(x, 0);
    
    cout << (ans != 114514 ? ans : -1);
    return 0;
}
