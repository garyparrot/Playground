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
    int N;
    vector<int> vec;
    vector<int> lazy;

    // query [a,b]
    int query(int a, int b, int k, int x, int y){
        if(y < a || b < x) return 0;                
        if(a <= x && y <= b) return vec[k] + lazy[k] * (y - x + 1); 
        // propagate modification to next level
        vec[k] += lazy[k] * (y - x + 1);
        lazy[k*2] += lazy[k];
        lazy[k*2+1] += lazy[k];
        lazy[k] = 0;
        // query 
        return query(a,b,k*2, x, (x+y)/2) + query(a,b,k*2+1,(x+y)/2+1,y);
    }
    int query(int a, int b) { return query(a,b,1,0,N-1); }

    void update(int k, int x){
        k += N; vec[k] += x;

        for(k /= 2;k;k /= 2) vec[k] = vec[k*2] + vec[k*2+1];
    }
    void update_range(int a, int b, int value, int k, int x, int y){
        if(y < a || b < x ) return;
        if(a <= x && y <= b) { lazy[k] += value; return; }
        // update itself and propagate modification to next level
        vec[k] += value * (min(b, y) - max(a,x) + 1);
        vec[k] += lazy[k] * (y - x + 1);
        lazy[k*2] += lazy[k];
        lazy[k*2+1] += lazy[k];
        lazy[k] = 0;
        // update two range
        update_range(a,b,value,k*2,x,(x+y)/2);
        update_range(a,b,value,k*2+1,(x+y)/2+1, y);
    }
    void update_range(int l, int r, int value){ update_range(l,r,value, 1, 0, N-1); }

    segment_tree(int size){
        N = 1 << (int)ceil(log2(size));
        vec.resize(N << 1);
        lazy.resize(N << 1);
    }
};

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int n; cin >> n;

    segment_tree st(n);
    for(int i = 0;i < n;i++) { int t; cin >> t; st.update(i,t); }
    cout << "Update OK" << endl;

    int l, r, v;
    string str;
    while(cin >> str){
        if(str == "Query") { cin >> l >> r; cout << st.query(l,r) << endl; }
        if(str == "UpdateRange") 
        {
            cin >> l >> r >> v; st.update_range(l,r,v); 
            for(int i : st.vec) cout << i << " " ; cout << endl;
            for(int i : st.lazy) cout << i << " " ; cout << endl;
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
