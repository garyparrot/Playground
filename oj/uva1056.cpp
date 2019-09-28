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

int Case = 1;
int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    int P, R; 
    while(cin >> P >> R && !(P == 0 && R == 0)){
        // vector<vector<int>> network(P);
        const int INF = 4000000;
        vector<vector<int>> d(P, vector<int>(P, INF));

        map<string, int> id;
        int index = 0;

        for(int i = 0;i < R; i++){
            string a,b; cin >> a >> b;
            if(id.find(a) == id.end()) id[a] = index++;
            if(id.find(b) == id.end()) id[b] = index++;
            d[id[a]][id[b]] = 1;
            d[id[b]][id[a]] = 1;
            d[id[a]][id[a]] = 0;
            d[id[b]][id[b]] = 0;
        }

        // floyd
        for(int i = 0;i < P;i++)
            for(int j = 0;j < P ;j++)
                for(int k = 0;k < P; k++)
                    if(d[j][k] > d[j][i] + d[i][k])
                        d[j][k] = d[j][i] + d[i][k];

        // result
        int maxi = 0;
        bool disconnceted = false;
        for(int i =0 ;i < P;i++)
            for(int j = 0;j < P;j++)
            {
                if(d[i][j] == INF)
                    disconnceted = true;
                maxi = max(maxi, d[i][j]);
            }

        cout << "Network " << Case++ << ": " << (disconnceted ? "DISCONNECTED" : to_string(maxi)) << endl << endl;
    }
}
