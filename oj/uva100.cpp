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

int cycle[3*10000 + 10000];

int eval(long long value){
    if(value == 1) return 1;
    if(cycle[value]) return cycle[value];

    long long base = value;
    while(value != 1){
        value = (value % 2) ? (value * 3 + 1) : (value / 2);
        ++cycle[base];
    }

    return ++cycle[base];
}

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);

    int a,b;
    while(cin >> a >> b){
        int maxi = 0;
        for(int i = a; i <= b;i++)
            maxi = max(maxi, eval(i));
        cout << a << " " << b << " " << maxi << endl;
    }
    
}
