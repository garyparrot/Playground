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
#define to_string_array(begin, end, title) (accumulate(begin, end-1, string(title), [](string str, const auto item) -> string { return str + to_string(item) + " "; }) + to_string(*(end-1)))
#define to_string_array2(begin, end) (accumulate(begin, end-1, string(""), [](string str, const auto item) -> string { return str + to_string(item) + " "; }) + to_string(*(end-1)))
#define string_array(begin, end) (accumulate(begin, end-1, string(""), [](string str, const auto item) -> string { return str + item + " "; }) + *(end-1))
using namespace std;

// Declaration {{{
void ONLINE_JUDEGE_SETTING(void);
int dprintf(const char *fmt, ...);
typedef long long ll;
// }}}

int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
    vector<string> default_constructor();
    vector<string> fill_constructor(10);
    vector<string> fill_constructor2(10,"Shit");
    int int_array[] = {1,3,5,7,9,2,4,6,8,10};
    vector<int> range_construtor(int_array, int_array + 10);
    vector<int> copy_constructor(range_construtor);

#define fori(s,t) for(auto iter = s;iter != t;iter++)

    // reverse iteration
    fori(range_construtor.rbegin(), range_construtor.rend()){ cout << *iter << endl; }
    // const iteration ( you can't modify the value )
    fori(range_construtor.cbegin(), range_construtor.cend()){ cout << *iter << endl; }
    // const reverse iteration 
    fori(range_construtor.crbegin(), range_construtor.crend()){ cout << *iter << endl; }

    // empty pop_back size
    while(!range_construtor.empty())
        range_construtor.pop_back();
    cout << range_construtor.size() << endl;

    // in-loop erase ( erase iterator in loop works )
    for(auto iter = copy_constructor.begin();iter != copy_constructor.end();iter++)
        if(*iter % 2 == 1)
            copy_constructor.erase(iter);
    fori(copy_constructor.begin(), copy_constructor.end()) { cout << *iter << endl; }



}

// Debugging & Online Judge {{{
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
    #endif
}
// }}}
