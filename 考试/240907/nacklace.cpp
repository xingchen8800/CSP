#include <bits/stdc++.h>
using namespace std;

int n, m, a[10001], ans = 0;
bool vis[10001] = {false};
void dfs(int x) {
    if(x > 1) ans++;
    if(x == n) {
        return;
    }
    for(int i = 1; i <= n; i++) {
        vis[i] = true;
        dfs(x + 1);
        vis[i] = false;
    }
}

int main() {
    freopen("necklace.in", "r", stdin);
    freopen("necklace.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(0);
    cout << ans;
    return 0;
}