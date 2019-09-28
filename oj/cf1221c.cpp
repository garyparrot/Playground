#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <numeric>

using namespace std;

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int q; cin >> q;
    while(q--){
        int a,b,c;cin >>a>>b>>c;
        int must = min(a,b);
        int rest = (a+b+c) - must*2;
        if(rest >= must){
            cout << must << endl;
        }else{
            int ok = rest; must -= rest;
            ok += must * 2 / 3;
            cout << ok << endl;
        }
    }
}
