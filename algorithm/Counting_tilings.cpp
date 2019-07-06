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

map<pair<int,string>, int> dp;
int n,m;

char ccc[] = {'^','v','<','>'};

struct counter4{
    int digit;
    int maxi;
    int state;
    bool next(){
        if(maxi <= state) return false;
        state++;
        return true;
    }
    int operator[](int index){
        int s = state;
        while(index--) s /= 4;

        return s % 4;
    }
    counter4(int d){
        maxi = 1;
        state = 0;
        digit = d;
        while(digit--) maxi *= 4;
    }
};

#define valid_top_combination(s) (s.find('v') == string::npos)
#define valid_bot_combination(s) (s.find('^') == string::npos)
int f(int k, string s){
    if(s[0] == '>' || s[m-1] == '<')
        return 0;
    for(int i = 0;i < m;i++)
        if(s[i] == '<' && s[i+1] != '>' || s[i] == '>' && s[i-1] != '<')
            return 0;
    if(k == 1){
        if(valid_top_combination(s)) dprintf("1 f(%d, %s)\n", k, s.c_str());
        return valid_top_combination(s);
    }
    if(k == n && !valid_bot_combination(s))
        return 0;
    if(dp.find(make_pair(k,s)) != dp.end())
    {
        dprintf("2 f(%d, %s) = %d\n", k, s.c_str(), dp[make_pair(k,s)]);
        return dp[make_pair(k,s)];
    }
    
    counter4 counter(m);
    int sum = 0;
    do{
        string news = string(4, ' ');
        for(int i = 0;i < m;i++)
            news[i] = ccc[counter[i]];

        bool shit = false;
        for(int i = 0;i < m;i++){
            if(s[i] == 'v')
                if(news[i] != '^')
                    shit = true;
            if(news[i] == '^')
                if(s[i] != 'v')
                    shit = true;
        }
        if(shit) continue;
        sum += f(k-1, news);
    }while(counter.next());

    dp[make_pair(k,s)] = sum;
    dprintf("3 f(%d, %s) = %d\n", k, s.c_str(), sum);
    return sum;
}

int Case = 1;
int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    while(cin >> n >> m){
        if(n < m) { int t = n; n = m; m = t; }
        dp.clear();

        counter4 counter(m);
        int sum = 0;
        do{
            string perm = string(4,' ');
            for(int i = 0;i < m;i++)
                perm[i] = ccc[counter[i]];
            int r = f(n, perm);
            dprintf("Generate State %s = %d\n", perm.c_str(),r);
            sum += r;
        }while(counter.next());

        cout << sum << endl;
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
