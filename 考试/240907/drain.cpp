#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

typedef unsigned long long ull;

ull FastPow(ull a, ull b) {
    ull ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int fenzi = 1, fenmu = 1;   //分子和分母，约分后为：(m+1)*...*(n+m)/n!
    for(int i = m + 1; i <= n + m; i++) fenzi = (fenzi * i) % mod;  //分子是(n+m)!
    for(int i = 2; i <= n; i++) fenmu = (fenmu * i) % mod;          //分母是n!m!
    
    cout << fenzi * FastPow(fenmu, mod - 2) % mod << endl;

    return 0;
}