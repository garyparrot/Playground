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

struct ansset{
    int value;
    int perm;

    bool operator<(const ansset& as) const { return value < as.value; }
    bool operator==(const ansset& as) const { return value == as.value; }

    ansset(){}
    ansset(int v,int p) : value(v), perm(p) {}
};

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int shit[] = {11,3,423,12,23,423,5,23423,324,123,12,31,21,123,432,1,4321,213};
    int n = sizeof(shit) / sizeof(int);

    set<ansset> a,b;
    for(int i = 0;i < (1 <<(n/2));i++){
        int sum = 0;
        for(int k = i, offset = 0;k;k >>=1, offset++)
            sum += (k & 0x1) * shit[offset];
        a.insert(ansset(sum, i));
    }
    for(int i = 0;i < (1 <<(n - n/2));i++){
        int sum = 0;
        for(int k = i, offset = 0;k;k >>=1, offset++)
            sum += (k & 0x1) * shit[n/2+offset];
        b.insert(ansset(sum, i));
    }

    cout << "A: "; for(auto& i : a) cout << i.value << " "; cout << endl;
    cout << "B: "; for(auto& i : b) cout << i.value << " "; cout << endl;

    int q;
    while(cin >> q){
        for(auto i : a){
            auto j = b.find(ansset(q - i.value,0));
            if(j != b.end() && i.value + (*j).value == q)
            {
                int a = i.perm;
                int b = (*j).perm;
                for(int s = a, offset = 0;s;s >>=1, offset++) if(s & 0x1) cout << shit[offset] << "+";
                for(int s = b, offset = 0;s;s >>=1, offset++) if(s & 0x1) cout << shit[n/2+offset] << "+";
                cout << " = " << q << endl;
                
            }
        }
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
