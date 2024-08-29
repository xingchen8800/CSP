#include <bits/stdc++.h>
using namespace std;

int N, n;
const string str = "!@#$%^&*";

void Solution(int n) {
    char s[11][11];
    //第一步：输入
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    //第二步：模拟
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == '.') {    //需要进行填充
                for(int k = 0; k < 9; k++) {    //k为被填充的字符在str中的下标
                    bool ok = true;         //标记是否可以填充str[k]到s[i][j]中
                    //判断
                    if(i > 0 && s[i - 1][j] == str[k]) ok = false;      //不是第一行并且与上面的不同
                    if(i < n - 1 && s[i + 1][j] == str[k]) ok = false;  //不是最后一行并且与下面的不同
                    if(j > 0 && s[i][j - 1] == str[k]) ok = false;      //不是最左边并且与左边的不同
                    if(j < n - 1 && s[i][j + 1] == str[k]) ok = false;  //不是最右边并且与右边的不同
                    if(ok) {//如果可以填充str[k]到s[i][j]中
                        s[i][j] = str[k];   //填充
                        break;              //结束循环
                    }
                }
            }
        }
    }
    //第三步：输出
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }
    return;     //完成
}

int main() {
    cin >> N;
    while(N--) {
        cin >> n;
        Solution(n);
    }
    return 0;
}