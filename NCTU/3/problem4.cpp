#include <bits/stdc++.h>
using namespace std;

int main(void){
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        vector<pair<int,int>> vec(n);
#define x first
#define y second
        for(int i = 0;i < n;i++)
            cin >> vec[i].x >> vec[i].y;

#define pow2(x) ((x)*(x))
#define dist(p0,p1) (pow2(p0.x - p1.x) + pow2(p0.y - p1.y))
        int counter  = 0;
        for(int i = 0;i < n;i++)
            for(int j = i + 1;j < n;j++)
                for(int k = j + 1; k < n;k++)
                    if(dist(vec[i], vec[j]) == dist(vec[i], vec[k]))
                        counter++;

        cout << counter << endl;

    }
}
