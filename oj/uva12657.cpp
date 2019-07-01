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

int rev = 0;
int link[100005][2];
int cmd_y_offset[] = {0,-1,1,0};

int& lt_of(int index) { return link[index][rev + 0]; }
int& rt_of(int index) { return link[index][1 - rev]; }
// 讓 index_node 從 list 抽離
void detach_node(int index){
    rt_of(lt_of(index)) = rt_of(index);
    lt_of(rt_of(index)) = lt_of(index);
    rt_of(index) = -1;
    lt_of(index) = -1;
}
//讓 target_node 搶走 index_node 的連接關係
void hijack_node(int index, int target){
    rt_of(lt_of(index)) = target;
    lt_of(rt_of(index)) = target;
    rt_of(target) = rt_of(index);
    lt_of(target) = lt_of(index);
    rt_of(index) = -1;
    lt_of(index) = -1;
}

int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int n,m, Case = 1; 
    while(cin >> n >> m){
        rev = 0;
        for(int i = 1;i <= n;i++){
            link[i][0] = i - 1;
            link[i][1] = i + 1;
        }
        link[0][0] = n;
        link[0][1] = 1;
        link[n][1] = 0;

        for(int i = 0;i < m;i++){
            int cmd, x, y, t; cin >> cmd;
            if(cmd == 4)
                rev = 1 - rev;
            else if(cmd == 1){
                cin >> x >> y;
                detach_node(x);
                rt_of(lt_of(y)) = x;
                lt_of(x) = lt_of(y);
                rt_of(x) = y;
                lt_of(y) = x;
            }else if(cmd == 2){
                cin >> x >> y;
                detach_node(x);
                lt_of(rt_of(y)) = x;
                rt_of(x) = rt_of(y);
                lt_of(x) = y;
                rt_of(y) = x;
            }else if(cmd == 3){
                cin >> x >> y;
                hijack_node(x,n+1);
                hijack_node(y,n+2);
                hijack_node(n+1,y);
                hijack_node(n+2,x);
            }
        }


        long long sum = 0;
        for(int s = rt_of(0), counter = 1; s != 0; s = rt_of(s), counter++)
            sum += s * (counter % 2);
        cout << "Case " << Case++ << ": " << sum << endl;
    }
}

// {{{ Debugging & Online Judge
int dprintf(const char *fmt, ...){
    #ifdef ONLINE_JUDGE
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
