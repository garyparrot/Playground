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
        int s; cin >> s;
        vector<int> vec(s);
        for(int i = 0;i < s;i++) cin >> vec[i];

        // test
        for(int i = 0;i < 1005; i++){
            int bak = vec[0];
            for(int i = 0;i < s - 1; i++) vec[i] = abs(vec[i] - vec[i+1]);
            vec[s-1] = abs(vec[s-1] - bak);
        }

        // zero ?
        if(any_of(vec.begin(), vec.end(), [](const int& value) -> bool { return value != 0; }))
            cout << "LOOP" << endl;
        else
            cout << "ZERO" << endl;
    }
}
