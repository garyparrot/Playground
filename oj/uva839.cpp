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

struct mobile{
    ll w[2], l[2];
    mobile* sub[2] = {nullptr, nullptr}; 
};

mobile* build(){
    mobile* mb = new mobile();
    cin >> mb->w[0] >> mb->l[0] >> mb->w[1] >> mb->l[1];
    if(mb->w[0] == 0) mb->sub[0] = build();
    if(mb->w[1] == 0) mb->sub[1] = build();

    return mb;
}
void del_mobile(mobile* mb){
    if(mb->sub[0]) del_mobile(mb->sub[0]);
    if(mb->sub[1]) del_mobile(mb->sub[1]);
    delete mb;
}

bool balance = true;
ll balanced(const mobile* mb){
    ll forcel, forcer;
    int w1 = (mb->w[0] == 0 ? balanced(mb->sub[0]) : mb->w[0]);
    int w2 = (mb->w[1] == 0 ? balanced(mb->sub[1]) : mb->w[1]);
    forcel = w1 * mb->l[0];
    forcer = w2 * mb->l[1];
    balance = balance & forcel == forcer;

    return w1 + w2;
}

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int q; cin >> q;
    while(q--){
        mobile* mb = build();

        if(Case > 1) cout << endl;
        Case++;
        balance = true;
        balanced(mb);
        cout << (balance ? "YES" : "NO") << endl;

        del_mobile(mb);
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
