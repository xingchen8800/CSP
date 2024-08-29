#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    stack<int> st;      //单调栈
    int tmp, ans = 0;
    cin >> n;
    while(n--) {
        cin >> tmp;
        while(!st.empty() && st.top() <= tmp) st.pop();   //维护单调栈，必须大于！！！等于也！要！出！栈！（破音）
        ans += st.size();   //维护完了再累加，防止反着看（单调性没了）
        st.push(tmp);   //tmp入栈
    }
    cout << ans;
    return 0;
}