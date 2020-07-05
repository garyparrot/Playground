#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
#define int unsigned long long
        int a,b; cin >> a >> b;

        int based = max(a-1,b-1) * max(a-1,b-1) + 1;
        int length_of_level  = 1 + max(a-1,b-1) * 2;
        int beginning_position_x = max(a,b);
        int beginning_position_y = 1;
        int offset = (b - beginning_position_x) + (a - beginning_position_y);

        if(max(a,b) % 2)
            offset = length_of_level - offset - 1;

        cout << based + offset << endl;
    }
}
