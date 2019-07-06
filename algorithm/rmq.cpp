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
#define to_string_array3(begin, end, title) (accumulate(begin, end-1, string(title), [](string str, const auto item) -> string { return str + to_string(item) + " "; }) + to_string(*(end-1)))
#define to_string_array2(begin, end) (accumulate(begin, end-1, string(""), [](string str, const auto item) -> string { return str + to_string(item) + " "; }) + to_string(*(end-1)))
#define string_array3(begin, end, title) (accumulate(begin, end-1, string(title), [](string str, const auto item) -> string { return str + item + " "; }) + *(end-1))
#define string_array2(begin, end) (accumulate(begin, end-1, string(""), [](string str, const auto item) -> string { return str + item + " "; }) + *(end-1))
using namespace std;

// {{{ Declaration
void ONLINE_JUDEGE_SETTING(void);
int dprintf(const char *fmt, ...);
typedef long long ll;
// }}}

/*
 * RMQ 
 * Waste you O(nlogn) for preprocessing the query array
 * foreach rmq(n,m) it stands for minimum value in [n,n+2^m)
 *
 * After that you can query any range [l,r) in god damn constant time, insame.
 * Compare to Segment tree, Segment tree require O(logn) for query but it is a online data structure.
 */

typedef vector<vector<int>> container;
int range(container& con, int l, int r){
    int len = r - l;
    int pow = floor(log2(len)); 
    return min( con[l][pow], con[r - (1 << pow)][pow] );
}

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int n; cin >> n;
    vector<vector<int>> rmq(n, vector<int>(1));
    for(int i = 0;i < n;i++) cin >> rmq[i][0];

    for(int i = 1, j = 1;j < n;i++, j*=2)
        for(int k = 0;k + j < n;k++){
            int minv = min( rmq[k][i-1], rmq[k+j/2][i-1] );
            rmq[k].push_back(minv);
        }

    int l, r;
    while(cin >> l >> r){
        cout << "min value in " << "[" << l << ","<< r << "]"<< range(rmq, l, r) << endl;
    }
}

// {{{ Debugging & Online Judge
int dprintf(const char *fmt, ...){
    #ifndef ONLINE_JUDGE
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
    clog.rdbuf(nullptr);
    #endif
}
// }}}
