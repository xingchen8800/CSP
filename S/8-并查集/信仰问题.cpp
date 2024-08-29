#include <iostream>
#include <algorithm>
using namespace std;

int father[50001];

int find(int x) {
    return father[x] == x ? x : father[x] = find(father[x]);
}

void merge(int x, int y) {
    father[find(y)] = find(x);
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);    //合并
    }
    sort(father + 1, father + n + 1);
    
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(father[i] != father[i - 1]) ans++;
    }
    cout << ans;
}