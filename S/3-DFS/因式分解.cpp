#include <iostream>
using namespace std;

int a[101], n, sum = 1;

void dfs(int x) {   //x被分解
    if(x) { //只有因数1了
        a[sum] = 1;
        cout << n << "=";
        for(int i = 1; i < sum; i++) cout << a[i] << "*";   //输出
        cout << a[sum] << endl;
        return ;        //回溯1
    } 
    for(int i = x; i > 1; i--) {
        if(x % i == 0) {    //i是x的因子
            a[sum] = i; //存储
            sum++;  
            dfs(x / i); //将x / i作为下一个被分解的数
            //回溯2
            a[sum] = 0;
            sum--;
        }
    }
}
int main() {
    cin >> n;
    dfs(n);
    return 0;
}