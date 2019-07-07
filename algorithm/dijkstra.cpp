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

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    typedef pair<pair<int,int>,int> edge;

#define src first.first
#define dst first.second
#define weight second

    // dijkstrac with priority_queue, O(n+mlogm)
    int n,e;
    cin >> n >> e;

    vector<vector<edge>> edges(n);
    
    for(int i = 0;i < e;i++){
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back(make_pair(make_pair(a,b),c));
        edges[b].push_back(make_pair(make_pair(b,a),c));
    }

    const int INF = 6666666;
    int srcpoint;
    while(cin >> srcpoint){
        vector<int> dest(n, INF);
        vector<bool> visited(n, false);
        priority_queue<pair<int,int>> que;
        dest[srcpoint] = 0;
        que.push(make_pair(0, srcpoint));

        while(!que.empty()){
            int target = que.top().second; que.pop();
            if(visited[target]) continue;
            visited[target] = true;
            for(auto e : edges[target])
                if(dest[e.dst] > dest[e.src] + e.weight){
                    dest[e.dst] = dest[e.src] + e.weight;
                    que.push(make_pair(-dest[e.dst], e.dst));
                }
        }
        for(int i = 1;i < n;i++){
            cout << "For " << i << " shortest weight is " << dest[i] << endl;
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
