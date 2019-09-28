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
    map<string, set<string>> mapp;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        string country, name;
        cin >> country; getline(cin, name);

        mapp[country].insert(name);
    }

    for(auto pair : mapp){
        cout << pair.first << " " << pair.second.size() << endl;
    }
}
