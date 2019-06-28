/*
 * Stay away from my code, y'all :p
 *
 * QAQ
 *
 * Before you upload your sh*tty code. Pleause MAKE SURE.
 * 1. You have passed all the public test cases.
 * 2. Make sure each part of your code working fine.
 * 3. Remove any logging message.
 * 4. Your variable won't overflow.
 * 5. Perform your alogrithm on your paper.
 * 6. Pray to the God of AC.
 * 7. Sacrifice your soul for the king of Competeive Programming.
 * 8. Sign up the contract for selling your body to the daemon of Codeforces.
 *
 * Then you upload your code
 */
#include <bits/stdc++.h>
#define MAX_INT std::numeric_limits<int>::max()
#define MAX_INT64 std::numeric_limits<int>::max()
#define ESP 1e-6
using namespace std;

// Declaration {{{
void ONLINE_JUDEGE_SETTING(void);
int dprintf(const char *fmt, ...);
typedef long long ll;
// }}}

int candy[200005] = {0};
int selected[200005] = {0};

int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int maxi = 0;
        vector<int> marker;
        for(int i = 0;i < n;i++){
            int type ; cin >> type ; 
            if(!selected[type]) {selected[type] = ++maxi; marker.push_back(type); }
            ++candy[selected[type]];
        }

        sort(candy + 1, candy + maxi + 1, [](const int a, const int b) -> bool { return a > b; });

        int ans = 0, upper = MAX_INT;
        for(int i = 1;i <= maxi && upper > 0;i++){
            if(candy[i] < upper)
                ans += candy[i], upper = candy[i];
            else
                upper = upper - 1, ans += upper;
        }

        cout << ans << endl;

        for(int mark : marker) selected[mark] = 0;
        for(int i = 1;i <= maxi;i++) candy[i] = 0;
    }
}

// Debugging & Online Judge {{{
int dprintf(const char *fmt, ...){
    #ifdef ONLINE_JUDGE
    va_list vlist;
    va_start(vlist, fmt);
    int r = vprintf(fmt, vlist);
    va_end(vlist);
    return r;
    #endif
    return 0;
}

void ONLINE_JUDEGE_SETTING(){
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); clog.tie(0); cerr.tie(0);
    #endif
}
// }}}
