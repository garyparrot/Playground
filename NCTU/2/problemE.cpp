#include <bits/stdc++.h>
using namespace std;

struct segment_tree{
    int N;
    vector<int> vec;

    void update(int k, int x){
        k += N; vec[k] += x;

        for(k /=2 ; k ; k/=2)
            vec[k] = min(vec[k*2], vec[k*2+1]);
    }

    int query(int l,int r){
        l += N; r += N;

        int s = 66666666;
        while(l <= r){
            if(l % 2 == 1) s = min(s, vec[l++]);
            if(l % 2 == 0) s = min(s, vec[r--]);
            l /=2; r /=2;
        }

        return s;
    }

    segment_tree(int size){
        N = 1 << (int)ceil(log2(size));
        vec.resize(N << 1);
    }
};

int main(void){
    int n; cin >> n;
    segment_tree st(n);

    for(int i = 0;i < n;i++)
    {
        int t; cin >> t; st.update(i,t);
    }

    int l, r;
    while(cin >> l >> r){
        l--; r--;
        cout << st.query(l,r) << endl;
    }
}
