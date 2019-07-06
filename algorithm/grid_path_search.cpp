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

struct point {
    int x, y; 

    bool operator== (const point p){ return p.x == x && p.y == y; }
    point() { }
    point(int x,int y) : x(x), y(y){}
};

#define empty(p) (grids[p.y][p.x] == 0)
#define legal_pos(p) (0 <= p.x && p.x < size && 0 <= p.y && p.y < size)

point target;
const int size = 7;
int grids[size][size];


const int wx[] = {1,0,-1,0};
const int wy[] = {0,1,0,-1};

int dfs_counter(point p, int target, int set){
    if(!legal_pos(p)) return 0;
    if(grids[p.y][p.x] != target) return 0;

    grids[p.y][p.x] = set;
    int sum = 0;
    for(int i = 0;i < 4;i++){
        point next = p; next.x += wx[i]; next.y += wy[i];
        sum += dfs_counter(next,target,set);
    }
    return sum + 1;
}

int dfs(point p, int rest, int step){
    if(p == target && rest == 0) return 1;
    if(p == target && rest != 0) return 0;
    int counting = dfs_counter(target, 0,-1); dfs_counter(target, -1,0);
    if(counting != rest) return 0;

    int sum = 0; 
    for(int i = 0;i < 4;i++){
        point next = p; next.x += wx[i]; next.y += wy[i];
        if(empty(next) && legal_pos(next))
        {
            grids[next.y][next.x] = step;
            sum += dfs(next, rest-1, step + 1);
            grids[next.y][next.x] = 0;
        }
    }
    return sum;
}
int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();

    target = point(size-1,size-1);
    grids[0][0] = grids[1][0] = 1;
    cout << 2*dfs(point(0,1), size*size-2, 2) << endl;
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
