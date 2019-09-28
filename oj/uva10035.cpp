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
    long long a, b;
    while(cin >> a >> b && !(a == 0 && b == 0)){
        long long total = 0, carry = 0;
        while(a || b){
            carry = (a % 10 + b % 10 + carry) >= 10;
            total += carry;
            a /= 10, b /= 10;
        }
        if(total == 0)
            cout << "No carry operation." << endl;
        else if(total == 1)
            cout << "1 carry operation." << endl;
        else
            cout << total << " carry operations.\n";
    }
}
