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
#define to_string_array(begin, end, title) (accumulate(begin, end-1, string(title), [](string str, const auto item) -> string { return str + to_string(item) + " "; }) + to_string(*(end-1)))
using namespace std;

// Declaration {{{
void ONLINE_JUDEGE_SETTING(void);
int dprintf(const char *fmt, ...);
typedef long long ll;
// }}}

double num[100001];

int main(int argc, const char* args[]){
    int n; cin >> n;
    int sum = 0;
    for(int i = 0;i < n;i++){
        double d; cin >> d; sum += (int)d; num[i] = d;
    }

    if(sum < 0)
        for(int i = 0;i < n;i++)
            if(sum < 0 && ceil(num[i]) > int(num[i]))
                cout << ceil(num[i]) << endl, ++sum;
            else
                cout << (int)num[i] << endl;
    else if(sum > 0)
        for(int i = 0;i < n;i++)
            if(sum > 0 && floor(num[i]) < int(num[i]))
                cout << floor(num[i]) << endl, --sum;
            else
                cout << (int)num[i] << endl;
    else
        for(int i = 0;i < n;i++)
            cout << (int)num[i] << endl;
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
