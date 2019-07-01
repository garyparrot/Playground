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

vector<int> inorder, postorder;

int k = 0;
int node[10005][3];
int spawn_node() { node[k][0] = node[k][1] = node[k][2] = -1; return k++; }
int& lc(int index) { return node[index][0]; }
int& rc(int index) { return node[index][1]; }
int& vl(int index) { return node[index][2]; }

int mapping_in[10005], mapping_post[10005];

int build(int inl, int inr, int postl, int postr){
    dprintf("Build %d~%d %d~%d\n", inl, inr, postl, postr);
    if(inl >= inr && postl >= postr) return -1;
    assert(inr - inl == postr - postl);
    int mid_pos = mapping_in[postorder[postr-1]];

    int node = spawn_node();
    int lcount = mid_pos - inl;
    lc(node) = build(inl, mid_pos, postl, postl + lcount);
    rc(node) = build(mid_pos+1, inr, postl + lcount, postr-1);
    vl(node) = inorder[mid_pos];
    dprintf("Create node %d with value %d and l=%d r=%d\n", node, vl(node), lc(node), rc(node));

    return node;
}

pair<int,int> dfs(int node){
    if(node == -1) return make_pair(99999999, -666);
    if(lc(node) == -1 && rc(node) == -1) return make_pair(vl(node), vl(node));

    auto resultl = dfs(lc(node));
    auto resultr = dfs(rc(node));
    resultl.first += vl(node);
    resultr.first += vl(node);

    return resultl.first > resultr.first ? (resultr) : (resultl.first == resultr.first && resultl.second > resultr.second) ? (resultr) : (resultl);
}

int Case = 1, t;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    string s1,s2;
    while(getline(cin,s1) && getline(cin,s2)){
        inorder.clear(); postorder.clear(); k = 0; 
        stringstream ss1(s1), ss2(s2);
        while(ss1 >> t) inorder.push_back(t);
        while(ss2 >> t) postorder.push_back(t);

        for(int i = 0;i < inorder.size();i++)
            mapping_in[inorder[i]] = i;

        int root = build(0, inorder.size(), 0, postorder.size());

        cout << dfs(root).second << endl;
        
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
