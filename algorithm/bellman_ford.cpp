/*
 * Bellman-Ford Algorithm
 * 1. Can handle negative weight edge.
 * 2. Could detect negative cycle.
 *
 * NOTE THAT YOU HAVE TO FINISH ONE NODE THEN DO ANOTHER
 * YOU CAN'T MIX THE ORDER, i.e. do 1->2 then do 3->4
 * but you can 1->2 1->3 1->4 ... after all the edge start from 1 finished, you iterate next node
 * Otherwise your bellman-ford will failed
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

int Case = 1;

int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int n,e; cin >> n >> e;    

    vector<vector<pair<int,int>>> vec(n);

    for(int i = 0,j,k,l; i < e;i++){
        cin >> j >> k >> l;
        vec[j].push_back(make_pair(k,l));
        vec[k].push_back(make_pair(j,l));
    }

    const int INF = 666666;
    vector<int> dist(n,INF);
    vector<int> from(n,INF);
    dist[0] = 0;

    bool neg_cycle = false;
    for(int i = 0;i <= n; i++){
        bool update = false;
        for(int j = 0;j < n;j++){
            for(auto e : vec[j]){
                if(from[j] != e.first && dist[e.first] > dist[j] + e.second){
                    dist[e.first] = dist[j] + e.second;
                    from[e.first] = j;
                    update = true;
                }
            }
        }
        if(update == false) break;
        if(update && i == n - 1) { neg_cycle = true; break; }
    }

    if(neg_cycle) cout << "NEG" << endl;
    for(auto i : dist){ cout << i << endl; }
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
