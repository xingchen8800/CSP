#include <iostream>
using namespace std;

int n, a[10]/*n个数*/;

//判断第x个数和第y个数是否需要交换，要求[x,y)中没有与第y个数字相等的数字
bool isSwap(int x, int y) {
    for(int i = x; i < y; i++) 
        if(a[i] == a[y]) return false;
    return true;
}
void dfs(int x) {
    if(x == n - 1) {
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return ;
    }
    for(int i = x; i < n; i++) {
        if(isSwap(x, i)) {
            swap(a[x], a[i]);
            dfs(x + 1);
            swap(a[x], a[i]);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    dfs(0);
    return 0;
}