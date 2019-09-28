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
#include <sstream>
#include <map>
#include <string>
#include <numeric>

using namespace std;

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int T; cin >> T; int Case = 1;
    string s; getline(cin, s); getline(cin, s);
    while(T--){
        cout << "Case #" << Case++ << ":" << endl;
        while(getline(cin, s) && s != ""){
            stringstream ss(s);
            int pos = 0;
            string word;
            while(ss >> word)
                if(pos < word.length())
                    cout << word[pos], pos++;
            cout << endl;
        }
        if(T != 0)
            cout << endl;
    }
}
