#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    str.resize(unique(str.begin(), str.end()) - str.begin());
    cout << ((str.length() % 2) ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
}
