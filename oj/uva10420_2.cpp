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
    map<string, set<string>> country;
    int n; cin >> n;
    while(n--){
        string con; string name;
        cin >> con; getline(cin, name);
        country[con].insert(name);
    }

    for(auto p : country)
        cout << p.first << " " << p.second.size() << endl;
}
