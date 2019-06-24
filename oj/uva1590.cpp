#include <bits/stdc++.h>
#define ip_merge(i1,i2,i3,i4) (i1 << 24 | i2 << 16 | i3 << 8 | i4)
#define ip_part(ip, part) ((ip >> (8 * part)) & 0xff)

using namespace std;

int main(int argc, const char* args[]){
    ios::sync_with_stdio(false);
    
    int m;
    while(cin >> m){

        int rip = 0xffffffff, nip = 0xffffffff, p1,p2,p3,p4;

        for(int i = 0;i < m;i++){
            cin >> p1; cin.ignore(1); cin >> p2; cin.ignore(1); cin >> p3; cin.ignore(1); cin >> p4;
            rip &=  ip_merge(p1,p2,p3,p4);   // rip = the bit 1 that is always equal from first ip to last ip
            nip &= ~ip_merge(p1,p2,p3,p4);   // nip = the bit 0 that is always equal from first ip to last ip
        }

        int mask = rip | nip;                // for this moment, mask is the bit 1 or 0 that is always equal from first ip to last ip
        for(int i = 31; i>=0;i--)
            if((mask & (1 << i)) >> i ==  0){   // find the biggest zero in the mask, make every bit behind it to zero. Now it is a really mask
                mask = mask >> i;
                mask = mask << i;
                break;
            }   

        int domain = ip_merge(p1,p2,p3,p4) & mask;

        cout << ip_part(domain,3) << "." << ip_part(domain,2) << "." << ip_part(domain,1) << "." << ip_part(domain,0) << endl;
        cout << ip_part(mask,3) << "." << ip_part(mask,2) << "." << ip_part(mask,1) << "." << ip_part(mask,0) << endl;
    }
}
