#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const ull B = 128, MOD = 1e9;
ull subStrHash = 0, strHash[10000001] = {0};
string str;

int main() {
    cin >> str;
    for(int i = 0; i < str.length(); i++) {
        strHash[i + 1] = strHash[i] * B + str[i];
    }
    for(int i = 1; i <= str.length(); i++) {    //枚举子串长度
        if(str.length() % i != 0) continue;     //剪枝操作
        subStrHash = strHash[i];    //substr:[0, i] 子串Hash值
        int j;
        for(j = i; j <= str.length(); j += i) { //滑动窗口，j是左端点，j+1是右端点
            if(strHash[j + i] - strHash[j] * (ull)pow(B, i) != subStrHash) break;    //[j + 1, j + i] == [0, i]
            //^验证[j+1,j+i]区间是否与[0,i]的Hash值相等
        }
        if(j == str.length()) {     //验证完成
            cout << str.length() / i << endl;
            return 0;
        }
    }
    return 0;
}