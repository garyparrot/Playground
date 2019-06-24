#include <bits/stdc++.h>
#define MAX_INT std::numeric_limits<int>::max()
#define MAX_INT64 std::numeric_limits<int>::max()
#define ESP 1e-6

using namespace std;

int main(int argc, const char* args[]){
    ios::sync_with_stdio(false);
    
    int m;
    while(cin >> m){
        int r1,r2,r3,r4,n1,n2,n3,n4,p1,p2,p3,p4;
        // r1,r2,r3,r4 stands for the bits that is equal to 1 from first IP to last IP.
        // n1,n2,n3,n4 stands for the bits that is equal to 0 from first IP to last IP.
        // r1,r2,r3,r4 是 從第1個到最後個IP 都為 1 bit
        // n1,n2,n3,n4 是 從第1個到最後個IP 都為 0 bit
        r1=r2=r3=r4=n1=n2=n3=n4= 255;
        for(int i = 0;i < m;i++){
            cin >> p1; cin.ignore(1); cin >> p2; cin.ignore(1); cin >> p3; cin.ignore(1); cin >> p4;
            r1 &= p1;
            r2 &= p2;
            r3 &= p3;
            r4 &= p4;
            n1 &= ~p1;
            n2 &= ~p2;
            n3 &= ~p3;
            n4 &= ~p4;
        }

        // m1,m2,m3,m4 stands for the bits that is equal from first IP to last IP.
        // m1,m2,m3,m4 是 從第1個到最後個IP 都相同的 bit
        int m1,m2,m3,m4;
        m1 = r1 | n1;
        m2 = r2 | n2;
        m3 = r3 | n3;
        m4 = r4 | n4;
        // 找到最大的 0, 把他後面從成全部是0
        int merge = m1 << 24 | m2 << 16 | m3 << 8 | m4;
        for(int i = 31; i>=0;i--)
            if((merge & (1 << i)) >> i ==  0){
                merge = merge >> i;
                merge = merge << i;
            }

        m1 = (merge >> 24) & 255;
        m2 = (merge >> 16) & 255;
        m3 = (merge >> 8) & 255;
        m4 = (merge) & 255;
        int a1,a2,a3,a4;
        a1 = p1 & m1;
        a2 = p2 & m2;
        a3 = p3 & m3;
        a4 = p4 & m4;

        cout << a1 << "." << a2 << "." << a3 << "." << a4 << endl;
        cout << m1 << "." << m2 << "." << m3 << "." << m4 << endl;
    }
}
