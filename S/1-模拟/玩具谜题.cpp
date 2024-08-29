#include <iostream>
using namespace std;

int m, n;
struct Node {
    string name;
    bool rotation;
} a[100001];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].rotation >> a[i].name;    
    int x, y;   //等待输入方向(x)与个数(y)
    int index = 0; //从头开始数
    while(m--) {
        cin >> x >> y;
        if(a[index].rotation ^ x) index = (index + y) % n;
        else index = (index + n - y) % n; //index + n是为了防止越界为负数
    }

    cout << a[index].name << endl;
    return 0;
}