#include <bits/stdc++.h>
using namespace std;

const int N = 21;
int n, a[N][N];

//折半搜索
long long ans = 0;
map< pair<pair<long long, long long>,long long>, long long> cnt;
void dfs1(int x, int y, int cur) {
    cur = cur ^ a[x][y];
    if(x + y == n + 1) { //在对角线上
        cnt[make_pair(make_pair(x, y), cur)]++;
        return;     //回溯
    }
    dfs1(x + 1, y, cur);    //走法1
    dfs1(x, y + 1, cur);    //走法2
}

void dfs2(int x, int y, int cur) {
    //先判断，防止重复异或
    if(x + y == n + 1) {    //在对角线上
        ans += cnt[make_pair(make_pair(x, y), cur)];
        return;     //回溯
    }
    cur = cur ^ a[x][y];
    dfs2(x - 1, y, cur);    //反走法1
    dfs2(x, y - 1, cur);    //反走法2
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) cin >> a[i][j];

    dfs1(1,1, 0);
    dfs2(n,n, 0);
    cout << ans << endl;
    return 0;
}