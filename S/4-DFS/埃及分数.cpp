#include <bits/stdc++.h>
using namespace std;

int ans[10001], cnt = 0, a, b;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

void dfs(int a, int b) {
    if(b % a == 0) {
        ans[++cnt] = b / a;
        b /= a;
        a = 1;
    }
    if(a == 1) {
        for(int i = 1; i <= cnt; i++) {
            cout << ans[i] << " " << endl;
        }
        return;
    }
    int xn = ceil((double)b / a);
    ans[++cnt] = xn;
    int x = a * xn - b;
    int y = b * xn;
    int t = gcd(x, y);  //求(x,y)
    x /= t; //x除去最大公约数
    y /= t; //y除去最大公约数
    dfs(x, y);
}

int main() {
    cin >> a >> b;
    dfs(a, b);
    return 0;
}