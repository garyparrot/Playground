#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    long long t;
    while(t = a % b) a = b, b = t;
    return b;
}

int main(void){

    long long integer, fraction;
    while(cin >> integer && integer != 0){
        if(cin.get() == '.')
            cin >> fraction;
        else{
            cout << integer << "/1" << endl;
            continue;
        }

        long long top = fraction;
        long long bot = 1;
        for(int i = ceil(log10(top)); i; i--) bot *= 10;
        long long ggcd = gcd(top,bot);
        top /= ggcd;
        bot /= ggcd;
        top += bot * integer;

        cout << top << "/" << bot << endl;
    }

}
