#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int a[601][601], b[601][601];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool vis[601][601];
int minv = INT_MAX;
void dfs(int x, int y, int v, int nt) {
    if(nt == t - 1) {
        minv = min(minv, v);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= n && !vis[xx][yy]) {
            vis[xx][yy] = true;
            dfs(xx, yy, v + abs(a[x][y] - a[xx][yy]), nt + 1);
            vis[xx][yy] = false;
        }
    }
}

int main() {
    freopen("battle.in", "r", stdin);
    freopen("battle.out", "w", stdout);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    
    
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(b[i][j]) {
                minv = INT_MAX;
                memset(vis, false, sizeof vis);
                dfs(i, j, 0, 0);
                cout << i << " " << j << " " << minv << endl;
                ans = (ans + minv);
            }
        }
    }

    cout << ans << endl;
    return 0;
}