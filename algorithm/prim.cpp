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
    typedef pair<int, pair<int,int>> edge;
#define weight first
#define src second.first
#define dst second.second
    vector<vector<edge>> edges(n+1);

    for(int i = 0;i < e;i++){
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back(make_pair(-c,make_pair(a,b)));
        edges[b].push_back(make_pair(-c,make_pair(b,a)));
    }

    priority_queue<edge> que; 
    vector<bool> visited(n+1,false); visited[1] = true;
    vector<edge> spanning_tree;

    for(auto e : edges[1])
        que.push(e);

    while(que.empty() == false){
        edge e = que.top(); que.pop();
        if(visited[e.dst]) continue;

        spanning_tree.push_back(e);
        visited[e.dst] = true;

        for(auto e : edges[e.dst])
            que.push(e);
    }

    for(auto e: spanning_tree){
        cout << e.src << "->" << e.dst << " = " << -e.weight << endl;
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
