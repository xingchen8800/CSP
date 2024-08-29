#include <iostream>
using namespace std;

string str;
char s[220];
int k, top = 0;

int main() {
    //输入
    cin >> str;
    cin >> k;
    //核心：贪心
    int i = 0;
    while(i < str.length()) {
        if(k == 0) {    //不需要删除
            s[++top] = str[i++];
            continue;
        } 
        if(top == 0) s[++top] = str[i++]; //空栈进栈
        else {  //维护单调栈
            if(str[i] < s[top]) {  //当栈顶元素比待删数大时，弹出栈顶 
                top--;
                k--;
            } else {    //入栈
                s[++top] = str[i++];
            }
        }
    }
    //删数
    while(k > 0) {
        top--;
        k--;
    }
    //去除无效0
    int j = 1;
    while(s[j] == '0' && j < top) {
        j++;
    }
    //输出
    for(; j <= top; j++) cout << s[j];
    return 0;
}