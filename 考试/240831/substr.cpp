#include <bits/stdc++.h>
using namespace std;

const int N = 500001;
int a[N], n;

struct Node {
    string s;
    int l, r;
} substrs[N * 10];

int cnt = 0;

bool cmp(Node &a, Node &b) {
    return a.s < b.s;
}

int main() {
    freopen("substr.in", "r", stdin);
    freopen("substr.out", "w", stdout);
    int q, x;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            string s;
            for(int k = i; k <= j; k++) {
                s += a[k] + '0';
            }
            substrs[cnt++] = (Node){s, i, j};
        }
    }
    sort(substrs, substrs + cnt , cmp);

    while(q--) {
        cin >> x;
        cout << substrs[x - 1].l << " " << substrs[x - 1].r << endl;
    }
    return 0;
}