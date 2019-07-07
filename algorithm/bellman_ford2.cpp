/*
 *
 * 特別注意： Standard Bellman-ford can detect negative cycle, but it can not apply to undirected graph
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

    typedef pair<pair<int,int>,int> edge;
#define src first.first
#define dst first.second
#define weight second
    vector<edge> vec(2*e);

    for(int i = 0,j,k,l; i < e;i++)
        cin >> vec[i].src >> vec[i].dst >> vec[i].weight;

    const int INF = 666666;
    vector<int> dist(n,INF);
    vector<int> from(n,INF);
    dist[0] = 0;

    bool neg_cycle = false;
    for(int i = 0;i <= n; i++){
        bool update = false;
        for(int j = 0;j < e;j++){
            edge& e = vec[j];
            if(dist[e.src] != INF && from[e.dst] != e.src && dist[e.dst] > dist[e.src] + e.weight)
                { update = true; dist[e.dst] = dist[e.src] + e.weight; from[e.dst] = e.src;}
            if(dist[e.dst] != INF && from[e.src] != e.dst && dist[e.src] > dist[e.dst] + e.weight) 
                { update = true; dist[e.src] = dist[e.dst] + e.weight; from[e.src] = e.dst;}
        }
        if(update == false) break;
        if(update && i == n) { neg_cycle = true; break; }
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
