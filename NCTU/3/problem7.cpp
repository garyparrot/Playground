#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    while(cin >> n){
        typedef pair<pair<int,int>, int> work;
#define ws first.first
#define wf first.second
#define wage second
        vector<work> works(n);
        for(int i = 0 ;i < n;i++)
            cin >> works[i].ws, cin.ignore(), cin >> works[i].wf, cin.ignore(), cin >> works[i].wage;

        // dp(i) 為 i 時段的最大獲利
        // dp(0) = 0
        // dp(i) = max(dp(i-1), dp(ws-1) + profit)   當i這裡有一個工作結束時
        // dp(i) = dp(i-1)                           否則
        vector<int> dp(401,0);

        for(int i = 1;i < 401;i++)
            for(int j = 0;j < n;j++)
                if(works[j].wf == i)
                    dp[i] = max(dp[i],max(dp[i-1], dp[works[j].ws] + works[j].wage));
                else
                    dp[i] = max(dp[i], dp[i-1]);

        cout << dp[400] << endl;
    }
}
