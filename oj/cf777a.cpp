#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, x, num[3] = {0,1,2};
    cin >> n >> x;
    n %= 6;
    for(int i = 1; i <= n;i++)
    {
        if(i % 2)
            swap(num[0], num[1]);
        else
            swap(num[1], num[2]);
        // cout << num[0] << num[1] << num[2] << endl;
    }
    cout << num[x] << endl;
}
