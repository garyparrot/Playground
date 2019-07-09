#include <bits/stdc++.h>

using namespace std;

int main(void){
    long long n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;

        long long mxx = max(a,b) * max(a,b) - max(a,b) + 1;
        long long of1 = (max(a,b) % 2 == 1) ? 1 : -1;
        long long of2 = (max(a,b) % 2 == 1) ? -1:  1;
        mxx += abs(a - max(a,b)) * of1;
        mxx += abs(b - max(a,b)) * of2;

        cout << mxx << endl;
    }
}
