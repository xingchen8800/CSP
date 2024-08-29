#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int a[N];   //原数组，最多N个数据
int c[N];
int n;  //n个数据

int lowbit(int x) { return x & (-x); }

void Update(int x, int k) {
    for(int i = x; i <= n; i += lowbit(i)) c[i] += k;
}

int Sum(int l, int r) {
    if(l == 1) {
        int result = 0;
        for(int i = r; i >= 1; i -= lowbit(i)) result += c[i];  //累加
        return result;
    } else return Sum(1, r) - Sum(1, l - 1);    //前缀和
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        Update(i, a[i]);
    }
    for(int i = 1; i <= m; i++) {
        int p, x, y, k;
        cin >> p;
        if(p == 1) {
            cin >> x >> k;
            Update(x, k);
        } else {
            cin >> x >> y;
            cout << Sum(y, x) << endl;
        }
    }
    return 0;
}