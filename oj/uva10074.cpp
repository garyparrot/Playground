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
    int m,n;
    while(cin >> m >> n && !(m == 0 && n == 0)){
        vector<vector<int>> vec(m, vector<int>(n));
        vector<vector<int>> ktop(m, vector<int>(n));
        vector<vector<int>> kleft(m, vector<int>(n));
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++) {
                cin >> vec[i][j];
                if(vec[i][j] == 0)
                    ktop[i][j] = kleft[i][j] = 1;
                if(vec[i][j] == 0 && i != 0)
                    ktop[i][j] = ktop[i-1][j] + 1;
                if(vec[i][j] == 0 && j != 0)
                    kleft[i][j] = kleft[i][j-1] + 1;
            }

        int maxival = 0;
        for(int i = 0;i < m; i++)
            for(int j = 0;j < n;j++){
                int topbase_mostleft = kleft[i][j];
                for(int k = 0;k < ktop[i][j];k++)
                    topbase_mostleft = min(topbase_mostleft, kleft[i-k][j]);
                int leftbase_mosttop = ktop[i][j];
                for(int k = 0;k < kleft[i][j];k++)
                    leftbase_mosttop = min(leftbase_mosttop, ktop[i][j-k]);

                int v1 = topbase_mostleft * ktop[i][j];
                int v2 = leftbase_mosttop * kleft[i][j];

                cout << ktop[i][j] << " " << topbase_mostleft << " "<< v1 << " " << i << j << endl;

                maxival = max(maxival, max(v1,v2));
            }

        cout << maxival << endl;
    }
}
