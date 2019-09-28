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

char cboard[101][101];
int stepx[]  = {1,1,2,2,-1,-1,-2,-2};
int stepy[]  = {-2,2,1,-1,2,-2,1,-1};
int n;

#define in_range(i) (0 <= (i) && (i) < n)

void rec(int i, int j, char c){
    if(cboard[i][j] != 0)
        return;
    cboard[i][j] = c;
    for(int k = 0;k < 8;k++)
        if(in_range(i + stepy[k]) && in_range(j + stepx[k]))
            cboard[i + stepy[k]][j + stepx[k]] = (c == 'W') ? 'B' : 'W';
    for(int k = 0;k < 8;k++)
        if(in_range(i + stepy[k]) && in_range(j + stepx[k]))
            rec(i + stepy[k], j + stepx[k], (c == 'W') ? 'B' : 'W');
}

int main(int argc, const char* argsp[]){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            rec(i,j,'W');

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++)
            cout << cboard[i][j];
        cout << endl;
    }
        
}
