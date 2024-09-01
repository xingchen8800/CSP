#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 1, a = 3;
    while(n) {
        if(n & 1) ans = (ans * a) % 10;
        a = (a * a) % 10;
        n /= 2;
    }
    cout << ans << endl;
}