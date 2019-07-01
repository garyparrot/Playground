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

int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    int q; cin >> q;
    while(q--){
        int n,m; cin >> n >> m;
        deque<int> que;

        int counter[10] = {0,0,0,0,0,0,0,0,0,0};
        for(int i = 0;i < n;i++){ int job; cin >> job;  counter[job]++; if(i == m) job = -job; que.push_back(job); }

        int step = 0;
        while(que.empty() == false){
            int front = (que.front());
            int level = abs(que.front()); 
            int is_target = que.front() < 0;
            bool is_lower_priority = any_of(counter + level + 1, counter + 10, [](const int& value) -> bool { return value > 0; });

            if(is_lower_priority){
                que.pop_front();
                que.push_back(front);
            }else{
                que.pop_front();
                counter[level]--;
                step += 1;

                if(is_target){
                    cout << step << endl;
                    break;
                }
            }
        }
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
