#include <bits/stdc++.h>
using namespace std;

const int INF = -9000000;

int value(string c){
    if(c == "I") return 1;
    if(c == "V") return 5;
    if(c == "X") return 10;
    if(c == "L") return 50;
    if(c == "C") return 100;
    if(c == "D") return 500;
    if(c == "M") return 1000;
    if(c == "IV") return 4;
    if(c == "IX") return 9;
    if(c == "XL") return 40;
    if(c == "XC") return 90;
    if(c == "CD") return 400;
    if(c == "CM") return 900;
    if(c == "") return 100000;

    return INF;
}
int five(string c){ return c == "V" || c == "L" || c == "D"; }

int eval(const string& str, int i, string l3, string l2, string l1){
    if(i == str.length()) return 0;
    string l0 = str.substr(i,1);
    if(value(l0) == INF) return INF;
    if(l3 == l2 && l2 == l1 && l1 == l0) return INF;
    if(l1 == l0 && five(l1) && five(l0)) return INF;
    int dec = 0;
    if(value(l0) > value(l1)) {
        dec = value(l1);
        l0 = l1 + l0;
        l1 = l2;
        l2 = l3;
        if(value(l0) == INF || value(l0) > value(l1))
            return INF;
    }
    return value(l0) + eval(str, i + 1, l2, l1, l0) - dec;
}

int main(void){
    string s;
    while(cin >> s){
        cout << max(eval(s,0,"","",""), 0) << endl;
    }
}
