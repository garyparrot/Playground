#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    while(cin >> n){
        string p,t;
        cin.ignore();
        getline(cin, p);
        getline(cin, t);
        int lenp = p.length();
        int lent = t.length();
        
        vector<int> f(p.length(), 0);
        for(int i = 1, k = 0 ; i < lenp; i++){
            while(k && p[k] != p[i]) k = f[k - 1];
            if(p[k] == p[i]) ++k;
            f[i] = k;
        }
            
        // for(int i : f) cout << i << " "; cout << endl;

        bool found = false;
        for(int i = 0, k = 0 ; i < lent; i++){
            while(k && p[k] != t[i]) k = f[k - 1];
            if(p[k] == t[i]) ++k;
            if(k == lenp) { cout << (i - lenp + 1) << endl; found = true; k = f[k-1]; }
        }
        if(found) cout << endl;
    }
}
