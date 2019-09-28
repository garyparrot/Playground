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
#include <climits>

using namespace std;

int num[5000];

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int cases, r;
    for(cin >> cases ; cases--; ){
        cin >> r; 

        for(int i = 0;i < r;i++) cin >> num[i];

        sort(num, num + r);

        int sum = 0;
        for(int i = 0;i < r;i++) sum += abs(num[r/2] - num[i]);
        cout << sum << endl;
    }
}
