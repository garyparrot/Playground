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

int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    string a, b;
    cin >> a >> b;
    int counter = 0;
    int blen = b.length();
    int base = accumulate(b.begin(), b.end(), 0, [](int val, const char& c) -> int { return val + c == '1'; });

    for(int i=0,len=a.length();i < len - blen + 1;i++){
        int cc = accumulate(a.begin() + i, a.begin() + i + blen, 0, [](int val, const char& c) -> int{ return val + c =='1'; });
        if((base + cc) % 2 == 0)
            counter += 1;
    }
    cout << counter << endl;
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
