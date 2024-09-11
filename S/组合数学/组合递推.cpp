#include <bits/stdc++.h>
using namespace std;

int C[2005][2005];

int main() {
    ios::sync_with_stdio(false);
    C[0][0] = 1;
    for(int i = 1; i <= 2000; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j] % 100;
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}