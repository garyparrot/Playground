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
    int a,b;
    while(cin >> a >> b && !(a == 0 && b == 0)){
        set<int> s1, s2;
        for(int i = 0;i < a;i++) { int s; cin >> s; s1.insert(s); }
        for(int i = 0;i < b;i++) { int s; cin >> s; s2.insert(s); }
        set<int> d1(s1.begin(), s1.end()); 
        set<int> d2(s2.begin(), s2.end());
        for(int value : s2) d1.erase(value);
        for(int value : s1) d2.erase(value);
        cout << min(d1.size(), d2.size()) << endl;
    }
}
