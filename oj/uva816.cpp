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

int getDir(char c){ return c == 'N' ? 0 : c == 'E' ? 1 : c == 'S' ? 2 : c == 'W' ? 3 : -66666; }
struct player { int x, y, dir; };
struct point  { int x, y; };
struct rule   { int x, y; string rule; };

vector<rule> rules;
point pt;
player record[15][15][4];

bool recorded(player p) { return record[p.y][p.x][p.dir].x != -1; }
player get_prev(player p) { return record[p.y][p.x][p.dir]; }
void write_record(player dst, player src) { record[dst.y][dst.x][dst.dir] = src; }

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    string map_name;
    while((cin >> map_name) && map_name != "END"){
        rules.clear();
        memset(record, -1, sizeof(record));
        player p; char c; 
        cin >> p.y >> p.x >> c; p.dir = getDir(c);
        assert(p.dir != -66666);
        cin >> pt.y >> pt.x; 

        string str;
        while(getline(cin,str) && str != "0"){
            rule r;
            stringstream ss(str);
            ss >> r.y >> r.x;
#define showrule(r) dprintf("Rule %d,%d for %s\n", r.y, r.x, r.rule.c_str())
            while(ss >> r.rule && r.rule != "*")
            {
                rules.push_back(r);
                // showrule(r);
            }
        }

        typedef pair<player,player> state;
        int wx[] = {0,1,0,-1};
        int wy[] = {-1,0,1,0};
        player pgogo = p;
        player ff;
        pgogo.x += wx[p.dir];
        pgogo.y += wy[p.dir];
        deque<state> que {make_pair(p,pgogo)};
        bool found = false;
        while(!que.empty()){
            state s = que.front(); que.pop_front(); 
            player& src = s.first;
            player& dst = s.second;
            dprintf("Get state %d %d\n", dst.y, dst.x);
            if(recorded(dst)) { continue;}
            write_record(dst, src);
            if(dst.x == pt.x && dst.y == pt.y){ ff = dst; found = true; break; }

#define stand_same(r,p) (r.x == p.x && r.y == p.y)
#define look_same(r,p) (p.dir == getDir(r.rule[0]))
            for(rule r : rules){
                if(stand_same(r,dst) && look_same(r,dst)){
                    for(int i = 1; i < r.rule.length();i++){
                        player news = dst;
                        switch(r.rule[i]){
                            case 'F': break;
                            case 'L': news.dir = (news.dir + 4 - 1) % 4; break;
                            case 'R': news.dir = (news.dir + 1) % 4; break;
                        }
                        news.x += wx[news.dir];
                        news.y += wy[news.dir];
                        que.push_back(make_pair(dst, news));
                        dprintf("Go to %d,%d from %d,%d\n", news.y, news.x, dst.y, dst.x);
                    }
                }
            }
        }

        cout << map_name << endl << " ";
        if(found){
            vector<player> step;
            player last;
            do{
                step.push_back(ff);
                last = ff;
                ff = get_prev(ff);
#define equal(a,b) (a.x == b.x && a.y == b.y && a.dir == b.dir)
            }while(!(equal(last,pgogo) && equal(ff, p)));
            step.push_back(p);

            int counter = 0;
            for(auto iter = step.rbegin(); iter != step.rend(); iter++, counter++){
                cout << (counter != 0 && counter % 10 == 0 ? "\n  ": " ") ;
                cout << "(" << (*iter).y << "," << (*iter).x << ")"; 
            }
        }else{
            cout << " No Solution Possible";
        }
        Case++;
        if(Case > 1) cout << endl;
        
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
