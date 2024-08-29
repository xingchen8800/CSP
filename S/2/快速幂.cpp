#include <iostream>
using namespace std;

int main() {
    long long a, b, k, ans = 1;
    cin >> a >> b >> k;
    while(b) {
        if(b % 2) ans = (ans * a) % k;
        a = (a * a) % k;
        b /= 2;
    }
    cout << ans << endl;
    return 0;
}