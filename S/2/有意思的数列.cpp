#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > qmax;
priority_queue<int, vector<int>, greater<int> > qmin;

int main() {
    int n, x, a, b, c;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        qmax.push(x);
        qmin.push(x);
    }
    //求最小值
    while(qmax.size() > 2) {
        a = qmax.top();
        qmax.pop();
        b = qmax.top();
        qmax.pop();
        c = qmax.top();
        qmax.pop();
        qmax.push(a * b * c + 1);
    }
    if(qmax.size() == 2) {
        a = qmax.top();
        qmax.pop();
        b = qmax.top();
        qmax.pop();
        qmax.push(a * b + 1);
    }
    //求最大值
    while(qmin.size() > 2) {
        a = qmin.top();
        qmin.pop();
        b = qmin.top();
        qmin.pop();
        c = qmin.top();
        qmin.pop();
        qmin.push(a * b * c + 1);
    }
    if(qmin.size() == 2) {
        a = qmin.top();
        qmin.pop();
        b = qmin.top();
        qmin.pop();
        qmin.push(a * b + 1);
    }
    cout << qmin.top() - qmax.top();
}