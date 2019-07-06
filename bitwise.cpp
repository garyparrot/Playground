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

int reverseBit(int value){
    int rev = 0;
    for(int i = 0;i < 32;i++)
        rev = (rev << 1) | ((value >> i) & 0x1);
    return rev;
}

int main(int argc, const char* args[]){
    ONLINE_JUDEGE_SETTING();
#define set_bit(x,i)                 ( x |  (1 << i) )
#define reset_bit(x,i)               ( x & ~(1 << i) )
#define invert_bit(x,i)              ( x ^  (1 << i) )
#define reset_First1(x,i)            ( x &  (x - 1)  )
#define first_1(x,i)                 ( x &  -x       ) 

    // dirty trick for print 32 binary value
#define pb8 "%d%d%d%d%d%d%d%d"
#define pb16 pb8 pb8
#define pb32 pb16 pb16
#define get1(x) ((x) & 1)
#define get2(x) get1(x >> 1), get1(x)
#define get4(x) get2(x >> 2), get2(x)
#define get8(x) get4(x >> 4), get4(x)
#define get16(x) get8(x >> 8), get8(x)
#define get32(x) get16(x >> 16), get16(x)
    
    printf("The binary of %d is " pb32 "\n", 666, get32(666));
    printf("Rev binary of %d is " pb32 "\n", 666, get32(reverseBit(666)));

#define set_intersectoin(a,b)        ((a)&(b))
#define set_union(a,b)               ((a)|(b))
#define set_complement(a)            (~(a))
#define difference(a,b)              ((a) & ~(b))

    // 遞代每個x的子集合(把 (b-x) 看成 (b + ~x + 1) 比較好懂)
    int x = 1 << 3 | 1 << 5 | 1 << 8;
    int b = 0;
    printf("set x =" pb32 "\n", get32(x));
    do{
        // process subset b
        printf("subset " pb32 "\n", get32(b));
    } while(b = (b-x) & x);
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
