#include <bits/stdc++.h>

using namespace std;

struct BIT{
    int N;
    vector<int> vec;

    void add(int k, int x){
        while(k <= N)
            vec[k] += x, k += k & -k;
    }
    int query(int k){
        int sum = 0;
        while(k) 
            sum += vec[k], k -= k & -k;
        return sum;
    }
    int query(int l,int r){
        return query(r) - query(l-1);
    }

    BIT(int size){
        N = 1 << (int)ceil(log2(size));
        vec.resize(N + 1);
    }
};

int main(void){
    ios::sync_with_stdio(false);
    int n; cin >> n;

    BIT bit(n);

    for(int i = 1;i <= n;i++)
    {
        int a; cin >> a;
        bit.add(i, a);
    }

    string oper;
    while(getline(cin,oper)){
        stringstream ss(oper);
        ss >> oper;
        if(oper == "sum"){
            int r; ss >> r;
            cout << bit.query(r) << endl;
        }else if(oper == "update"){
            int a,b; ss >> a >> b;
            int val = b - bit.query(a,a);
            bit.add(a,val);
        }
    }

}
