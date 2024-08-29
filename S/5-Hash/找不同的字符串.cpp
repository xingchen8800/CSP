#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int B = 128;
const unsigned long long MOD = 1e9;

unsigned long long _hash[100001], cnt = 0, ans = 1, n;
//从尾到头法
// unsigned long long GetHash(string s) {
//     unsigned long long result = 0;
//     for(int i = s.length() - 1; i >= 0; i--) {
//         result += s[i] * pow(B, i);
//     }
//     return result % MOD;
// }
//尾部追加法
unsigned long long GetHash(string s) {
    unsigned long long result = 0;
    for(int i = 0; i < s.length(); i++) {
        result = result * B + s[i]; //追加
    }
    return result % MOD;
}

int main() {
    cin >> n;
    string str;
    while(n--) {
        cin >> str;
        _hash[++cnt] = GetHash(str);
    }
    sort(_hash + 1, _hash + cnt);
    for(int i = 1; i < cnt; i++) {
        if(_hash[i] != _hash[i + 1]) ans++;
    }
    cout << ans << endl;
}