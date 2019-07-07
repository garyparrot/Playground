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

struct unite_set{
    vector<int> p;
    vector<int> s;

    int find(int x) { while(p[x] != x) x = p[x]; return x; }
    int same(int a,int b) { return find(a) == find(b); }
    void unite(int a,int b){
        while(p[a] != a) a = p[a];
        while(p[b] != b) b = p[b];
        // connect a to b, b should be bigger set
        if(s[b] < s[a]) swap(a,b);
        s[b] += s[a];
        p[a] = b;
    }

    unite_set(int n){
        p.resize(n);
        s.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(s.begin(), s.end(), 1);
    }
};

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int n,e; cin >> n >> e;
    typedef pair<int, pair<int,int>> edge;
#define weight first
#define src second.first
#define dst second.second
    vector<edge> edges(2*e);

    for(int i = 0;i < e;i++){
        int a, b, c; cin >> a >> b >> c;
        edges[2*i+0].src = a; edges[2*i+0].dst = b; edges[2*i+0].weight = c;
        edges[2*i+1].src = b; edges[2*i+1].dst = a; edges[2*i+1].weight = c;
    }

    sort(edges.begin(), edges.end());

    vector<edge> spanning_tree;
    unite_set set(n+1);
    for(int i = 0, j = 0; i < edges.size() && j < n - 1;i++){
        edge e = edges[i];
        if(!set.same(e.src, e.dst))
        {
            j++, spanning_tree.push_back(e), set.unite(e.src, e.dst);
        }
    }
    if(spanning_tree.size() == n - 1) cout << "Found" << endl;
    for(auto e : spanning_tree)
        cout << e.src << " " << e.dst << " " << e.weight << endl;
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
