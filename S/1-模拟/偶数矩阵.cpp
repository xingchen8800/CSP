#include <bits/stdc++.h>
using namespace std;

int n, a[16][16], b[16][16];
/* a矩阵是原矩阵，b矩阵是填充后*/

/*求解：枚举第一行*/
int Solution(int first_line) {
    memset(b, 0, sizeof(b));    //初始化b矩阵
    //1、将二进制数据转化为一维的01数组
    for(int i = n - 1; i >= 0; i--) {
        if(first_line % 2 == 1) b[0][i] = 1;
        else b[0][i] = 0;
        if(a[0][i] == 1 && b[0][i] == 0) return INT_MAX; /*如果填充的不是0，就不合法*/
    }
    //2、处理剩下的n-1行的同时计算差异
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum = 0;
            if(i > 1) sum += b[i - 2][j];       //不是第一行，取上上方
            if(j > 0) sum += b[i - 1][j - 1];   //不是第一列，取左上方
            if(j < n - 1) sum += b[i - 1][j + 1];   //不是最后一列，取右上方
            b[i][j] = sum % 2;  //确定 b[i][j];
            if(a[i][j] == 1 && b[i][j] == 0) return INT_MAX; /*如果填充的不是0，就不合法*/
            if(a[i][j] != b[i][j]) cnt++;
        }
    }
    //3、返回
    return cnt;
}

int main() {
    cin >> n;
    //输入
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    int _min = 1145;
    //枚举
    for(int i = 1; i < (1 << n); i++) {
        _min = min(_min, Solution(i));
    }
    //输出
    cout << (_min == 1145 ? -1 : _min) << endl;
    return 0;
}