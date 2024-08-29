#include <bits/stdc++.h>
using namespace std;

//输入数据
int n;          //a_m=n
int depth;      //限制深度
int a[10001];   //记录最短序列

bool dfs(int k) {   //深度（序列长度）
    if(k > depth) {         //到深度限制了
        if(a[depth] == n) { //符合a[m]=n的条件
            return true;
        } else return false;
    }
    bool visited[10001] = {false};  //标记数组
    //i,j从后往前枚举，可以减少重复（小的数更容易被枚举过），同时加快速度（大+大>小+小）
    for(int i = k - 1; i >= 1; i--) {
        for(int j = k - 1; j >= 1; j--) {
            if(a[i] + a[j] <= a[k - 1]) break;  //满足a[k - 1] <= a[i] + a[j]，即如果将a[i]+a[j]填在a[k]上，必然有a[k-1] >= a[k]，则不满足单调性
            if(a[i] + a[j] <= n && !visited[a[i] + a[j]]) {   //a[k]比m都大并且a是单调递增的，则说明a[m]必然!=n；若有a[i]+a[j]<=n，则说明a[k]上可以试着放a[i]+a[j]
                //将a[k]设置为a[i]+a[j]（尝试）
                visited[a[i] + a[j]] = 1;
                a[k] = a[i] + a[j];
                //搜索下一位
                if(dfs(k + 1)) {
                    return true;
                }
                //不需要回溯，因为被标记的数如果不成功就不能要了
            }
        }
    }
    return false;
}

int main(){
    cin >> n;
    if(n == 1) cout << 1 << endl;   //剪枝(bushi)

    depth = 2;  //深度至少是2（不然怎么搜）
    a[1] = 1;   //a[0]=1;
    while(true) {
        if(dfs(2)) {    //dfs搜到了（至少从2层开始搜）
            for(int i = 1; i <= depth; i++) cout << a[i] << " ";
            cout << endl;
            break;
        } else depth++;
    }
    return 0; 
}