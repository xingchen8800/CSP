#include <bits/stdc++.h>
using namespace std;

double calc() {
    string str;
    cin >> str;
    if(str[0] == '+') {
        return calc() + calc(); //输入两个数（合并成整体的表达式）
    } else if(str[0] == '-') {
        return calc() - calc();
    } else if(str[0] == '*') {
        return calc() * calc();
    } else if(str[0] == '/') {
        return calc() / calc();
    } else {
        return atof(str.c_str());
    }
}

int main() {
    cout << calc();
    return 0;
}