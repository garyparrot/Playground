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
    int T; cin >> T;
    while(T--){
        long long x, y; cin >> x >> y;
        long long r = y - x;
        long long step = 1, run = 0;
        while(r){
            if(r >= step * 2){
                r -= step * 2; step += 1; run+=2;
            }else{
                break;
            }
        }
        if(r >= step) r -= step, run++;
        if(r) run++;
        cout << run << endl;
    }
}
