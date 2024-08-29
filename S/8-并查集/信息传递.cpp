#include <bits/stdc++.h>
using namespace std;

int father[200001];
int pre[200001];
int a[200001];
int minans = 2000001;

int find(int x) {
    return father[x] == x ? x : father[x] = find(father[x]);
}

void merge(int x, int y) {
    father[find(x)] = find(y);
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        father[i] = i;
        pre[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        if(find(i) == find(a[i])) {
            int ans = 1;    //i --> a[i]的连边
            for(int j = a[i]; j != i; j = pre[j]) { //找环
                ans++;
            }
            minans = min(minans, ans);
        }
        merge(i, a[i]);
        pre[i] = a[i];
    }
    cout << minans;
    return 0;
}