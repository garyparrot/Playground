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
    while(true){
        vector<int> ceilings, floors;
        int num; string res; char c;

        while(cin >> num >> c && num != 0){
            getline(cin, res);
            if(res == "oo high")
                ceilings.push_back(num);
            if(res == "oo low")
                floors.push_back(num);
            if(res == "ight on"){
                break;
            }
        }
        if(num == 0) return 0;

        int cheat = 0;
        for(int val : ceilings)
            cheat = cheat || num >= val;
        for(int val : floors)
            cheat = cheat || num <= val;

        cout << (cheat ? "Stan is dishonest" : "Stan may be honest") << endl;
    }
}
