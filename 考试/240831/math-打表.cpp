#include <bits/stdc++.h>
using namespace std;

int a[] = {3, 9, 1, 7};

int main() {
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
    int n;
    cin >> n;
    if(n == 0) {
        cout << 1 << endl;
        return 0;
    }
    cout << a[n%4];
    return 0;
}
