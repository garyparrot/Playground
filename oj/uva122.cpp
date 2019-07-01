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

int k = 0;
int node[300][3];

int spawn_node() { return k++; }

int& lt_of(int index)    { return node[index][0]; }
int& rt_of(int index)    { return node[index][1]; }
int& value_of(int index) { return node[index][2]; }

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    stringstream ss;
    string str;
    while(getline(cin, str, '\n')) ss << " " << str;

    while(true){
        k = 0;
        memset(node, -1, sizeof(node));
        int root = spawn_node();
        while(true){
            if(!(ss >> str)) goto STOPPPPPPPPPPPP;
            int bl = str.find('(');
            int br = str.find(')');
            int ca = str.find(',');
            if(ca == string::npos) break;
            int value = stoi(str.substr(bl + 1, ca - bl - 1));
            string path = str.substr(ca + 1, br - ca - 1);

            int walk = root;
            for(char p : path){
                if(p == 'L'){
                    if(lt_of(walk) == -1) lt_of(walk) = spawn_node();
                    walk = lt_of(walk);
                }else{
                    if(rt_of(walk) == -1) rt_of(walk) = spawn_node();
                    walk = rt_of(walk);
                }
            }
            if(value_of(walk) == -1)
                value_of(walk) = value;
            else
                value_of(walk) = -1;
        }

        // BFS this shit
        vector<int> seq;
        deque<int> que{root};

        bool legal = true;
        while(!que.empty()){
            int node = que.front(); que.pop_front();
            if(value_of(node) < 0) { legal = false; break; }
            seq.push_back(value_of(node));
            if(lt_of(node) >= 0) que.push_back(lt_of(node));
            if(rt_of(node) >= 0) que.push_back(rt_of(node));
        }

        bool fuck_uva_online_judge_what_is_wrong_with_your_siliy_problems_presentation_error_kiss_my_as = true;
        if(legal)
            for_each(seq.begin(), seq.end(), [&](const int& value) -> void { 
                cout << (fuck_uva_online_judge_what_is_wrong_with_your_siliy_problems_presentation_error_kiss_my_as ? "" : " ") << value; 
                fuck_uva_online_judge_what_is_wrong_with_your_siliy_problems_presentation_error_kiss_my_as = false;
            }), cout << endl;
        else
            cout << "not complete" << endl;
    }
    STOPPPPPPPPPPPP:
    return 0;
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
