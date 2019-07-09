#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector<int> num(2*n);

        for(int i = 0;i < n;i++) cin >> num[i];
        for(int i = 0;i < n-1;i++) num[i+n] = num[i];

        const int INF = -6666666;
        int l = 0, r = 0, sum = 0, ans = INF;
        // first => start_position, second => prefix_sum
        deque<pair<int,int>> state;
        state.push_back(make_pair(-1, 0));
        for(int i = 0; i < 2*n-1;i++){
            // 過期的狀態
            if(i - state.front().first > n) 
            {
                // cout << "Pop state" << endl;
                state.pop_front();
            }
            // 取得狀態
            auto s = state.front();
            // cout << "Get state" << s.first << " " << s.second << endl;

            sum = sum + num[i];
            ans = max(ans, sum - s.second);
            // cout << "Current ans " << ans << " sum = " << sum << " " << num[i] << endl;

            // 塞入新狀態
            pair<int,int> p = make_pair(i, sum);

            while(state.empty() == false && state.back().second >= p.second)
                state.pop_back();
            // cout << "push " << p.first << " " << p.second << endl;
            state.push_back(p);
        }

        cout << ans << endl;
    }
}
