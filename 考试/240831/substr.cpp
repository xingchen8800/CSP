#include<bits/stdc++.h>
using namespace std;

int n, q, x, p[300005]; //a[l] = x, p[x] = l
long long k, c[300005]; //c[i] = 开头为1~i的子串数量

int main(){
    cin >> n >> q;

	for(int i = 1;i <= n; i++){
		cin >> x;
		p[x] = i; //映射
	}

	for(int i = 1;i <= n; i++)
		c[i] = c[i - 1] + n - p[i] + 1;  //前缀和

	while(q--) {
		cin >> k;   //第k大
		int l = lower_bound(c, c + n + 1, k) - c;   //寻找第一个<=k的元素下表
		cout << p[l] << " " << k - c[l - 1] + p[l] - 1 << endl;
	}
	return 0;
}