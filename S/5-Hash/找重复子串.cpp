#include <bits/stdc++.h>
using namespace std;

const unsigned long long B = 131;

string str1, str2;
unsigned long long hashStr1, hashStr2[10001];

unsigned long long GetHash(string s) {
    unsigned long long result = 0;
    for(int i = 0; i < s.length(); i++) {
        result = result * B + s[i];
    }
    return result;
}

int main() {
    cin >> str1 >> str2;
    
    hashStr1 = GetHash(str1);

    hashStr2[1] = (unsigned long long)str2[0];
    for(int i = 2; i < str2.length(); i++) {
        hashStr2[i] = hashStr2[i - 1] * B + str2[i - 1];    //求出str2的每个[0,i]形式的子串的Hash值
    } 

    int ans = 0;
    const unsigned long long k = pow(B, str1.length());  //B^len_str1，因为B^(len_b - len_a + 1)中len_a = i,len_b = i + len_a，所以len_b - len_a + 1 = len_a + 1 = str1.length()
    for(int i = 0; i + str1.length() <= str2.length(); i++) {
        if(hashStr2[i + str1.length()] - hashStr2[i] * k == hashStr1) ans++;
        //^求[i + 1, i + len_str1]的区间Hash值，即减法性质公式
    }
    cout << ans;
    return 0;
}