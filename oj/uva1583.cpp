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
    static int numbers[100500];

    for(int i = 1;i < 100500;i++){
        int gen = i, val = i;
        while(val) gen += val % 10, val /= 10;

        if(numbers[gen] == 0)
            numbers[gen] = i;
    }

    int t; cin >> t;
    while(t--){
        int a; cin >> a;
        cout << numbers[a] << endl;
    }

}
