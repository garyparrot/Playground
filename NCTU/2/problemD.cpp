#include <bits/stdc++.h>
using namespace std;

int mat[305][305];
const int INF = 66666666;
int Case = 1;

int main(){
    int S,C,Q;
    while(cin >> S >> C >> Q && !(S==0&&C==0&&Q==0)){
        if(Case != 1) { cout << endl; }

        for(int i = 0;i < 305;i++) for(int j = 0;j < 305;j++) mat[i][j] = INF;
        for(int i = 0;i < 305;i++) mat[i][i] = 0;

        for(int i = 0;i < C;i++){
            int a,b,c; cin >> a >> b >> c;
            a--; b--;
            mat[a][b] = c;
            mat[b][a] = c;
        }

        for(int k = 0;k < S;k++)
            for(int i = 0;i < S;i++)
                for(int j = 0;j < S;j++)
                {
                    if(i == j || j == k || i == k) continue;
                    if(mat[i][j] > max(mat[i][k], mat[k][j])){
                        mat[i][j] = max(mat[i][k], mat[k][j]);
                    }
                }

        cout << "Case #" << Case++ << endl;
        while(Q--){
            int a,b; cin >> a >> b;
            a--; b--;
            if(mat[a][b] == INF)
                cout << "no path" << endl;
            else
                cout << mat[a][b] << endl;
        }
    }
}
