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

int table[(int)sqrt(1e9)+5];
vector<int> primes;

void build(int ceiling){
    for(int i = 2;i < ceiling;i++){
        if(table[i] == 0){
            primes.push_back(i);
            for(int j = i; j < ceiling; j+=i) table[j] = 1;
        }
    }
}

int main(int argc, const char* argsp[]){
    int T; cin >> T;

    build(5 + sqrt(1000000000));

    while(T--){
        int a,b,i;
        int maxvalue = 0, maxdiv = 0;
        for(cin >> a >> b, i = a;i <= b;i++){
            vector<int> coc;
            int val = i;
            for(const int p : primes){
                if(p > val) break;
                int cc= 0;
                while(val % p == 0 && val != 1) cc++, val /= p;
                coc.push_back(cc+1);
            }

            val = 1;
            for(int i : coc) val *= i;

            if(val > maxdiv)
                maxvalue = i, maxdiv = val;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", a,b,maxvalue, maxdiv);
    }
}
