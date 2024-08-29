#include <iostream>
using namespace std;

int n, k, ans, maxn;

void dfs(int start, int s, int t) { //最小值为start，将s分为t份
    if(t == 1) {    //分完了
        ans++;
        return;
    }
    for(int i = start; i <= s / t; i++) {   //枚举所有的可能（同时去重）
        dfs(i, s - i, t - 1);   //再搜一位
        //不需要回溯
    }
}

int main() {
    cin >> n >> k;
    dfs(1, n, k);   //最小值是1，将n分为k份
    cout << ans;
    return 0;
}