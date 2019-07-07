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

int mat[100][100];

int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int n,e;
    cin >> n >> e;

    const int INF = 6666666;
    
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) mat[i][j] = INF;
    for(int i = 0;i < n;i++) mat[i][i] = 0;
    for(int i = 0;i < e;i++){
        int a,b,c; cin >> a >> b >> c;
        mat[a][b] = c;
        mat[b][a] = c;
    }

    // Flody
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            for(int k = 0;k < n;k++)
                if(mat[j][k] > mat[j][i] + mat[i][k])
                    mat[j][k] = mat[j][i] + mat[i][k];

    int srcpoint;
    while(cin >> srcpoint){
        for(int i = 0;i < n;i++)
            cout << srcpoint << "->" << i << " = " << mat[srcpoint][i] << endl;
        cout << endl;
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
