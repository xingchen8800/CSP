#include <iostream>
using namespace std;
int n, a[10], b[10];    //b表示是否被使用过，a表示一种排列方式
void dfs(int x) {   //当前填充第x位
    if(x == n + 1) {    //填完了，输出
        for(int i = 1; i <= n; i++){ 
            cout << a[i];
        }
        cout << endl;
        return; //回溯1
    }
    for(int i = 1; i <= n; i++) {   //枚举下一步可能的情况
        if(!b[i]) {
            a[x] = i;   //填数
            b[i] = 1;   //标记
            dfs(x + 1); //搜索下一位         
            //回溯
            a[x] = 0;
            b[i] = 0;   
        }
    }
}

int main() {
    cin >> n;
    dfs(1); //从第一位开始填
    return 0;
}