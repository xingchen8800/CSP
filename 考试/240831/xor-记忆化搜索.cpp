#include <bits/stdc++.h>
using namespace std;

const int N = 21;
int n, a[N][N], INF;

int fx[2] = {1, 0};
int fy[2] = {0, 1};

bool vis[N][N] = {};
int dp[N][N][15] = {};
int dfs(int x, int y, int _sum) {
    if(dp[x][y][_sum] != INF) {
        return dp[x][y][_sum];
    }
    if(x == n && y == n) {
        if(_sum == 0) {
            return 1;
        }
        else return 0;
    }

    int ans = 0;
    for(int i = 0; i < 2; i++) {
        int xx = x + fx[i];
        int yy = y + fy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= n && !vis[xx][yy]) {
            vis[xx][yy] = true;
            ans += dfs(xx, yy, _sum ^ a[xx][yy]);
            vis[xx][yy] = false;
        }
    }
    if(!ans) return 0;
    else return dp[x][y][_sum] = ans;
    return ans;
    
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    memset(dp,0x3f, sizeof dp);
    INF = dp[0][0][0];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << dfs(1,1,a[1][1]);
    return 0;
}