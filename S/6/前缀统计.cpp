#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

int trie[N/*深度*/][26];    //trie[i][j]表示在i后的j字符所指向的下一个节点的编号
int tot = 1;    //节点数量
int ed[N];  //标记完整的单词的个数

void insert(string str) {
    int len = str.length();
    int p = 1;  //记录当前节点的编号
    for(int i = 0; i < len; i++) {
        int ch = str[i] - 'a';  //获得字符
        if(!trie[p][ch]) trie[p][ch] = ++tot;
        p = trie[p][ch];
        ed[p]++;    //以第p个节点结尾的单词个数++
    }
}

int search(string str) {
    int len = str.length();
    int p = 1;
    for(int k = 0; k < len; k++) {
        if(!p) return 0;
        p = trie[p][str[k] - 'a'];  //从头向下查找
    }
    return ed[p];
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        insert(str);
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        string str;
        cin >> str;
        cout << search(str) << endl;
    }
    return 0;
}