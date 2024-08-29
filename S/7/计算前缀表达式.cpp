#include <bits/stdc++.h>
using namespace std;

bool isAnOperator(char _character) {
    if(_character == '+' || _character == '-' || _character == '*' || _character == '/') return true;
    return false;
}

int main() {
    int k;
    char s[1001][101];  //输入(1001个长度为101的字符串)
    int count = 1;  //标记字符串的数量
    double answer[1001] = {0};    //记录一块的答案
    int p = 0;      //answer的索引，即当前运算符后的数
    while(cin >> s[k]) k++; //获得输入
    count--;    //[1,count]
    for(int i = count; i >= 1; i--) {   //从后往前找运算符
        if(isAnOperator(s[i][0])) { //是运算符，就计算结果
            if(s[i][0] == '+') {
                answer[p - 1] = answer[p] + answer[p - 1]; //存储作为整体的表达式，p从后往前存，p-1在p的后面
                answer[p] = 0;                   //不写也可，直接覆盖
            } else if(s[i][0] == '-') {
                answer[p - 1] = answer[p] - answer[p - 1];
                answer[p] = 0;
            } else if(s[i][0] == '*') {
                answer[p - 1] = answer[p] * answer[p - 1];
                answer[p] = 0;
            } else {
                answer[p - 1] = answer[p] / answer[p - 1];
                answer[p] = 0;
            }
            p--;
        } else {    //是数，直接加入
            answer[++p] = atof(s[i]);   //atof(): (const char *) to double
        }
    }
    cout << answer[1];
}