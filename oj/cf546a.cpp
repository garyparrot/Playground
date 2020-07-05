#include <bits/stdc++.h>

using namespace std;

int main() {
    int k,w,n;
    cin >> k >> n >> w;
    long long total = ((1+w)*(w)/2) * k;
    cout << std::max(total-n,0ll)<< endl;
}
