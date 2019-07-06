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

struct segment_tree{
    int size;
    int N;
    vector<int> vec;

    // return the sum of [a,b]
    int sum(int a,int b){
        a += N;     // move a to the corresponding left node
        b += N;     // move b to the corresponding right node
        int s = 0;  // sum 
        while(a <= b){
            if(a % 2 == 1) s += vec[a++]; // if a's parent is part of the query range, add it
            if(b % 2 == 0) s += vec[b--]; // if b's parent is part of the query range, add it
            a/=2; b/=2;     // move query range to the next level(their parent)
        }
        return s;
    }
    void add(int k, int x){
        k += N;
        vec[k] += x;
        for(k/= 2; k>= 1; k/=2)
            vec[k] = vec[k*2] + vec[k*2+1];
    }

    segment_tree(int n){
        int pow2 = ceil(log2(n));
        N = 1 << (pow2);
        size = 1 << (pow2 + 1);
        vec.resize(size);
        fill(vec.begin(), vec.end(), 0);
    }
};

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();

    int n; cin >> n;
    segment_tree st(n);
    for(int i = 0;i < n;i++) {int t; cin >> t; st.add(i,t);}
    clog << to_string_array3(st.vec.begin(), st.vec.end(), "SD") << endl;

    int l,r;
    while(cin >> l >> r){
        cout << st.sum(l,r) << endl;
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
