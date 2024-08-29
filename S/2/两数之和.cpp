#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[1000010];

int main() {
    //输入
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    //排序
    sort(a, a + n);
    //核心
    for(int i = 0; i < n; i++) {
        int t = m - a[i];   //枚举一个数
        //二分
        int l = i + 1, r = n - 1; //在(i + 1, n - 1)区间内查找
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(a[mid] == t) {   //找到了
                cout << a[i] << " " << t << endl;
                return 0;
            }
            if(a[mid] > t) r = mid - 1; //向左找
            else l = mid + 1; //向右找
        }
    }
    cout << "NO" << endl;
}