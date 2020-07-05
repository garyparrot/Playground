#include <bits/stdc++.h>

using namespace std;

int Cases = 1;
int main() {
    const int INF = 666666;

    int S,C,Q;
    while(cin >> S >> C >> Q && !(S == 0 && C == 0 && Q == 0)){
        if(Cases != 1) cout << endl;
        cout << "Case #" << Cases++ << endl;
        vector<vector<int>> matrix (S, vector<int>(S, INF));

        for(int i = 0; i < C; i++){
            int a,b,c; cin >> a >> b >> c;
            a--, b--;
            matrix[a][b] = c;
            matrix[b][a] = c;
        }

        // Floyd
        for(int i = 0;i < S;i++)
        for(int j = 0;j < S;j++)
        for(int k = 0;k < S;k++)
            if(matrix[j][k] > max(matrix[j][i],matrix[i][k]))
                matrix[j][k] = max(matrix[j][i], matrix[i][k]);

        for(int i = 0;i < Q; i++) {
            int a,b; cin >> a >> b;
            a--, b--;
            if(matrix[a][b] >= INF) {
                cout << "no path" << endl;
            } else {
                cout << matrix[a][b] << endl;
            }
        }
    }


}
