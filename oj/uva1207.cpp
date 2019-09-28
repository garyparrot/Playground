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
    int s1,s2; string a, b;
    while(cin >> s1 && getline(cin, a) && cin >> s2 && getline(cin, b)){
        vector<vector<int>> dp(s1+2, vector<int>(s2+2));
        s1++, s2++;
        a = " " + a;
        b = " " + b;
        for(int i = 0;i <= s1; i++)
            dp[i][0] = i;
        for(int i = 0;i <= s2; i++)
            dp[0][i] = i;
        for(int i = 1;i <= s1; i++)
        {
            for(int j = 1;j <= s2;j++){
                if(a[i] == b[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1));
            }
        }

        cout << dp[s1][s2] << endl;
    }
}
